from collections import ChainMap

a = {1:’fast’, 2:’iba’}
b = {3:’landhi’,’johar’}
c = ChainMap(a,b)
print(c)
#ChainMap({1: 'fast', 2: 'iba'}, {3: 'landhi', 4: 'johar'})
