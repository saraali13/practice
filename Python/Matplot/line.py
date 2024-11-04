import matplotlib.pyplot as plt

y = [30, 21, 10, 20,100]
z = [20, 31, 15, 28,70]
x = [y,z]
color = ["r", "b", "g", "y"]
plt.xlabel("Albhabets")
plt.ylabel("no")
plt.title("Line Graph", fontsize=10)
plt.plot(z,y)
plt.text(20,30,"Hi",fontsize=12)#adding text to a perticular point
plt.annotate("Bye",xy=(40,30),xytext=(60,10),arrowprops=dict(facecolor="green"))#pointing using arrow xy text to xy
#plt.grid() works
plt.show()
