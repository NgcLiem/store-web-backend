var User = function (firstName, lastName, avatar){
    this.firstName = firstName;
    this.lastName = lastName;
    this.avatar = avatar;
    
    this.getName = function(){
        return `${this.firstName} ${this.lastName}`
    }
}

var user = new User("Forn", "Gui", "FFF")
var author = new User("Bom", "Jac", "GGG")

user.little = "Dao"
author.comment = "Khoe"

console.log(user)
console.log(author)