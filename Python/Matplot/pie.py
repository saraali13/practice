import matplotlib.pyplot as plt

x = ["a", "b", "c", "d"]
y = [30, 21, 10, 20]
z = [0, 0, 0, 0.2]  # distance for exploding
color = ["r", "b", "g", "y"]
plt.xlabel("Albhabets")
plt.ylabel("no")
plt.title("Pie Graph", fontsize=10)
plt.pie(y, labels=x, colors=color, explode=z, autopct="%d")  # autopct = labeled values inside the pie chart
plt.show()
