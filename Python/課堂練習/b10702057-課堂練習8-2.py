def run(a, b, op):
    if(op == '+'):
        return a + b
    elif(op == '-'):
        return a - b
    elif(op == '*'):
        return a * b
    elif(op == '/'):
        if (b == 0):
            return "不能除零喔!"
        else:
            return a / b
    elif(op == '**'):
        sum = 1
        for i in range(1, b + 1):
            sum *= a
        return sum
    elif(op == '!'):
        sum = 1
        for i in range(1, a + 1):
            sum *= i
        return sum

a = eval(input("請輸入a:"))
op = input("請輸入運算符號:")
if (op != '!'):
    b = eval(input("請輸入b:"))
    print("%d %s %d = " %(a, op, b), run(a, b, op))
else:
    print("%d! = %d" %(a, run(a, 0, op)))