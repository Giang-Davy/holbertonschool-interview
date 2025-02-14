#!/usr/bin/python3
"""Code pour lire des lignes et compter les codes de statut HTTP."""


import sys


# Module de comptage des codes de statut
def count_status_codes(line, status_codes):
    """Compte les occurrences des différents codes de statut."""
    parts = line.strip().split()
    status_code = int(parts[-2])  # Avant-dernier élément
    file_size = int(parts[-1])  # Dernier élément

    if status_code in status_codes:
        status_codes[status_code] += 1
    
    return status_codes, file_size

# Module d'affichage des résultats
def display_results(status_codes, total_size):
    """Affiche les résultats du comptage des codes de statut."""
    print(f"File size: {total_size}")
    print(f"200: {status_codes.get(200, 0)}\n"
          f"301: {status_codes.get(301, 0)}\n"
          f"400: {status_codes.get(400, 0)}\n"
          f"401: {status_codes.get(401, 0)}\n"
          f"403: {status_codes.get(403, 0)}\n"
          f"404: {status_codes.get(404, 0)}\n"
          f"405: {status_codes.get(405, 0)}\n"
          f"500: {status_codes.get(500, 0)}")

# Code principal
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0
total_size = 0

for line in sys.stdin:
    line = line.strip()  # Supprime les espaces et retours à la ligne
    if not line:
        continue  # Ignore les lignes vides

    # Compte les codes de statut et la taille du fichier
    status_codes, file_size = count_status_codes(line, status_codes)
    
    # Mise à jour de la taille totale
    total_size += file_size
    line_count += 1

    # Affiche les résultats tous les 10 lignes lues
    if line_count % 10 == 0:
        display_results(status_codes, total_size)
