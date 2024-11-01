import nltk
from nltk.stem import PorterStemmer
from nltk.stem import WordNetLemmatizer

nltk.download("wordnet")
stemmer = PorterStemmer()
lemmatizer = WordNetLemmatizer()

word_list = ["Jump", "Jumping", "Jumped", "Run", "Running", "Easily", "Tasty"]

# Apply stemming to each word in the list
st_words = [stemmer.stem(word) for word in word_list]
print(f"Original word list: {word_list}\nStemmed Word list: {st_words}\n")

# Apply lemmatization (converting words to lowercase as it works effectively on lower cases)
lem_words = [lemmatizer.lemmatize(word.lower()) for word in word_list]
print(f"Lemmatized Word list: {lem_words}")

lem_words_verb = [lemmatizer.lemmatize(word.lower(), pos='v') for word in word_list]
print(f"Lemmatized verb Word list: {lem_words_verb}")

#Output
#Original word list: ['Jump', 'Jumping', 'Jumped', 'Run', 'Running', 'Easily', 'Tasty']
#Stemmed Word list: ['jump', 'jump', 'jump', 'run', 'run', 'easili', 'tasti']
#Lemmatized Word list: ['jump', 'jumping', 'jumped', 'run', 'running', 'easily', 'tasty']
#Lemmatized verb Word list: ['jump', 'jump', 'jump', 'run', 'run', 'easily', 'tasty']

