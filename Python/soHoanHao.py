import math

def soHoannHao(n):
    if n < 2:
        return False
    total = 1
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            total += i
            if i != n // i:
                total += n // i
    return True if total == n else False
        
for i in range(int(input()) + 1):
    if soHoannHao(i):
        print(i)
    