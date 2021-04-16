import numpy as np

A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

print(A[2, :], end=' '), print(A[2, :].shape, '\n') 
print(A[:, :2], end=' '), print(A[:, :2].shape, '\n') 
print(A[1, :2], end=' '), print(A[1, :2].shape, '\n') 