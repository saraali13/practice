ex={1:"a",2:"b",3:"c"}
for i,k in enumerate(ex):
  print(i,k) #print index and keys
for i,(k,j) in enumerate(ex.items()):
  print(i,k,j) #print index and keys and val
