import matplotlib.pyplot as plt

x=["a","b","c","d"]
y=[30,21,10,20]
z=[10,15,8,12]

#c=["r","b","g","y"] marzi h
plt.xlabel("Albhabets")
plt.ylabel("no")
plt.title("Bar Graph",fontsize=23)
plt.bar(x,y,width=0.3,color="b",edgecolor="m",linewidth=4,label="usage1")
plt.bar(x,z,width=0.3,color="r",edgecolor="pink",linewidth=4,label="usage2")
plt.legend()
plt.show()
