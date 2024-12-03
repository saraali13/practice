import nltk
import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer

# Download necessary NLTK data
nltk.download("punkt")
nltk.download("stopwords")
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

# Sample text paragraph
Para = """This is the first document. This document is the second document. And this is the third one. Is this the first document?"""

# Tokenization and punctuation removal
Sentence = nltk.sent_tokenize(Para)
stop_words = set(stopwords.words("english"))
processed_corpus = []

for sentence in Sentence:
    words = word_tokenize(sentence.lower())  # Tokenize the sentence into words
    # Remove punctuation and stop words
    filtered_words = [word for word in words if word.isalnum() and word not in stop_words]
    processed_corpus.append(' '.join(filtered_words))  # Join words back into a sentence

# Display the processed corpus
print("Processed Corpus:\n", processed_corpus)

# Count Vectorizer
count_vectorizer = CountVectorizer()
count_vector_matrix = count_vectorizer.fit_transform(processed_corpus)

# Display Count Vectorizer output as DataFrame
count_vector_df = pd.DataFrame(count_vector_matrix.toarray(), columns=count_vectorizer.get_feature_names_out())
print("\nCount Vectorizer Matrix:\n", count_vector_df)

# TF-IDF Vectorizer
tfidf_vectorizer = TfidfVectorizer()
tfidf_vector_matrix = tfidf_vectorizer.fit_transform(processed_corpus)

# Display TF-IDF Vectorizer output as DataFrame
tfidf_vector_df = pd.DataFrame(tfidf_vector_matrix.toarray(), columns=tfidf_vectorizer.get_feature_names_out())
print("\nTF-IDF Vectorizer Matrix:\n", tfidf_vector_df)
