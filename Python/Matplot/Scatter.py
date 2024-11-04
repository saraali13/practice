import matplotlib.pyplot as plt

x=["a","b","c","d"]
y=[30,21,10,20]
z=[500,100,78,21]
color=["r","b","g","y"]
plt.xlabel("Albhabets")
plt.ylabel("no")
plt.title("Scatered Graph",fontsize=10)
plt.scatter(x,y,c=color,s=z,marker="*",edgecolor="black",linewidth=2)
plt.show()
