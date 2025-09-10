import math

n = int(input("Nhap n: "))

def checkSNT(m):
    for i in range(2, m, 1):
        if m % i == 0:
            return 1;   
    return 0;

list1 = []
for i in range(2, n + 1, 1):
    if checkSNT(i) == 0:
        list1.append(i)
for j in list1:
    print(j)    
    

