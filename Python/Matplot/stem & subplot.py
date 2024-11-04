import matplotlib.pyplot as plt

y = [30, 21, 10, 20, 11]
z = [20, 31, 15, 28, 17]

plt.figure()

plt.stem(y, z, linefmt=":", markerfmt="*")
plt.show()

plt.subplot(2, 2, 1)
plt.plot(y, z, color="r")
plt.subplot(2, 2, 2)
plt.pie(y)
plt.subplot(2, 2, 3)
plt.bar(y, z)

plt.tight_layout()
plt.show()

#plt.fill_between(y, z)
#plt.fill_between([17, 20], 11, 21)
#plt.fill_between(y, z, color="b", where=(y > 20) & (z < 20), label="Conditional filling")
