list1 = [1,2,3,4,5,6,7,8,9,10]
list2 = [0,0,0,0,0,0,0,0,0,0]

for i in range(9, -1, -1):
    list2[-(i - 9)] = list1[i];
print(list2)

n = 9;

for i in range(0, len(list1)):
    if (list1[i] % 2 == 1):
        t = list1.pop(i)
        i -= 1
        n -= 1
        print("pop = %2d, list1 = %s" %(t, list1))
        if (i >= n - 1):
            break;
                 
print()

list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
list3 = [0,0,0,0]

n = 9

while i < len(list1):
    if (list1[i] > 6):
        t = list1.pop(i)
        print("pop = %2d, list1 = %s" %(t, list1))
    else:
        i += 1
