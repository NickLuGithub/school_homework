l1 = ['鼠', '牛', '虎', '兔', '龍', '蛇', '馬', '羊', '猴', '雞', '狗', '豬']
ina = eval(input("請輸入年代(西元前10000年到西元後10000年):\n"))
if(int(ina) == 1900):
    out = 0
    print("西元%5d年屬%s" %(ina, l1[out]))
elif(ina > 1900):
    out = (ina - 1900) % 12
    print("西元%5d年屬%s" %(ina, l1[out]))
elif(ina < 1900 and ina > 0):
    out = 12 - ((1900 - ina) % 12)
    print("西元%5d年屬%s" %(ina, l1[out]))
elif(ina == 0):
    out = 12 - ((1900 - ina) % 12)
    print("西元元年屬%s" %(l1[out]))
elif(ina < 0):
    out = 12 - ((1900 + (ina * -1)) % 12)
    print("西元前%5d年屬%s" %(ina * -1, l1[out]))
else:
    print("")