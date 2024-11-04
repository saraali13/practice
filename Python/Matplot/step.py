import matplotlib.pyplot as plt

y = [30, 21, 10, 20,100]
z = [20, 31, 15, 28,70]
x = [y,z]
color = ["r", "b", "g", "y"]
plt.xlabel("Albhabets")
plt.ylabel("no")
plt.title("Step Graph", fontsize=10)
plt.step(y,z,color="b",marker="*")
plt.grid()
plt.show()
