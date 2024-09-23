from collections import Counter

a=[1,1,1,1,1,2,2,2,2,2,5,5,5]
c=Counter(a)
print(c)
#{1:4,2:6,5:3}
sub={1:2,2:3}
c.subtract(sub)
print(c.most_common())
#[(1,2),(2,3),(5,3)]
