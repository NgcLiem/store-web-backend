m = int(input())
a = [float(x) for x in input().split()]
maxa = max(a)
mina = min(a)
b = [x for x in a if x != maxa and x != mina]
print(f"{sum(b) / len(b):.2f}")