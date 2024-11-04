import matplotlib.pyplot as plt

y = [30, 21, 10, 20,100]
z = [20, 31, 15, 28,70]
x = [y,z]
color = ["r", "b", "g", "y"]

plt.title("Box Graph", fontsize=10)
#plt.boxplot(y,vert=False,widths=0.5) for horizontal
#plt.boxplot(y,labels=["Hi"],patch_artist=True,showmeans=True)#patch artist color, show mean= line and green arrow rep mean
plt.boxplot(x,labels=["Hi","Bye"],showmeans=True)
plt.show()
