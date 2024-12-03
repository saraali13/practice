import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from collections import Counter
import numpy as np

# Download necessary NLTK data
nltk.download("punkt")
nltk.download("stopwords")
nltk.download("wordnet")
nltk.download("omw-1.4")

# Sample paragraph
Para = """This is the first document. This document is the second document. And this is the third one. Is this the first document?"""

# Tokenize and remove stop words
Sentence = nltk.sent_tokenize(Para)
stop_words = set(stopwords.words("english"))
processed_corpus = []

for sentence in Sentence:
    words = word_tokenize(sentence.lower())  # Tokenize the sentence into words
    filtered_words = [word for word in words if word.isalnum() and word not in stop_words]
    processed_corpus.append(filtered_words)

# Create a vocabulary (all unique words)
vocabulary = sorted(set(word for text in processed_corpus for word in text))

# Initialize Bag of Words matrix
bow_matrix = np.zeros((len(processed_corpus), len(vocabulary)), dtype=int)

# Populate the Bag of Words matrix
for i, text in enumerate(processed_corpus):
    word_counts = Counter(text)
    for j, word in enumerate(vocabulary):
        bow_matrix[i, j] = word_counts.get(word, 0)

# Display results
print("Vocabulary:\n", vocabulary)
print("\nBag of Words Matrix:\n", bow_matrix)
