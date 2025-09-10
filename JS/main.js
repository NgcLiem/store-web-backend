var languages = [
    'Javascrips',
    'PHP',
    'Java',
    'Python'
];

var languages2 = [
    'Dart',
    'Ruby'
]

console.log(languages.slice(-2, -1))

function show() {
    var myString = '';
    for(var param of arguments){
        myString += `${param} - `;
    }
    console.log(myString)
}

show('log 1', 'log 2');

/*
1. toString
2. join: bien tu array thanh 1 chuoi
3. pop: xoá element "cuối" mảng và trả về phần tử đã xoá
4. push: thêm 1 hoặc nhiều element vào "cuối mảng", trả về số lượng
5. shift: xoá element "đầu" mảng và trả về phần tử đã xoá
6. unshift: thêm 1 hoặc nhiều element vào "đầu" mảng, trả về số lượng
7. splicing: xoá và chèn (a,b,c) // a: địa chỉ chèn, b: số lượng, c: kí tự thêm vào
8. concat: nối array 
9. slicing: cắt array (a,b)
*/