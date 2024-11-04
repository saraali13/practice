import matplotlib.pyplot as plt

x = ["a", "b", "c", "d"]
y = [30, 21, 10, 20]
a1 = [23, 10, 20, 21]
a2 = [31, 20, 10, 18]
a3 = [28, 21, 15, 25]
color = ["r", "b", "g", "y"]
plt.xlabel("Albhabets")
plt.ylabel("no")
plt.title("Stackplot Graph", fontsize=10)
plt.stackplot(y,a1,a2,a3,labels=x)#can pass 1 or more a's
plt.legend(loc=2)#labels placement=loc
plt.show()
