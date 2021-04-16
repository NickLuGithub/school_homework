import random;

compter = random.randrange(-100, 101);
player = eval(input("請猜疑個-100到100的數字"));
if(compter == player):
    print("電腦數字為:", compter);
    print("太神啦，猜中囉");
elif(compter < player):
    print("電腦數字為:", compter);
    print("太大囉!!");
else:
    print("電腦數字為:", compter);
    print("太小囉!!");
         