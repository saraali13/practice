#the code is not correct
import nltk
import re
from nltk.stem import WordNetLemmatizer
from nltk.stem.porter import  PorterStemmer
from nltk.corpus import stopwords

Para = """This is the first document.This document is the second document.And this is the third one.Is this the first document?"""

#nltk.download("punkt")
#nltk.download("stopwords")
nltk.download("wordnet")
nltk.download("omw-1.4")

# Tokenize and remove stop words
port=PorterStemmer()
wordnet=WordNetLemmatizer()
Sentence=nltk.sent_tokenize(Para)
stop_words = set(stopwords.words("english"))
processed_corpus = []

for text in range(len(Sentence)):
    words = word_tokenize(text.lower())
    filtered_words = [word for word in words if word.isalnum() and word not in stop_words]
    processed_corpus.append(filtered_words)

# Create a vocabulary (all unique words)
vocabulary = sorted(set(word for text in processed_corpus for word in text))

# Initialize Bag of Words matrix
bow_matrix = np.zeros((len(corpus), len(vocabulary)), dtype=int)

# Populate the Bag of Words matrix
for i, text in enumerate(processed_corpus):
    word_counts = Counter(text)
    for j, word in enumerate(vocabulary):
        bow_matrix[i, j] = word_counts.get(word, 0)

# Display results
print("Vocabulary:\n", vocabulary)
print("\nBag of Words Matrix:\n", bow_matrix)
