import matplotlib.pyplot as plt

x=["a","b","c","d"]
y=[30,21,10,20]
#plt.bar(x,y,color="b")
#plt.show()

c=["r","b","g","p"]
plt.xlabel("Albhabets",fontsize=23)
plt.ylabel("no")
plt.title("Bar Graph")
plt.bar(x,y,width=0.3,color=c,edgecolor="y",linewidth=1,label=usage)
plt.show()

