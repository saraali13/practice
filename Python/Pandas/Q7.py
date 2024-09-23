import panda from pd


d1=pd.DataFrame({"a":["a1","a2","a3"],"b":["b1","b2","b3"]})
d2=pd.DataFrame({"c":["a1","a2","a3"],"d":["d1","b2","d3"]})

a=pd.merge(d1,d2) #same waly srf

