import numpy as np

def number(x, y):
    op = x + y + 2
    if (op == 2 or op == 18):
        return 1
    elif (op == 3 or op == 17):
        return 2
    elif (op == 4 or op == 16):
        return 3
    elif (op == 5 or op == 15):
        return 4
    elif (op == 6 or op == 14):
        return 5
    elif (op == 7 or op == 13):
        return 6
    elif (op == 8 or op == 12):
        return 7
    elif (op == 9 or op == 11):
        return 8
    else:
        return 9
int_array = np.arange(9, 9)
listt = test = [[0] * n] * n
int_array = np.array(listt)
for i in range(0, 9, 1):
    for j in range(0, 9, 1):
        int_array[i][j] = number(i, j)
print(int_array, "\n", int_array.dtype)
print()
int_array = int_array.astype(np.float64)
print(int_array, "\n", int_array.dtype)