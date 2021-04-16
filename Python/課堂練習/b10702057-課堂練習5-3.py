import random;

a = random.randrange(1, 101);
if(a % 2 == 1):
    if(a > 40):
        b = a - 40;
    else:
        b = a * 1.5;
else:
    if(a > 70):
        b = a - 70;
    else:
        b = a / 10;
print("原始數值 >> %d\n最終數值 >> %d" %(a, b));