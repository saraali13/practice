import pandas as pd

ages1={"Sara":18,"Ali":20, "Abbas":22}
ages2={"Sara":19, "Ali":19, "Haider":23}
a1=pd.Series(ages1)
a2=pd.Series(ages2)
a1+a2 #will show NAN infront of abbas and haider (coz they are uncommon)
a1.add(a2,fill_value=0)# will show the ages of haider and abbas as well
