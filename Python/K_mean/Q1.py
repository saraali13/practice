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
SSE=[]
for cluster in range (1,21):
    k__mean=KMeans(n_clusters=cluster,init="k-means++")
    k__mean.fit(data_scaled)
    SSE.append(k__mean.inertia_)

frame= pd.DataFrame({"Cluster":range(1,21),"SSE":SSE})
print(f"Predictions: {prediction}")
plt.figure()
plt.plot(frame["Cluster"],frame["SSE"],marker="*")
plt.xlabel("No of clusters")
plt.ylabel("Inertia")
plt.show()



