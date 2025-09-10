list = [4, 2, 9, 1, 5, 6]

# 1. Đếm độ dài danh sách
count = 0
for i in list:
    count += 1
print("Độ dài danh sách:", count)

# 2. Tính tổng các phần tử trong danh sách
total = 0
for num in list:
    total += num
print("Tổng các phần tử:", total)

# 3. Sắp xếp danh sách từ bé đến lớn
n = count 
list1 = list[:] 
for i in range(n - 1):
    for j in range(n - 1 - i):
        if list1[j] > list1[j + 1]:
            list1[j], list1[j + 1] = list1[j + 1], list1[j]
print("Sắp xếp từ bé đến lớn:", list1)

# 4. Sắp xếp danh sách từ lớn đến bé 
list2 = list[:]
for i in range(n - 1):
    for j in range(n - 1 - i):
        if list2[j] < list2[j + 1]:
            list2[j], list2[j + 1] = list2[j + 1], list2[j]
print("Sắp xếp từ lớn đến bé:", list2)

# 5. Tìm số nhỏ nhất
min_value = list[0]
for i in list:
    if i < min_value:
        min_value = i
print("Số nhỏ nhất:", min_value)

# 6. Tìm số lớn nhất
max_value = list[0]
for i in list:
    if i > max_value:
        max_value = i
print("Số lớn nhất:", max_value)
