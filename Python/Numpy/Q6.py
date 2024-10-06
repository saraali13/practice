import numpy as np
from numpy import random

#distributions
x = random.normal(loc=1, scale=2, size=(2, 3))
x = random.binomial(n=10, p=0.5, size=10)
x = random.poisson(lam=2, size=10)
x = random.uniform(size=(2, 3))
x = random.logistic(loc=1, scale=2, size=(2, 3))
