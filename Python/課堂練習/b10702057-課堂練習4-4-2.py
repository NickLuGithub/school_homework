import math

r = eval(input("請輸入半徑:"));
Perimeter = 2 * r * math.pi;
Area = r * r * math.pi;
print("半徑為%6.6s的圓，其圓周長為%10.4f，面積為%12.4f"%(r, Perimeter, Area));
print("半徑為%.3f的圓，其圓周長為%.4f，面積為%.4f"%(r, Perimeter, Area));