import numpy as np

A = np.array([[1, 1, 1, 1], [2, 2, 1, 1], [3, 3, 2, 2]])
B = np.array([[1, 1, 1, 1], [1, 2, 1, 1], [3, 1, 1, 1], [3, 2, 1, 2]])

C = np.dot(A, B)
print("C = \n", C)
print()

a11 = A[:2, :2]
a12 = A[:2, 2:]
a21 = A[2:, :2]
a22 = A[2:, 2:]

b11 = B[:2, :2]
b12 = B[:2, 2:]
b21 = B[2:, :2]
b22 = B[2:, 2:]

#C11 = A11和B11的矩陣乘積+A12和B21的矩陣乘積 
c11 = np.dot(a11, b11) + np.dot(a12, b21)
print("c11 = \n", c11)
print()
#C12 = A11和B12的矩陣乘積+A12和B22的矩陣乘積 
c12 = np.dot(a11, b12) + np.dot(a12, b22)
print("c12 = \n", c12)
print()
#C21 = A21和B11的矩陣乘積+A22和B21的矩陣乘積
c21 = np.dot(a21, b11) + np.dot(a22, b21)
print("c21 = \n", c21)
print()
#C22 = A21和B12的矩陣乘積+A22和B22的矩陣乘積
c22 = np.dot(a21, b12) + np.dot(a22, b22)
print("c22 = \n", c22)
print()
