import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler


df=pd.read_csv("Iris.csv")
x = df.iloc[:, :-1].values  # Features (numerical)
y = df.iloc[:, -1].values   # Target (categorical)
scaler=StandardScaler()

data_scaled=scaler.fit_transform(x)
df=pd.DataFrame(data_scaled)

k_means=KMeans(n_clusters=3,init="k-means++")
k_means.fit(data_scaled)# fitting k means algo on he scaled data
K_inertia=k_means.inertia_ #inertia SSE measures how data set was clustered by the algo ,inc K dec inertia
prediction=k_means.predict(data_scaled)
print(f"Predictions: {prediction}")

# Cluster Labels and Centers
labels = k_means.labels_  # Predicted cluster labels for each data point
centers = k_means.cluster_centers_  # Cluster centers

# Plotting Clusters
plt.scatter(x[:, 0], x[:, 1], c=labels, cmap='viridis', s=30)  # Data points
plt.scatter(centers[:, 0], centers[:, 1], c='red', marker='X', s=200)  # Cluster centers
plt.title("K-Means Clustering")
plt.show()






