s = "一江春水向東流，兩岸猿聲啼布住，三五村童放紙鷂，四海之內皆兄弟。"

print(s);
print("1");
print(s[8:16]+s[0:8]+s[24:]+s[16:24]);
print("2");
print(s[0]+s[8]+s[16]+s[24]);
print("3");
print(s[-2]+s[-10]+s[-18]+s[-26]);
print("4");
print(s[0:8]+"\n"+s[8:16]+"\n"+s[16:24]+"\n"+s[24:]);

s = """一江春水向東流，
兩岸猿聲啼布住，
三五村童放紙鷂，
四海之內皆兄弟。
"""
print();
print(s);
print("5");
print(s[0]+s[9]+s[18]+s[27]);
print("6");
print(s[0:8]+s[9:17]+s[18:26]+s[27:]);
print("7");
print(s[9:18]+s[0:9]+s[27:]+s[18:27]);