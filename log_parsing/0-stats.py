#!/usr/bin/python3
"""fonction"""

import sys

nombre200 = 0
nombre301 = 0
nombre400 = 0
nombre401 = 0
nombre403 = 0
nombre404 = 0
nombre405 = 0
nombre500 = 0
line_count = 0
taille = 0
for line in sys.stdin:
    line = line.strip()  # Supprime les espaces et retours à la ligne
    if not line:
        continue  # Ignore les lignes vides
    parts = line.strip().split()
    status_code = int(parts[-2])  # Avant-dernier élément
    file_size = int(parts[-1])  # Dernier élément
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

    line_count += 1
    if line_count % 10 == 0:
        taille += file_size
        print(f"File size: {taille}")
        print(f"200: {nombre200}\n301: {nombre301}\n400: {nombre400}\n"
              f"401: {nombre401}\n403: {nombre403}\n404: {nombre404}\n"
              f"405: {nombre405}\n500: {nombre500}")
