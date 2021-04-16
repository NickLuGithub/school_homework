string = "apple is a kind of fruit, apple is a brand of cell phone";
string = string.replace(',', '');
print(string);
print(string.split(sep = ' '));
print(type(string.split(sep = ' ')));
print("分割後第一個元素:",string.split(sep = ' ')[0]);
print(string.count(string.split(sep = ' ')[0]));