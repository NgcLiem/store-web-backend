def round(n):
    return 1 if n >= 5 else 0
a = int(input())
for i in range(a):
    arr = [int(lst) for lst in input()]
    for j in range(arr.__len__() - 1, 0, -1):
        arr[j-1] += round(arr[j])
        arr[j] = 0
    print(''.join(map(str,arr)))       