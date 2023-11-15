class PQueue{
    constructor(){
        this.length = 0;
        this.storage = [];
        this.front = 0;
    }

    enqueue(value, priority){
        var insertIndex = this.front;
        while(insertIndex < this.length && priority <= this.storage[insertIndex].priority){
            insertIndex++;
        }
        this.storage.splice(insertIndex, 0, {value, priority}); 
        this.length ++;
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

var myPQueue = new PQueue;
console.log(myPQueue.length);
myPQueue.enqueue(0,0);
myPQueue.enqueue(1,1);
myPQueue.enqueue(2,1);



//ARRAY.SPLICE takes three values. The index where you want to replace the values, the number of values you are adding, and the values you are adding
// const months = ['Jan', 'March', 'April', 'June'];
// months.splice(1, 0, 'Feb');
// Inserts at index 1
// console.log(months);
// Expected output: Array ["Jan", "Feb", "March", "April", "June"]

// months.splice(4, 1, 'May');
// Replaces 1 element at index 4
// console.log(months);
// Expected output: Array ["Jan", "Feb", "March", "April", "May"]