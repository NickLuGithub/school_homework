s1 = {1, 2, 3}
s2 = {2, 3, 4}
s3 = {'a', 'b', 'c'}

print(type(s1))
print(type(s2))

out1 = sorted(s1)
out2 = sorted(s3)

print(out1)
print(out2)

##print(out1 - s2)


fs1 = frozenset(s1)
fs2 = frozenset(s2)
print(fs1, type(fs1))

out3 = s1 - fs1
print(out3, type(out3))

out4 = fs1 - s1
print(out4, type(out4))

out5 = fs1 - fs2
print(out5, type(out5))