import time
import random
list1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
op = input("請輸入Y開始遊戲")
print(list1)
t0 = time.time()
while op == 'y' or op == 'Y':
    for i in range(0, 10):
        k = random.randrange(0, 26)
        print(list1[k])
        for l in range(3):
            a = input("請輸入前一個字母")
            if (list1[k] == 'a' and a == '0'):
                break
            elif ((a in list1) == True):
                if ((list1.index(a)) == (list1.index(list1[k])) - 1):
                    break
            else:
                print("錯誤 ", end = "")
        else:
            print("不要鬧了!")
            op = 'end'
            break
    else:
        t1 = time.time()
        print("總共猜10次，您總空花了%f秒" %(t1 - t0))
        op = 'end'
