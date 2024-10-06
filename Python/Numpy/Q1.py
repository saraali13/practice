import numpy as np
#creating array from list
l1=[1,2,3]
np.array(l1)
l2=[[1,2,3],[4,8,9],[6,4,1]]
np.array(l2)
#creating array within range
np.arange(0.10) #0-9 elements of array
np.arange(0,11,2) #0-10 elements with gap of 2
#creating array using ither func
np.zeros(4)
np.zeros((3,3))
np.ones((2,2))
np.linespace(0,6,5) #5 elements within range 0-6 gap == equal 
np.eye(3)#3x3 identity matrix

np.random.rand(3,2)# create an array with random values of give shape and size uniformally distributed
np.random.randn(3,2)# normally distributed random values 0-1 both 
np.np.random.randint(1,20,5)# generate 5 values between 1 -20

np.random.seed(42) #on this seed well get the same random values output
np.random.rand(4)
