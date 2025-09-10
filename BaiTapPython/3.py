import math
def snt(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


def check(n, m):
    x = ""
    y = ""
    for j in str(n):
        x = j + x
    if snt(n) and snt(int(x)) and int(x) <= m:
        y = y + str(n) + str(x)
        
for a in range(int(input())):
    b = int(input())
    
    for i in range(13, b + 1):
       check(i, b)
    print(' '.join(set(y)))  