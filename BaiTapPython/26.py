import math
class Point:
    def __init__(self, x, y, z, t):
       self.x = x
       self.y = y
       self.z = z
       self.t = t 
       self.khoangCach = math.sqrt((z - x) ** 2 + (t - y) ** 2)
    def __str__(self):
        return f"{self.khoangCach:.4f}"
    def __lt__(self, other):
        return self.khoangCach < other.khoangCach   

ds = []
for i in range(int(input())):
    a = input().split()
    ds.append(Point(int(a[0]), int(a[1]), int(a[2]), int(a[3])))
ds.sort()
for i in ds:
    print(i)    
    
           