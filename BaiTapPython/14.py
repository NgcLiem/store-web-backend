import math
a = int(input())
for i in range(a):
    b = input()
    x = ""
    for i in b:
        x = i + x
    print("NO") if math.gcd(int(x), int(b)) != 1 else print("YES")
        