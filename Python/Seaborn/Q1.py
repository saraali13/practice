import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt
from pyparsing import alphas

df=pd.read_csv("sample_name_age_height.csv")
plt.figure()#figsize(10,4) if want to as a para
sns.scatterplot(x="Age",y="Height",data=df,hue="Age",size="Height",s=300)#clr wrt to age and size wrt height s for size
plt.show()
sns.scatterplot(x="Age",y="Height",data=df, alpha=0.2,hue="Age",style="Height")#blurred=alpha, diff rep for diff height
plt.show()
