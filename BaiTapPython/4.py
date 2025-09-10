def giaiThua(n):
    return 1 if n == 0 else n * giaiThua(n - 1)
for b in range(int(input())):
    a = input()
    sum1 = sum(giaiThua(int(i)) for i in a)
    print("Yes") if sum1 == int(a) else print("No")     