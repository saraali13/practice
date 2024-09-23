import panda from pd
d1={"a":["a1","a2","a3"],"b":["b1","b2","b3"]}
d2={"c":["c1","c2","c3"],"d":["d1","d2","d3"]}
a=pd.DataFrame(d1)
b=pd.DataFrame(d2)
ax0=pd.concat([a,b],axis=0)
#a b c d col or 0-3 then 0-3 row total 6 rows
ax1=pd.concat([a,b],axis=1)
#a b c d col or 0-3 rows only
a.columns=b.columns # a b col and 6 row containg all data of a b c d
pd.concat([a,b])
