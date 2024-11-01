#Stop words
import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

#nltk.download("punkt") already downloaded
nltk.download("stopwords")

text="Hi, My name is Sara Ali. I am 19 years old. It felt nice meeting you"
word_tk=word_tokenize(text)

stop_words=set(stopwords.words("english"))

fil_words=[word for word in word_tk if word.lower() not in stop_words]
print(f"Original words: {word_tk}\nAfter removing stop words: {fil_words}")

#Output
#Original words: ['Hi', ',', 'My', 'name', 'is', 'Sara', 'Ali', '.', 'I', 'am', '19', 'years', 'old', '.', 'It', 'felt', 'nice', 'meeting', 'you']
#After removing stop words: ['Hi', ',', 'name', 'Sara', 'Ali', '.', '19', 'years', 'old', '.', 'felt', 'nice', 'meeting']

