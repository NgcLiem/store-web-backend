var course = {
    name: "hit",
    fee: 0
}

var result = course.fee > 0 ? `${course.fee} Coins` : "Mien phi"
console.log(result)

var languages = {
    name: "PHP",
    age: 19
}

for(var value of Object.values(languages))

console.log(value)

// forEach() duyet qua tat ca cac phan tu
// every() tat ca cac phan tu phai thoa man 1 dieu kien nao do -> true
// some() 1 phan tu phai thoa man 1 dieu kien nao do -> true
// find() tra ve 1 phan tu ma thoa man dieu kien
// filter() tra ve list phan tu thoa man dieu kien
// map() tra ve tat ca cac phan tu
// reduce()

var courses = [
    {
        id: 1,
        name: "JS",
        coin: 0
    },
    {
        id: 2,
        name: "Java",
        coin: 100
    },
    {
        id: 3,
        name: "Nodejs",
        coin: 200
    },
    {
        id: 4,
        name: "Python",
        coin: 100
    },
    {
        id: 5,
        name: "Ruby",
        coin: 100
    },
    {
        id: 6,
        name: "Ruby",
        coin: 200
    }
];

var course = courses.filter(function(course, index){
    return course.name === "Ruby";
});

var course = courses.every(function(course, index){
    return course.coin === 0;
});

console.log(course)

function courseHandle(course, index){
    return {
        id: course.id,
        name: `Khoa hoc: ${course.name}`,
        coin: course.coin,
        coinText: `Gia ${course.coin}`,
        index : index,
    };
}

var newCourses = courses.map(courseHandle)

console.log(newCourses)

var i = 0
function coinHandle(accumulator /* gia tri khoi tao */, currentValue/* gia tri hien tai */, currentIndex /* dia chi currentValue*/){
    i++;
    var total = accumulator + currentValue.coin
    return total;
}

var totalCoin = courses.reduce(function(accumulator, currentValue){
    return accumulator + currentValue.coin
}, 0)

console.log(totalCoin)

var listMap = courses.reduce(function(course, courses){
    return course.concat(courses)
}, [])

console.log(listMap)

Array.prototype.map2 = function(callback){
    var output = [], arrayLength = this.length;

    for(var i = 0; i < arrayLength; ++i){
        var result = callback(this[i], i)
        output.push(result)
    }
    return output;
}

var courses1 = ["PHP", "JS", "Python"];

var htmls = courses1.map2(function(course){
    return `<h2>${course}</h2>`
})

console.log(htmls.join(''))
