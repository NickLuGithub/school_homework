place = ['觀霧', '日月潭', '阿里山', '小琉球', '墾丁']

print(place)
a = input("請輸入新地名:")
place.append(a)
print(place)
b = input("請輸入新地名:")
place.insert(4, b)
print(place)

print()

place.sort()
print(place)

print()

k = place.index('觀霧')
place.pop(k)
print("index = %d"%k)
print(place)

print()


b = place[4]
k = place.pop(2)
b2 = place.index(b)
k2 = place.pop(b2)
print("刪除了:", k, ", ", k2)
print(place)
