def appetizer():
    k = ["凱薩莎拉","鮮蝦蘆筍","水果沙拉"]
    print("現在為您點開胃菜:\n1. ", k[0], "\n2. ", k[1], "\n3. ", k[2], "\n請輸入您要的餐點:" , end = "")
    op = eval(input())
    op -= 1
    print("完成開胃菜點餐,你點的開胃菜是%s" %k[op])
    return k[op]

def soup():
    k = ["香菇雞肉湯","鮮魚湯","牛肉湯"]
    print("現在為您點湯品:\n1. ", k[0], "\n2. ", k[1], "\n3. ", k[2], "\n請輸入您要的餐點:" , end = "")
    op = eval(input())
    op -= 1
    print("完成湯品點餐,你點的湯品是%s" %k[op])
    return k[op]
    
def main_course():
    k = ["超級厚黑牛排","夭壽鮮嫩魚排", "不好吃砍頭雞排"]
    print("現在為您點主餐:\n1. ", k[0], "\n2. ", k[1], "\n3. ", k[2], "\n請輸入您要的餐點:" , end = "")
    op = eval(input())
    op -= 1
    print("完成主菜點餐,你點的主菜是%s" %k[op])
    return k[op]
    
def dessert():
    k = ["法式布蕾","炭烤布丁", "橙汁奶酪"]
    print("現在為您點甜點:\n1. ", k[0], "\n2. ", k[1], "\n3. ", k[2], "\n請輸入您要的餐點:" , end = "")
    op = eval(input())
    op -= 1
    print("完成甜點點餐,你點的甜點是%s" %k[op])
    return k[op]
    