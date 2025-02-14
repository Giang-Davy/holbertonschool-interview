#!/usr/bin/python3
"""
Script qui lit des logs depuis l'entrée standard (stdin)
et affiche des statistiques :
- Taille totale des fichiers
- Nombre de lignes par code HTTP valide
Les statistiques sont affichées toutes les 10 lignes ou
lors d'une interruption clavier (CTRL+C).
"""

import sys

# Initialisation des variables
filesize, count = 0, 0
codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
stats = {k: 0 for k in codes}


def print_stats(stats: dict, file_size: int) -> None:
    """Affiche les statistiques sous forme triée"""
    print("File size: {:d}".format(file_size))
    for k, v in sorted(stats.items()):
        if v:
            print("{}: {}".format(k, v))


def parse_line(line: str) -> None:
    """Analyse chaque ligne et met à jour les statistiques"""
    global filesize
    data = line.split()
    try:
        status_code = data[-2]
        if status_code in stats:
            stats[status_code] += 1
    except IndexError:
        pass  # En cas de ligne malformée

    try:
        filesize += int(data[-1])
    except (IndexError, ValueError):
        pass  # Ignore les erreurs liées à l'absence de taille


# Lecture des lignes depuis stdin
try:
    for line in sys.stdin:
        count += 1
        parse_line(line)
        if count % 10 == 0:
            print_stats(stats, filesize)
    print_stats(stats, filesize)
except KeyboardInterrupt:
    print_stats(stats, filesize)
    raise
