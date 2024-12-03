from sklearn.feature_extraction.text import CountVectorizer

# Sample corpus (list of text documents)
corpus = [
    "This is the first document.",
    "This document is the second document.",
    "And this is the third one.",
    "Is this the first document?"
]

# Initialize CountVectorizer
vectorizer = CountVectorizer()

# Fit and transform the corpus
X = vectorizer.fit_transform(corpus)

# Vocabulary
print("Vocabulary:", vectorizer.vocabulary_)

# Document-Term Matrix
print("\nDocument-Term Matrix:\n", X.toarray())
