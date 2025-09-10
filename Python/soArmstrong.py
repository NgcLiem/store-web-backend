def is_armstrong(n):
    digits = [int(i) for i in n]
    b = len(digits)
    sum1 = sum(i ** b for i in digits)
    return True if sum1 == n else False 

def list_n_armstrong(n):
    for i in range(n+1):
        if is_armstrong(i):
            print(i)

def get_armstrong(my_list):
    result = set()
    for i in my_list:
        if is_armstrong(i):
            result.add(i)
    return sorted(result, reverse = True)      


def get_frequency(path_to_file):
    frequency = {}
    
    #Đọc dữ liệu từ file
    with open(path_to_file, 'r') as f:
        content = f.read 
            
    import re 
    numbers = re.findall(r'\b\d+\b', content)
    
    for num_str in numbers:
        num = int(num_str)
        if is_armstrong(num):
            frequency[num] = frequency.get(num, 0) + 1
            
    #Ghi từ điển ra file log
    with open(r'D:\get_frequency.log', 'w') as f:
        for key, value in frequency.items():
            f.write(f"{key}:{value}\n")
            
    return frequency

my_list = [153, 370, 371, 407, 9474, 153, 10, 407]
print(get_armstrong(my_list))

result = get_frequency("D:/goc hoc tap/javaScript/mytext.txt")
print(result)                

        