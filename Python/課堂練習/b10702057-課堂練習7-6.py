s = {1,2,3,4,5,6,7,8,9,10}
a = {1,2,3,4,5}
b = {4,5,6,7,8}

out1 = s-a
print("a 補集合 >> ", out1)

out2 = a^b
print("a symmetric dufference b >> ", out2)

out3 = s-(a&b^(s-a^(s-b)))
print("a XOR b >> ", out3)

print("symmetric dufference 是否等於 XOR >> ", out2 == out3)

print("5 in XOR? >> ", 5 in out3)

out4 = s-(a&b)
out5 = s-a|(s-b)

print("等號左邊 >> ", out4, "等號右邊 >> ", out5)
print("兩邊是否相等 >> ", out4 == out5)