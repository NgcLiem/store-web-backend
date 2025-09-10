# a = int(input())
# if a % 2 == 0 : print("CHAN")
# else : print("LE")

n = int(input())
for i in range(n):
    s = input()
    count = 1
    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            print(count, end = "")
            print(s[i - 1], end = "")
            count = 1
        else:
            count += 1
    print(count, end = "")
    print(s[len(s)-1])        
            
                