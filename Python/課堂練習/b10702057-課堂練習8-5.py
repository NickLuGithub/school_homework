def a(n):
    if n <= 1:
        return 1
    else:
        if(n % 2 == 1):
            return n + (a(n-1))
        else:
            return a(n-1)
        
        
innumber = eval(input("請輸入N:"))
out = a(innumber)
print("1~n的奇數總和",out)