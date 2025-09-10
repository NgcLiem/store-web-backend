import math
def snt(a):
    if a < 2:
        return False
    for i in range(2, int(math.sqrt(a))+1):
        if a % i == 0:
            return 0
    return 1    

def check(s):
    for i in range(len(s)):
        if snt(i) != snt(int(s[i])):
            return 0
    return 1    

a = int(input())
for i in range(a):
    b = input()
    if check(b) == 1:
        print("YES")
    else:
        print("NO")    
    
        