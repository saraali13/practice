import matplotlib.pyplot as plt

z=[90,100,78,81,40,10,50,79,54,52,21,60,100,100,100,81,79,50]
c=["r","b","g","y"]
plt.xlabel("number")
plt.ylabel("freq")
plt.title("Hist Graph",fontsize=10)
#plt.hist(z,color="r",edgecolor="black",linewidth=2)
#plt.hist(z,"auto",(0,100),edgecolor="black",linewidth=2)
#plt.hist(z,color="r",bins=6,edgecolor="black",linewidth=2,cumulative=-4)#bins=no of bars
#plt.hist(z,color="r",bins=6,edgecolor="black",linewidth=2,histtype="step")#type step=no filling clr only border
plt.hist(z,color="r",bins=6,edgecolor="black",linewidth=2,orientation="horizontal")#bins=no of bars
plt.show()
