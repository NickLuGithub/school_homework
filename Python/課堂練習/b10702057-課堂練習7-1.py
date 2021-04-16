print("1")

list1 = [1,2,3,4]
a = [5, 6, 7, 8]

list1.append(a)
print(list1)
list1 = [1,2,3,4]
list1.extend(a)
print(list1)

print("2")

list1 = [1,2,3,4]
a = 'test'

list1.append(a)
print(list1)
list1 = [1,2,3,4]
list1.extend(a)
print(list1)

print("3")

list1 = [1,2,3,4]
a = ['a', 'b', 'c']

list1.append(a)
print(list1)
list1 = [1,2,3,4]
list1.extend(a)
print(list1)

print("4")

list1 = [1,2,3,4]
a = '阿貓'

list1.append(a)
print(list1)
list1 = [1,2,3,4]
list1.extend(a)
print(list1)

print("5")

list1 = [1,2,3,4]
a = ['阿貓', '阿狗']

list1.append(a)
print(list1)
list1 = [1,2,3,4]
list1.extend(a)
print(list1)

print("6")

list1 = [1,2,3,4]
a = 0

list1.append(a)
print(list1)
list1 = [1,2,3,4]
list1.extend(a)
print(list1)