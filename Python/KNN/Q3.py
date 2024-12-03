import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split,cross_val_score
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

knn1=KNeighborsClassifier(n_neighbors=best_K_val)
knn1.fit(x_train_scaled,y_train)
y_predict=knn1.predict(x_test_scaled)

# Performance Evaluation
acc = accuracy_score(y_test, y_predict)
cm = confusion_matrix(y_test, y_predict)
print("Accuracy:", acc)
print("\nConfusion Matrix:\n", cm)
print("\nClassification Report:\n", classification_report(y_test, y_predict))

# 10-Fold Cross-Validation
cv_scores = cross_val_score(knn1, x_train_scaled, y_train, cv=10, scoring='accuracy')
print("\n10-Fold Cross Validation Mean Accuracy: {:.2f}%".format(cv_scores.mean() * 100))

# Discussing the Confusion Matrix
tp = cm.diagonal().sum()  # Sum of diagonal elements gives true positives for all classes
fn = cm.sum(axis=1) - cm.diagonal()  # False negatives
fp = cm.sum(axis=0) - cm.diagonal()  # False positives
tn = cm.sum() - (tp + fp + fn)  # Remaining cells are true negatives
print("\nDetailed Confusion Matrix Analysis:")
for i, _ in enumerate(np.unique(y)):
    print(f"Class {i+1}:")
    print(f"  True Positives (TP): {tp}")
    print(f"  False Negatives (FN): {fn[i]}")
    print(f"  False Positives (FP): {fp[i]}")
    print(f"  True Negatives (TN): {tn[i]}\n")
