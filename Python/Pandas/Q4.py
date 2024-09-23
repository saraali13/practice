import numpy as np
import pandas as pd

myindex = ["AZ", "EX", "WS", "NY"]
mycolumns = ["Jan", "Feb", "Mar"]

# Create a DataFrame using the generated data, with specified index and column names
df = pd.read_csv("file.csv")
df.columns #names of all the col
df.index # start stop and step
df.head(3)#1st 3 rows with all col
df.tail(3)#last 3 rows with all col
df.info()
len(df)
df.descibe()
# count, mean, min, max, 25,50,75 % of each col

#grabbing a col
df["Jan"]
df["Jan","Feb"]

# create a new col
df["Apr"]="xyz"

#drop col
df=df.drop("Feb",axis=1)

# Display the DataFrame
print(df)
