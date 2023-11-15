#include "sequential-list.h"

SequentialList::SequentialList(unsigned int cap) {
    capacity_ = cap;
    size_ = 0;
    data_ =  new DataType[capacity_];
}


SequentialList::~SequentialList() {
    delete data_;
}


unsigned int SequentialList::size() const {
    return size_;
}


unsigned int SequentialList::capacity() const {
    return capacity_;
}


bool SequentialList::empty() const {
    return (size() == 0);
}


bool SequentialList::full() const {
    return (size() == capacity());
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    if(index >= 0 && index < capacity_){
        DataType val = data_[index];
        return val;
    }
    else return data_[size_];
}


unsigned int SequentialList::search(DataType val) const {
    for(int i = 0; i < size_; i++) {
        if (data_[i] == val) {
            return i;
        }
    }
    return size_;
}


void SequentialList::print() const {
    for(int i = 0; i < capacity_; i ++){
        std::cout << data_[i] << std::endl;
    }
}


bool SequentialList::insert(DataType val, unsigned int index) {
    if(!full() && (index >= 0 && index <= size_)){
            for(unsigned int i = size_; i > index; i --){
                data_[i] = data_[i - 1];
            }
            data_[index] = val;
            size_++;
            return true;
    }
    else return false;
}


bool SequentialList::insert_front(DataType val) {
   unsigned int front = 0;
   return insert(val, front);
}


bool SequentialList::insert_back(DataType val) {
    unsigned int back = size_;
    return insert(val, back);
}


bool SequentialList::remove(unsigned int index) {
    if(index >= 0 && index < size_){ //if index is valid
        //size_--;
        for(int i = index; i < size_ - 1; i++){
            data_[i - 1] = data_[i];
        }
        size_--;
        //print();
        return true;
    }
    return false;

}


bool SequentialList::remove_front() {
    unsigned int front = 0;
    return remove(front);
}


bool SequentialList::remove_back() {
    if(!empty()){
        unsigned int back = 0;
        return remove(back);
    }
    return false;
}


bool SequentialList::replace(unsigned int index, DataType val) {
    if(!(index >= 0) && !(index <= capacity_)){ //if index is invalid
        return false;
    }
    else{
        data_[index] = val;
        return true;
    }
}
