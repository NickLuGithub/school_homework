n = 0
sum = 0
inputnumber = input("請輸入第%d位學生成績: " %(n + 1))
while(inputnumber != '結束'):
    sum += eval(inputnumber)
    n += 1
    inputnumber = input("請輸入第%d位學生成績: " %(n + 1))
if ( n == 0 ):
    print("我們班沒人啦!")
else:
    print("全班總成績: %d\n全班總平均: %d" %(sum, sum / n))