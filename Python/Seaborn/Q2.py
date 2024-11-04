import numpy as np
import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

df=pd.read_csv("sample_name_age_height.csv")
plt.figure()#figsize(10,4) if want to as a para
sns.rugplot(x="Height",data=df)
plt.xlim(100,700)
plt.show()
sns.displot(df["Age"],color="b",edgecolor="r",kde=True)
plt.show()
sns.countplot(data=df,x="Age",hue="Age")
plt.show()
sns.barplot(data=df,x="Age",y="Height",estimator=np.mean,errorbar="sd",hue="Age")
plt.show()
sns.boxplot(data=df,y="Height",x="Age",hue="Age",palette="Set2")
plt.show()
