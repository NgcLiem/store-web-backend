list1 = ['Huyndai', 'Morning', 'other']

def hamTinhTienTaxi(a, b, c):
    if a == 'Huyndai':
        if b <= 0.741:
            return f"gia tien: {(10000 + c * 3000 / 4):.2f}"  
        elif b <= 30: 
            return f'gia tien: {(10000 + (b - 0.741) * 13900 + c * 3000 / 4):.2f}'
        elif b <= 60:
            return f'gia tien: {(10000 + (30 - 0.741) * 13900 + (b - 30) * 11600 + c * 3000 / 4):.2f}'
        elif b > 60:
            return f'gia tien: {(10000 + (30 - 0.741) * 13900 + 29 * 11600 + (b - 60) * 10300 + c * 3000 / 4):.2f}'
        
    elif a == 'Morning':
        if b <= 0.752:
            return f'gia tien: {(10000 + c * 3000 / 4):.2f}'
        elif b <= 30: 
            return f'gia tien: {(10000 + (b - 0.752) * 13600 + c * 3000 / 4):.2f}'
        elif b > 30:
            return f'gia tien: {(10000 + (30 - 0.752) * 13600  + (b - 30) * 11000 + c * 3000 / 4):.2f}'
        
    else:
        if b <= 0.748:
            return f'gia tien: {(11000 + c * 3000 / 4):.2f}'
        elif b <= 30: 
            return f'gia tien: {(10000 + (b - 0.748) * 15100 + c * 3000 / 4):.2f}'
        elif b <= 60:
            return f'gia tien: {(10000 + (30 - 0.748) * 13900 + (b - 30) * 12000 + c * 3000 / 4):.2f}'  
    
for i in list1:
    print(hamTinhTienTaxi(input('Nhap loai xe(Huyndai, Morning, xa khac): '),
                          float(input('Nhap so km di duoc: ')) ,
                          float(input('Nhap thoi gian cho bao nhieu phut: '))))
    break
        
   