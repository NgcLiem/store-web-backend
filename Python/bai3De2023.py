def is_valid_cccd(cccd):
    if len(cccd) != 12:
        return False
    total = 0
    for i in range(len(cccd)):
        b = int(cccd[i])
        if i % 2 == 0:
            b *= 2
            if b > 9:
                b -= 9
        total += b  
    check_sum = (10 - (total % 10) ) % 10           
    return True if check_sum == int(cccd[-1]) else False 

def get_all_cccd(atm):
    if len(atm) != 11 or not atm.isdigit():
        return False
    
    list_valid_cccd = []
    for i in range(10):
       guess = atm + str(i)
       if is_valid_cccd(guess):
           list_valid_cccd.append(guess)
        
    return list_valid_cccd

print(is_valid_cccd("079203000009"))     
# print(get_all_cccd("07920300007"))    