name = input("請輸入姓名:")
old = input("請輸入你的年齡:")
mg = input("請輸入性別:")

a = '{}\t{}\t{}'
b = '{Name}\t{Old}\t{Mg}'
c = '{0}\t{1}\t{2}'

print("%s\t%s\t%s" %('姓名', '年齡', '性別'));
print("--------------------");
print("%s\t%s\t%s" %(name, old, mg));
print("____________________");

print("");

print(a.format('姓名', '年齡', '性別'));
print("--------------------");
print(a.format(name, old, mg));
print("____________________");

print("");

print(b.format(Name = '姓名', Old = '年齡', Mg = '性別'));
print("--------------------");
print(b.format(Name = name, Old = old, Mg = mg));
print("____________________");

print("");

print(c.format('姓名', '年齡', '性別'));
print("--------------------");
print(c.format(name, old, mg));
print("____________________");
