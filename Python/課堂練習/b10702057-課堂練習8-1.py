def number_i(a):
    sum = 1
    for i in range(1, a + 1):
        sum *= i
    return sum

a = eval(input("請輸入數字"))
print(a, "! = ", number_i(a))