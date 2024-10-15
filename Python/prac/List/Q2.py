from audioop import reverse

l1=[1,2,3,2]
summ=0
for i in range(5):
    l1.append(int(input("Enter a number")))

for i in l1: # var "i" is the element in the list
    if i % 2 == 0:
        print(i)
for i in l1:
    summ+=i
print(summ)
l1 = [i for i in l1 if i > 2] # remove pop (pop without any arg will remove the last element of the list) del l1[i] can also be used to delete an element from list but here they are not giving the desired output
print(l1)
l1.append(4)
l1.extend([4, 5])
l1.insert(1, 'a')
l1.count(2)# count of 2 in the list
l1.clear()# removes all elements from the list
sorted(l1)
sum(l1)
min(l1)
reverse(l1)
max(l1)
len(l1)
all(l1)# true if all elements of the list are nonzero
any(l1)# true if any 1 element is non zero
l2=["a","b"]
list(zip(l1,l2))# combine both the lists into a new list

