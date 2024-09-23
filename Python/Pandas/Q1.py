import pandas as pd

myindex=["USA","Canada","Mexico"]
mydata=[123,345,679]
myuser=pd.Series(data=mydata, index=myindex)
print (myuser)

ages={"Sara":18,"Ali":20, "Abbas":22}
pd.Series(ages)
