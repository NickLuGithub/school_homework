import random
import time
r = 0
l1 = ['鼠', '牛', '虎', '兔', '龍', '蛇', '馬', '羊', '猴', '雞', '狗', '豬']
op = 'go'
run = 0
while (op == 'go'):
    instr = input("猜一猜產生的生肖:")
    if (instr in l1 == False):
        print("輸入錯誤")
        break
    inln = l1.index(instr)
    if (run == 0):
        for i in range(20):
            r = random.randrange(0, 12)
            print("\r   %2d %s" %(r + 1, l1[r]), end ="")
            time.sleep(0.1)
        if (inln == r):
            print("厲害，猜中了")
            op = 'end'
        elif (inln != r):
            print("再猜猜看")
            run = 1
            op = 'go'
    else:
        if (inln == r):
            print("厲害，猜中了")
            op = 'end'
        elif (inln != r):
            print("再猜猜看")
            run = 1
            op = 'go'
    