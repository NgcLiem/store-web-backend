class Movie:
    def __init__(self, title, director, actor, year, rating):
        self.title = title
        self.director = director
        self.actor = actor
        self.year = year
        self.rating = rating
        
    def read(self):  
        soLuongDaoDien = len(self.director) if isinstance(self.director, list) else 1
        soLuongDienVien = len(self.actor)  if isinstance(self.actor, list) else 1  
        return f"So luong dao dien: {soLuongDaoDien}\nSo luong dien vien: {soLuongDienVien}"
        
    def __str__(self):
        return f"{self.title} san xuat nam {self.year} co diem danh gia la {self.rating}"   

movie = Movie(
    "Những thiên thần của Charlie's Angels",
    "Elizabeth Banks",
    ["Kristen Stewart", "Naomi Scott", "Ella Balinska"],
    2019,
    4.5)

movie2 = Movie(
    "Train to Busan",
    ["Alexander Issac", "Alexander Arnold"],
    ["Atus", "Ali"],
    2020,
    4.2
)

# print(movie.__dict__)
print(movie.read())
print(movie)
print(movie2.read())
print(movie2)
# print('%s' %movie)  
# print('%r' %movie)     