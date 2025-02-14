#!/usr/bin/python3
"""Ce script lit les lignes d'un log serveur et calcule des statistiques
sur les codes de statut HTTP (200, 301, etc.) et la taille totale des fichiers
servis. Après chaque 10 lignes, il affiche les statistiques.
"""

import sys

# Compteurs pour les codes de statut HTTP
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

# Traitement ligne par ligne
for line in sys.stdin:
    # La ligne est lue depuis l'entrée standard, en supprimant les espaces et retours à la ligne
    line = line.strip()
    
    # Si la ligne est vide, elle est ignorée
    if not line:
        continue
    
    # Divise la ligne en éléments séparés par des espaces
    parts = line.strip().split()

    # Vérifie que la ligne a un format valide
    if len(parts) < 9:
        continue  # Si la ligne ne contient pas suffisamment d'éléments, elle est ignorée

    # Extrait le statut code et la taille du fichier
    status_code = int(parts[-2])  # Avant-dernier élément : le statut code
    file_size = int(parts[-1])    # Dernier élément : la taille du fichier

    # Comptabilise les occurrences de chaque code de statut
    if status_code == 200:
        nombre200 += 1
    if status_code == 301:
        nombre301 += 1
    if status_code == 400:
        nombre400 += 1
    if status_code == 401:
        nombre401 += 1
    if status_code == 403:
        nombre403 += 1
    if status_code == 404:
        nombre404 += 1
    if status_code == 405:
        nombre405 += 1
    if status_code == 500:
        nombre500 += 1

    # Incrémente le compteur de lignes et affiche les résultats après 10 lignes
    line_count += 1
    if line_count % 10 == 0:
        taille += file_size  # Ajoute la taille du fichier à la taille totale
        print(f"File size: {taille}")  # Affiche la taille totale
        print(f"200: {nombre200}\n301: {nombre301}\n400: {nombre400}\n"
              f"401: {nombre401}\n403: {nombre403}\n404: {nombre404}\n"
              f"405: {nombre405}\n500: {nombre500}")
