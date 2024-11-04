class A:
  def display(self):
    print("Hi A")

class B(A):
  def display(self):
    print("Hi "B)

class C(A):
  def display(self):
    print("Hi C")

class D(B,C):
  def display(self):
    print("Hi D")

d1=D()
d1.display()

# first will check for D class if not found then B then C and then A
