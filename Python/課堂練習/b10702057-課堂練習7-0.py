a = [89, 56, 92, 79, 51]
b = [70, 86, 77, '缺考', 83]
c = [0, 0, 0, 0, 0]
agv = [0, 0, 0, 0, 0]
agvix = [0, 0, 0, 0, 0]
agv2 = [0, 0, 0, 0, 0]
agv2ix = [0, 0, 0, 0, 0]

for i in range(0,len(a)):
    if(a[i] == '缺考' or b[i] == '缺考'):
        c[i] = '缺考'
        agv[i] = '缺考'
        agv2[i] = '缺考'
    else:
        c[i] = a[i] + b[i]
        agv[i] = c[i] / 2
        agv2[i] = a[i] * 0.4 + b[i] * 0.6

k = 0
for i in range(0, len(a)):
    if (agv[i] == '缺考'):
        del agvix[i]
        k += 1
    else:
        agvix[i - k] = agv[i]
        

print("學期成績最高者為%d同學" %agv.index(max(agvix)))
print("學期成績最低者為%d同學" %agv.index(min(agvix)))
print("學期個人平均:", agv)
        
k = 0
for i in range(0, len(a)):
    if (agv2[i] == '缺考'):
        del agv2ix[i]
        k += 1
    else:
        agv2ix[i - k] = agv2[i]
        


print("學期成績最高者為%d同學" %agv2.index(max(agv2ix)))
print("學期成績最低者為%d同學" %agv2.index(min(agv2ix)))
print("學期個人平均:", agv2)
