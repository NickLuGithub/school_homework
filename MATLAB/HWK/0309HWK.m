a = [-1 0 3; 4 3 1]
b = [3 7 2; -1 0 6]

A1 = sum(intersect(a, b), 'all')
A2 = sum(a == b, 'all')