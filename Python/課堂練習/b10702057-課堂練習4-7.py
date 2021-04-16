a = 64
b = '64'
print(a);
print(type(a));
print("");
print(b);
print(type(b));
print("");

a = 64
b = '64'
a = bin(a)
b = bin(int(b))

print(a);
print(type(a));
print("");
print(b);
print(type(b));
print("");

a = 64
b = '64'
a = oct(a)
b = oct(int(b))

print(a);
print(type(a));
print("");
print(b);
print(type(b));
print("");

a = 64
b = '64'
a = hex(a)
b = hex(int(b))

print(a);
print(type(a));
print("");
print(b);
print(type(b));
print("");

print("二進位無64");
print("");
c = '64';
print(int(c, 8));
print(type(int(c, 8)));
print("");
print(int(c, 16));
print(type(int(c, 16)));
