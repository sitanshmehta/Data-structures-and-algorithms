#include "doubly-linked-list.h"



DoublyLinkedList::Node::Node(DataType data) {
    value = data;
    next = nullptr;
    prev = nullptr;
}


DoublyLinkedList::DoublyLinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}


DoublyLinkedList::~DoublyLinkedList() {
    Node* ptr = head_;
    while(head_ != nullptr){
        ptr = head_;
        head_ = head_->next;
        delete ptr;
    }

}


unsigned int DoublyLinkedList::size() const {
    return size_;
}


unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}


bool DoublyLinkedList::empty() const {
    return (size_ == 0);
}


bool DoublyLinkedList::full() const {
    return (size_ == CAPACITY);
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if(empty() || index > size_){
        return 0;
    }
    else if(index >= 0 && index <= size_){
        Node* node = getNode(index);
        if(node == NULL || node == nullptr){
            return 0;
        }
        else return node->value;
    }
    else{
        Node* node = getNode(size_ - 1);
        return node->value;
    }
}


unsigned int DoublyLinkedList::search(DataType value) const {
    Node* curr = head_;
    unsigned int count = 0;
    while(curr->next != nullptr && count <= size_){
        curr = curr->next;
        count++;
        if(curr->value == value){
            return count;
        }
    }
    return size_;
}


void DoublyLinkedList::print() const {
    Node* curr = head_;
    if(empty()){
        std::cout << "Empty" << std::endl;
    }
    while(curr != nullptr){
        std::cout << curr->value << std::endl;
        curr = curr->next;
    }
    std::cout << " End" << std::endl;
}


DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    int count = 0;
    Node* curr = head_;
    if(empty() && index >= size_){
        return nullptr;
    }
    else if(index >= 0 && index < size_){
        while(count < index && curr != nullptr){
            curr = curr->next;
            count++;
        }
        return curr;
    }
    return nullptr;
}


bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    //insert at the front, middle, and end
    if((index >= 0 && index <= size_)|| empty()){
        Node* newNode = new Node(value);
        if(empty()) {
            head_ = newNode;
            tail_ = newNode;
        }
        else if(index == 0){
            newNode->next = head_;
            head_->prev = newNode;
            newNode->prev = nullptr;
            head_ = newNode;
        }
        else if(index == size_){
            tail_->next = newNode;
            newNode->prev = tail_;
            tail_ = newNode;
            newNode->next = nullptr;

            /*Node* temp = getNode(index);
            temp->next = newNode;
            newNode->prev = temp;
            tail_ = newNode;*/
        }
        else{
            /*Node* temp = getNode(index);
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next->prev = newNode;*/

            Node* temp = getNode(index);
            newNode->next = temp;
            temp->prev->next = newNode;
            newNode->prev = temp->prev;
            temp->prev = newNode;
        }
        size_++;
        return true;
    }
    return false;
}


bool DoublyLinkedList::insert_front(DataType value) {
    unsigned int front = 0;
    return insert(value, front);
}


bool DoublyLinkedList::insert_back(DataType value) {
    unsigned int back = size_;
    return insert(value, back);
}


bool DoublyLinkedList::remove(unsigned int index) {
    if(empty() || index >= size_){
        return false;
    }
    else if(index >= 0 && index < size_){
        Node* node = getNode(index);
        if(size_ == 1){
            head_ = nullptr;
            tail_ = nullptr;
        }
        else if(index == 0){
            head_ = node->next;
            node->next->prev = head_;
            node->next = nullptr;
            node->prev = nullptr;
        }
        else if(index == size_ - 1){
            /*Node* temp = getNode(index - 1);
            tail_->prev = temp->prev;
            temp->prev->next = nullptr;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;*/

            tail_ = node->prev;
            node->prev->next = nullptr;
        }
        else{
            node->next->prev = node->prev;
            node->prev->next = node->next;
            node->next = nullptr;
            node->prev = nullptr;
        }
        size_--;
        delete node;
        return true;
    }
    return false;
}


bool DoublyLinkedList::remove_front() {
    unsigned int front = 0;
    return remove(front);
}


bool DoublyLinkedList::remove_back() {
    if(!empty()){
        unsigned int back = size_ - 1;
        return remove(back);
    }
    return false;
}


bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if(empty() || index > size_){
        return false;
    }
    else if(index >= 0 && index <= size_){
        bool removed = remove(index);
        bool added = insert(value, index);
        return (added && removed);
    }
    return false;
}
