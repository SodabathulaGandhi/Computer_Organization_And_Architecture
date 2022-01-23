#!/usr/bin/env python
# coding: utf-8

# In[1]:


import time
import numpy as np
start = time.time( )

n=int(input("Enter the matrix size: "))

array1 = np.random.randint(1,10,size=(n,n))
print(array1)
array2 = np.random.randint(1,10,size=(n,n))
print(array2)

result =np.zeros([n, n], dtype = float)

# iterating by row of array1
mulstart = time.time( )
for i in range(len(array1)):
    # iterating by column by array2
    for j in range(len(array2[0])):
        # iterating by rows of array2
        for k in range(len(array2)):
              result[i][j] += array1[i][k] * array2[k][j]
mulend = time.time( )
print("The time taken for execution of only multiplication is :", mulend-mulstart)

for r in result:
    print(r)
    end = time.time( )
print("The complete time taken for execution of above program is :", end-start)


# In[ ]:




