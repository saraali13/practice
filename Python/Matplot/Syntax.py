plt.bar(x,y,width=0.3,color=c,edgecolor="m",linewidth=4,label="usage")

plt.bar(x,y,width=0.3,color="b",edgecolor="m",linewidth=4,label="usage1")
plt.bar(x,z,width=0.3,color="r",edgecolor="pink",linewidth=4,label="usage2")

plt.scatter(x,y,c=color,s=z,marker="*",edgecolor="black",linewidth=2)

plt.hist(z,color="r",edgecolor="black",linewidth=2)
plt.hist(z,"auto",(0,100),edgecolor="black",linewidth=2)#auto= suitable no of bars for the range given
plt.hist(z,color="r",bins=6,edgecolor="black",linewidth=2,cumulative=-4)#bins=no of bars
plt.hist(z,color="r",bins=6,edgecolor="black",linewidth=2,histtype="step")#type step=no filling clr only border
plt.hist(z,color="r",bins=6,edgecolor="black",linewidth=2,orientation="horizontal")#bins=no of bars

plt.pie(y, labels=x, colors=color, explode=z, autopct="%d")  # autopct = labeled values inside the pie chart

plt.stackplot(y,a1,a2,a3,labels=x)#can pass 1 or more a's

plt.boxplot(y,vert=False,widths=0.5) #for horizontal
plt.boxplot(y,labels=["Hi"],patch_artist=True,showmeans=True)#patch artist color, show mean= line and green arrow rep mean
plt.boxplot(x,labels=["Hi","Bye"],showmeans=True)

plt.step(y,z,color="b",marker="*")

plt.plot(z,y)
plt.text(20,30,"Hi",fontsize=12)#adding text to a perticular point
plt.annotate("Bye",xy=(40,30),xytext=(60,10),arrowprops=dict(facecolor="green"))#pointing using arrow xy text to xy

plt.stem(y, z, linefmt=":", markerfmt="*")

plt.subplot(2, 2, 1)
plt.plot(y, z, color="r")
plt.subplot(2, 2, 2)
plt.pie(y)
plt.subplot(2, 2, 3)
plt.bar(y, z)

plt.fill_between(y, z)
plt.fill_between([17, 20], 11, 21)
plt.fill_between(y, z, color="b", where=(y > 20) & (z < 20), label="Conditional filling")
plt.tight_layout()
