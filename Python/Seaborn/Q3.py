import numpy as np
import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

df=pd.read_csv("sample_name_age_height.csv")
plt.figure()
data=df[["Age","Height"]]
sns.heatmap(data,linewidths=0.5,annot=True)
plt.show()
sns.swarmplot(data=df,x="Age",y="Gender",hue="Age",size=4,dodge=True)#dodge true sep clr (hue) fase will combine
plt.show()

sns.boxenplot(data=df,x="Height",y="Gender")
plt.show()

sns.jointplot(data=df,x="Age",y="Height",hue="Age")
plt.show()
sns.jointplot(data=df,x="Age",y="Height",kind="kde",fill=True)
plt.show()
sns.pairplot(df)
plt.show()
sns.catplot(x="Gender",y="Height",data=df,kind="box")
plt.show()
#sns.catplot(x="Gender",y="Height",data=df,kind="box",row="Age",col="Height")
#plt.show()

