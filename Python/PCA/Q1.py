# Import Libraries
from operator import index

from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler,LabelEncoder
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import seaborn as sns

# Load Dataset
df=pd.read_csv("Iris.csv")
x = df.iloc[:, :-1].values  # Features (numerical)
y = df.iloc[:, -1].values
scalr=StandardScaler()
x_scaled=scalr.fit_transform(x)
# Encode labels to numerical values
label_encoder = LabelEncoder()
y_encoded = label_encoder.fit_transform(y)

# Apply PCA
pca = PCA(n_components=2)  # Reduce to 2 principal components
principle_components = pca.fit_transform(x_scaled)

# Explained Variance
print("Explained Variance Ratio:", pca.explained_variance_ratio_)
print("Total Variance Explained:", sum(pca.explained_variance_ratio_))

# Plotting PCA
plt.figure()
scatter = plt.scatter(principle_components[:, 0], principle_components[:, 1], c=y_encoded, cmap='viridis', s=30)
plt.title("PCA: Dimensionality Reduction to 2 Components")
plt.xlabel("Principal Component 1")
plt.ylabel("Principal Component 2")
plt.colorbar(scatter, label="Classes")
plt.show()

print(f"No of components: {pca.n_components}\nComponents: {pca.components_}")

df_comp=pd.DataFrame(pca.components_,index=["PC1","PC2"],columns=df.columns[:-1])

plt.figure()
sns.heatmap(df_comp,annot=True)
plt.show()

explained_variance=[]
for i in range(1,6):
    pca1=PCA(n_components=i)
    pca1.fit(x_scaled)
    explained_variance.append(np.sum(pca.explained_variance_ratio_))

plt.plot(range(1,6),explained_variance)
plt.xlabel("No of components")
plt.ylabel("Variance Explained")
plt.show()
