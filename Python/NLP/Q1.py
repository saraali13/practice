import nltk
from nltk.corpus import gutenberg
from nltk.tokenize import word_tokenize, sent_tokenize

# Download the necessary data for tokenization and the gutenberg corpus
nltk.download("punkt")
nltk.download('gutenberg')

# Sample text for tokenization
text = "Hi, my name is Sara. What's your name?"

# Perform word and sentence tokenization
word_tokens = word_tokenize(text)
print(f"Word Tokenization: {word_tokens}")

sentence_tokens = sent_tokenize(text)
print(f"Sentence Tokenization: {sentence_tokens}")

#Output
#Word Tokenization: ['Hi', ',', 'my', 'name', 'is', 'Sara', '.', 'What', "'s", 'your', 'name', '?']
#Sentence Tokenization: ['Hi, my name is Sara.', "What's your name?"]
