def indate(name, old, **hobbies):
    date = {}
    date['Name'] = name
    date['Old'] = old
    for key, value in hobbies.items():
        date[key] = value
    return date

name = input("請輸入姓名")
old = input("請輸入年齡")
h = {}
k = 0
hobbie = input("請輸入喜歡的嗜好(n結束)")
while hobbie != 'n':
    t = '嗜好' + str(k)
    h[t] = hobbie
    k += 1
    hobbie = input("請輸入喜歡的嗜好(n結束)")

out = indate(name, old, **h)
print(out)