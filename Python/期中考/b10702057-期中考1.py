i = 1;
sum = 1;

while sum < 100000:
    sum *= i
    i += 1

i-=1
print("n! > 100000 n 最小為:", i)