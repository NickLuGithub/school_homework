import numpy as np

a = np.array([[1., 2.], [3., 4.]])
b = np.array([[1., 2., 3.], [3., 2., 1.]])
c = np.array([[1.], [-1.]])
d = np.array([[1.], [2.]])

print("a = \n", a, "\n")
print("b = \n", b, "\n")
print("c = \n", c, "\n")
print("d = \n", d, "\n")


if c.shape[1] == d.shape[0]:
    k = dot(c,d)
else:
    k = False

print("1 = \n", np.dot(a, b), "\n")
print("2 = \n", k, "\n")
print("3 = \n", np.linalg.det(a), "\n")
print("4 = \n", np.linalg.inv(a), "\n")
print("5 = \n", np.trace(a), "\n")
print("6 = \n", np.linalg.matrix_power(a, 10), "\n")
print("7 = \n", np.linalg.solve(a, b), "\n")