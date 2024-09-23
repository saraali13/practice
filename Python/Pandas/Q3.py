import numpy as np
import pandas as pd

# Set the random seed for reproducibility
np.random.seed(101)

# Generate random integers between 0 and 100 in a 4x3 matrix
mydata = np.random.randint(0, 101, (4, 3))

# Define row and column labels
myindex = ["AZ", "EX", "WS", "NY"]
mycolumns = ["Jan", "Feb", "Mar"]

# Create a DataFrame using the generated data, with specified index and column names
df = pd.DataFrame(data=mydata, index=myindex, columns=mycolumns)

# Display the DataFrame
print(df)
