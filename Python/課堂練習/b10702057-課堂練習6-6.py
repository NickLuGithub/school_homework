import random
run = 0
n = 0
compter = random.randrange(-100, 101)
player = eval(input("請猜疑個-100到100的數字"))
while run != -1:
    if(compter == player):
        print("電腦數字為:", compter)
        print("恭喜猜中囉，共猜了%d次" %n)
        run = -1
    elif(compter < player):
        player = eval(input("太大囉!!"))
        n += 1
    else:
        player = eval(input("太小囉!!"))
        n += 1