class Queue{
    constructor(){
        this.length = 0;
        this.storage = [];
        this.front = 0;
    }

    enqueue(value){
        this.storage[this.length] = value;
        this.length++;
    }

    dequeue(){
        if(this.length === 0){
            return undefined;
        }
        this.length--;
        var result = this.storage[this.front];
        delete this.storage[this.front];
        this.front++;
        return result;
    }
}

// var myQueue = new Queue();
// console.log(myQueue.length);
// myQueue.enqueue(0);
// myQueue.enqueue(1);
// console.log(myQueue.length);
// myQueue.dequeue();
// console.log(myQueue.length, myQueue.front);
