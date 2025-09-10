# print(oct(int(input(), 2))[2::])

f = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
a = int(input(), 2)
b = a 
x = ""
if a == 0:
    x = "0"
else:    
    while(a > 0):   
        b = a % 8
        x = f[b] + x
        a //= 8
print(x)    
