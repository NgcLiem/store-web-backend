f = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for i in range(int(input())):
    n, k = [int(x) for x in input().split()]
    s = ""
    while(n > 0):
        y = n % k
        s = f[y] + s
        n = int(n / k)
    print(s)    