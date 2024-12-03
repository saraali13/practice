import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import  classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler

df=pd.read_csv("Iris.csv")
print(df.shape)

x = df.drop(columns=["Species"])  # Features
y = df["Species"]  # Target
test_size=0.20
seed=7

x_train,x_test,y_train,y_test= train_test_split(x,y,test_size=test_size,random_state=seed)

scaler=StandardScaler()
x_train_scaled=scaler.fit_transform(x_train)
x_test_scaled=scaler.fit_transform(x_test)

n_range=range(1, len(x_train) + 1)
accuraries=[]

for k in n_range:
    knn=KNeighborsClassifier(n_neighbors=k)
    knn.fit(x_train_scaled,y_train)
    y_prediction=knn.predict(x_test_scaled)
    accuraries.append(accuracy_score(y_test,y_prediction))

best_K_val=n_range[accuraries.index(max(accuraries))]
worst_K_val=n_range[accuraries.index(min(accuraries))]
print(f"Best K val:{best_K_val} with accuracy: {max(accuraries)}")
print(f"worst K val:{worst_K_val} with accuracy: {min(accuraries)}")
