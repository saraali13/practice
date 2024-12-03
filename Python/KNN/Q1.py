from array import array

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import  classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.neighbors import KNeighborsClassifier

df=pd.read_csv("Iris.csv")
print(df.shape)

x = df.drop(columns=["Species"])  # Features
y = df["Species"]  # Target

test_size=0.20
seed=7

#dividing into test and train
x_train,x_test,y_train,y_test= train_test_split(x,y,test_size=test_size,random_state=seed)

knn=KNeighborsClassifier(n_neighbors=2)# two nearest neighbours
knn.fit(x_train,y_train)# training the model
y_prediction=knn.predict(x_test)# model prediction

acc=accuracy_score(y_test,y_prediction)
cl_rep=classification_report(y_test,y_prediction)
cn_mat=confusion_matrix(y_test,y_prediction)

TP=cn_mat[1,1]# true positive
TN=cn_mat[0,0]# true negative
FP=cn_mat[0,1]# false positive
FN=cn_mat[1,0]# false negative

precision= TP/(TP+FP)
recall=TP/(TP+FN)
training_accuracy=knn.score(x_train,y_train)
testing_accuracy=knn.score(x_test,y_test)

print("Accuracy: ",acc)
print("Classification Report: ",cl_rep)
print("Confusion Matrix: ",cn_mat)

print(f"True Positive: {TP}\nTrue Negative: {TN}\nFalse Positive: {FP}\nFalse Negative: {FN}")
print("Precision: ",precision)
print("Recall: ",recall)
print("Training Accuracy: ",training_accuracy)
print("Testing Accuracy: ",testing_accuracy)
