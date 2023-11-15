//functions: push, pop, peek, length
//JS lets you use an array as a stack

//Finding a palindrome
var letters = []
var word = "racecar"
var r_word = ""

for(var i = 0; i < word.length; i ++){
    letters.push(word[i]);
}

for(var i = 0; i < word.length; i++){
    r_word += letters.pop();
}

if(r_word === word) {
    //console.log("Same")
}
else {
    //console.log("Not same")
}

//Creating a stack
class Stack{
    constructor(){
        this.length = 0;
        this.storage = [];
    }

    push(value){
        this.storage[this.length] = value;
        this.length ++;
    }
    pop(){
        if(length === 0){
            return undefined;
        }
        var result = this.storage[this.length];
        delete this.storage[this.length];
        this.length--;
        return result;
    }
    peek(){
        if(this.length === 0){
            return undefined;
        }
        return this.storage[this.length - 1];
    }
    size(){
        if(this.length === 0){
            return 0
        }
        return this.length;
    }

}

// var myStack = new Stack();
// console.log(myStack.size());
// myStack.push(8);
// console.log(myStack.size());
// console.log(myStack.peek());


