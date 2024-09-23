import pandas as pd


# Create a DataFrame using the generated data, with specified index and column names
df = pd.read_csv("file.csv")

df.index #strt stop step
df.set_index("payment ID")#ID 1 is row 1 ID2 row 2 and so on
df.reset_index()
df.iloc[0] #grabs a single row name can also be pased in loc
df.iloc[0:4] #multiple rows

