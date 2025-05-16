#!/usr/bin/env python3


import requests
import re


def count_words(subreddit, word_list, counts=None, after=None):
	if counts is None:
		counts = {}

	url = f"https://www.reddit.com/r/{subreddit}/hot.json"
	headers = {'User-Agent': 'MyBot/0.0.1'}
	params = {'after': after}
	response = requests.get(url, headers=headers, params=params, allow_redirects=False)

	if response.status_code != 200:
		return

	data = response.json()
	children = data.get('data', {}).get('children', [])

	# Normaliser word_list
	normalized_words = [word.lower() for word in word_list]

	for post in children:
		title = post.get('data', {}).get('title', '').lower()
		words = re.findall(r'\b\w+\b', title)

		for word in normalized_words:
			count = words.count(word)
			if count > 0:
				if word in counts:
					counts[word] += count
				else:
					counts[word] = count

	# Récursion
	after = data.get('data', {}).get('after')
	if after:
		return count_words(subreddit, word_list, counts, after)

	# Fusionner les doublons de word_list
	final_counts = {}
	for word in normalized_words:
		if word in counts:
			if word in final_counts:
				final_counts[word] += counts[word]
			else:
				final_counts[word] = counts[word]

	# Tri
	sorted_words = sorted(final_counts.items(), key=lambda x: (-x[1], x[0]))

	# Affichage
	for word, count in sorted_words:
		if count > 0:
			print(f"{word}: {count}")
