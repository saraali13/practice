import numpy as np

arr=np.arange(25) # 0-24 elements
arr.reshape(5,5)# elements will be reshaped
arr.max()# max value
arr.argmax()# max values index
arr.min()
arr.argmin()

arr[2] #get value of an index
arr[1:5] #get values in this range
arr[0:3]=3 #all value ==3
arr=np.arange(0,11)# array reset 0-10 elements
arr1=arr[0:4]# 0-4 k elemtes seprate array
arr1[:]=8 # all elemnts of sliced array ==8
bool_arr=arr>4 # array filled with bool values
arr[bool_arr]
arr[arr>2]



