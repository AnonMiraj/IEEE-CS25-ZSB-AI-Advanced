---
jupyter:
  jupytext:
    text_representation:
      extension: .md
      format_name: markdown
      format_version: '1.3'
      jupytext_version: 1.16.6
  kernelspec:
    display_name: base
    language: python
    name: python3
---

**By:** *Ahmed Sharaf*


In this notebook you will practice how to:
1. Calculate the determinant of a 2x2 matrix with and without using numpy.linalg
2. Calculate the determinant of a 3x3 matrix with and without using numpy.linalg
3. Calculate the inverse of a 2x2 matrix using numpy.linalg
4. Calculate the inverse of a 3x3 matrix using numpy.linalg
5. Finding the rank of a matrix using numpy


### Notice

**Please Note:**  
When writing code, make sure to place it in the designated area marked with `# code here`.  
If there is a `pass` keyword in the code, please remove it and replace it with the required code.


# Calculating the determinant using numpy.linalg

```python
import numpy as np
```

```python
a2 = np.array([[1,2],[3,4]])
print(a2)
```

```python
a3 = np.array([[1,1,2],[2,3,1],[3,4,-5]])
print(a3)
```

```python
## Determinate of a2, a3
## Code Here
print(np.linalg.det(a2))
print(np.linalg.det(a3))
```

# Calculating the determinant of a 2x2 matrixwithout using numpy

```python
def Det1(Mat):
    return (Mat[0][0]*Mat[1][1]-Mat[0][1]*Mat[1][0])
print(a2)
print(Det1(a2))
```

# Calculating the determinant of a 3x3 matrixwithout using numpy

One idea
1. write a function to calculate the minor matrices. (hint, use slices)
2. write a function to calculate the cofactors (this should call the first function, and the determinant function)
3. the determinant function calls the function in step two and adds the results together.

Another idea 
use recursion ==> code credit https://stackoverflow.com/questions/3819500/code-to-solve-determinant-using-python-without-using-scipy-linalg-det


```python
# delete function removes a sub-array from the input array
# first argument is the original array
# second argument is the index to the sub-array to be removed
# third argument is the axis among which the deletion happens (0: x axis "row" and 1: y axis "column")
arr = np.array([[1,2,3,4], [5,6,7,8], [9,10,11,12]])
print(arr)

arr2 = np.delete(arr, 1, 0)
print(arr2)

arr3 = np.delete(arr, 3, 1)
print(arr3)
print(arr)
```

```python
def minor(arr,i,j):
    arr2 = np.delete(arr, i, 0)
    return np.delete(arr2, j, 1)


def det(arr):

    if arr.shape == (1, 1):
        return arr[0, 0] 
    
    if arr.shape == (2, 2):
        return arr[0, 0] * arr[1, 1] - arr[0, 1] * arr[1, 0]
    d = 0
    tog = 1
    for j in range(arr.shape[1]):
        cof= tog * arr[0, j] * det(minor(arr, 0, j))
        tog *=  -1
        d+= cof
    
    return d

print(a3)
det(a3)

```

# Calculating the inverse using numpy.linalg

```python
# The inverse of 2 x 2 matrix

a2 = np.array([[1,2],[3,4]])

det_a2 = det(a2)
print(a2)


# Code Here
print(np.linalg.inv(a2))
```

```python
# The inverse of a singular matrix

a3 = np.array([[1,2],[2,4]])

print(a3)

print(np.linalg.inv(a3))
## Code Here
```

```python
# The inverse of 3 x 3 matrix

A = np.array([[6, 1, 1],
              [4, -2, 5],
              [2, 8, 7]])
  
# Calculating the inverse of the matrix
## Code Here
print(np.linalg.inv(A))
```

```python
# Inverses of several matrices can
# be computed at once

A = np.array([[[1., 2.], 
               [3., 4.]],
              [[1, 3], 
               [3, 5]]])
  
# Calculating the inverse of the matrix
## Code Here
print(np.linalg.inv(A))
```

# Calculating the inverse of a 2x2 matrixwithout using numpy


1. Code a function to calculate the determinant of 2x2 matrix
2. Code a function that interchange the diagonal elements of a 2x2 matrix and inverse the sign of the off diagonal elements
3. Code a function to compute the inverse of 2x2 matrix based on the two previous functions if it exists

```python
#step -1- we already coded the det function that works for 2x2 and nxn size matrix

#step -2-
def interchangeMatrix(A):
   # Code Here 
   return [[A[1][1], -A[0][1]], [-A[1][0], A[0][0]]]

#step -3-
def inverse2x2(A):
    d = det(A)
    if d == 0:
        return 
    im = interchangeMatrix(A)
    return  im /d 


a2 = np.array([[1,2],[3,4]])
print(inverse2x2(a2))
```

# Calculating the inverse of a 3x3 matrixwithout using numpy


# Use the adjoint matrix method

Coding a Python code to inverse a 3x3 matrix (no numpy.linalg.inv allowed):
1. Coding a function that checks if a 3x3 matrix is invertible
2. Coding a function that generates the transpose of a 3x3 matrix
3. Coding a function that generates the matrix of minors of a 3x3 matrix
4. Coding a function that generates the matrix of cofactors of a 3x3 matrix
5. Coding a function that generates the inverse of a 3x3 matrix if it exists


```python
#step -1- a matrix is invertible only if its determinant != 0
def invertible(A):
    return det(A) != 0

#step -2- rows and columns could be interchanged without the need of built-in methods
def transposeM(A):
    return [[A[j][i] for j in range(3)] for i in range(3)]

#step -3- we coded that previously minor(arr,i,j)

#step -4- Calculating the matrix of cofactors (minors determinants multiplied by signs)
def cofactors(A):
    cof = [[((-1) ** (i + j)) * det(minor(A, i, j)) for j in range(3)] for i in range(3)]
    return cof


#step -5- Inverse is the transpose of the cofactor matrix divided by the determinant of the original/input matrix
def inverse3x3(A):
    if invertible(A):
        d = det(A)
        im = transposeM(cofactors(A))
        return im/d


B = np.array([[6, 1, 1],
              [4, -2, 5],
              [2, 8, 7]])

print(inverse3x3(B))

#[ 0.17647059 -0.00326797 -0.02287582]
# [ 0.05882353 -0.13071895  0.08496732]
# [-0.11764706  0.1503268   0.05228758]]
#check
print(np.linalg.inv(B))
```

# Finding the rank of a matrix using numpy

```python
a3 = np.array([[1,2],[2,4]])


## Code Here
np.linalg.matrix_rank(a3)
```
