import numpy as np

arr1 = np.array([10, 11, 12, 13, 14, 15])
arr2 = np.array([20, 21, 22, 23, 24, 25])
newarr = np.add(arr1, arr2))#[30 32 34 36 38 40]
newarr = np.subtract(arr1, arr2)#[-10  -1   8  17  26  35]
newarr = np.multiply(arr1, arr2)#[ 200  420  660  920 1200 1500]
newarr = np.divide(arr1, arr2)#[ 3.33333333  4.          3.          5.         25.          1.81818182]
newarr = np.power(arr1, arr2)#arr1^arr2
newarr = np.mod(arr1, arr2) # remainder arr1/2
newarr = np.divmod(arr1, arr2) # 2 arrays 1== Quotient and the other remainder
newarr = np.absolute(arr)# all +ve
arr = np.trunc([-3.1666, 3.6667]) # removes the fraction part and returns the int only
arr = np.around(3.1666, 2)# round off tilll 2 digits after dec
arr = np.floor([-3.1666, 3.6667])
arr = np.ceil([-3.1666, 3.6667])
x = np.unique(arr)# removes duplicates
newarr = np.union1d(arr1, arr2)# combine all elemets into a e=new array
newarr = np.setdiff1d(set1, set2) # elements of arr 1 that are not in arr2
x = np.gcd(num1, num2)
x = np.gcd.reduce(arr)# gcd of all the elemts in that arr
x = np.lcm(num1, num2)
x = np.lcm.reduce(arr) # lcm of all arr's elements
newarr=np.diff(arr)# arr[0]-arr[1],arr[1]-arr[2] and so on
newarr = np.diff(arr, n=2) # diff ka diff 2nd order diff
X=np.prod(arr)# product of all elemets of arr
X=np.prod([arr1,arr2])# product of elements of both arrays
X=np.add(arr1,arr2)
X=np.sum(arr1,arr2)# 1 output overall sum
newarr = np.cumsum(arr)# arr[0],arr[0]+arr[1],arr[0]+arr[1]+arr[2]











