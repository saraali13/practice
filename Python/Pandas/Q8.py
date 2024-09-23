df= pd.read_csv("file.cvs")
df.isnull()#returns true or false
df.dropna()#removes the row with na
df.fillna("new")# Null vale == new sb jaga
bool_series=df["total_bill"]>30
df[bool_series]
bool_series=df[(df["total_bill"]>30)&(df["size"]>7)]
