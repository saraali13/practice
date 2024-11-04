class A:
  def display(self):
    print("Hi A")

class B:
  def display(self):
    print("Hi "B)

class C:
  def display(self):
    print("Hi C")

class D:
  def display(self):
    print("Hi D")

class E:
  def display(self):
    print("Hi E")

class F(A,B,C):
  def display(self):
    print("Hi F")

class G(D,B,C):
  def display(self):
    print("Hi G")

class H(D,A):
  def display(self):
    print("Hi Z")

class Z(F,G,H):
  def display(self):
    print("Hi Z")

Z1=Z()
Z1.display()

# L(Z)=Z+ merge(L(F),L(G),L(H),FGH)
#find L(F),L(G),L(H)
#then L(Z)
#ZFGHDABCEO


