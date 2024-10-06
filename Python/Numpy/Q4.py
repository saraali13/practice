import numpy as np

def myadd(x, y):
  return x+y
  
myadd = np.frompyfunc(myadd, 2, 1)# 2 input 1 output
print(myadd([1, 2, 3, 4], [5, 6, 7, 8]))
# [6 8 10 12]

a = np.array([34, 67, 89, 15, 33, 27])
 
string_generator = np.frompyfunc(str, 1, 1) # 1 input and 1 output
