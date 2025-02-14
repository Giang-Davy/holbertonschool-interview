#!/usr/bin/python3
"""
Ce script lit les lignes d'un log serveur et calcule des statistiques
sur les codes de statut HTTP (200, 301, etc.) et la taille totale des fichiers
servis. Après chaque 10 lignes, il affiche les statistiques.
"""

import sys

# Variables globales pour compter les statuts et accumuler la taille des fichiers
nombre200 = 0  # Compteur pour le statut code 200
nombre301 = 0  # Compteur pour le statut code 301
nombre400 = 0  # Compteur pour le statut code 400
nombre401 = 0  # Compteur pour le statut code 401
nombre403 = 0  # Compteur pour le statut code 403
nombre404 = 0  # Compteur pour le statut code 404
nombre405 = 0  # Compteur pour le statut code 405
nombre500 = 0  # Compteur pour le statut code 500
line_count = 0  # Compteur pour le nombre de lignes lues
taille = 0  # Taille totale des fichiers servies


def process_log_line(line):
    """
    Prend une ligne de log sous forme de chaîne, l'analyse et met à jour les
    compteurs des statuts HTTP et de la taille des fichiers.
    
    Args:
        line (str): La ligne de log à analyser.
    
    Returns:
        tuple: Contient la mise à jour des compteurs des statuts et de la taille des fichiers.
    """
    line = line.strip()  # Supprime les espaces et retours à la ligne
    if not line:
        return None, None

    parts = line.strip().split()

    # Vérifie que la ligne a un format valide
    if len(parts) < 9:
        return None, None

    status_code = int(parts[-2])  # Avant-dernier élément : le statut code
    file_size = int(parts[-1])    # Dernier élément : la taille du fichier

    return status_code, file_size


def display_statistics():
    """
    Affiche les statistiques de la taille totale et des codes de statut HTTP
    après chaque 10 lignes.
    """
    print(f"File size: {taille}")  # Affiche la taille totale
    print(f"200: {nombre200}\n301: {nombre301}\n400: {nombre400}\n"
          f"401: {nombre401}\n403: {nombre403}\n404: {nombre404}\n"
          f"405: {nombre405}\n500: {nombre500}")


# Traitement ligne par ligne
for line in sys.stdin:
    status_code, file_size = process_log_line(line)

    if status_code is None:
        continue  # Ignore les lignes mal formées ou vides

    # Mise à jour des compteurs des statuts
    if status_code == 200:
        nombre200 += 1
    elif status_code == 301:
        nombre301 += 1
    elif status_code == 400:
        nombre400 += 1
    elif status_code == 401:
        nombre401 += 1
    elif status_code == 403:
        nombre403 += 1
    elif status_code == 404:
        nombre404 += 1
    elif status_code == 405:
        nombre405 += 1
    elif status_code == 500:
        nombre500 += 1

    # Ajout de la taille et affichage des statistiques après 10 lignes
    line_count += 1
    if line_count % 10 == 0:
        taille += file_size  # Ajoute la taille du fichier à la taille totale
        display_statistics()
