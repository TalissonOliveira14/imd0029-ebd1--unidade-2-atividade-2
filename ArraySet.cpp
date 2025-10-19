#include "Set.hpp"
#include <string>

Set::Set(){
    this->capacity = CAPACITY_DEFAULT;
    array = new std::string[this->capacity];
    this->quantity = 0;
}

Set::Set(int initialCapacity){
    this->capacity = initialCapacity;
    array = new std::string[this->capacity];
    this->quantity = 0;
}

Set::~Set(){
    delete [] array;
}

void Set::resize() {
    int newCapacity = capacity * 2;
    std::string *newArray = new std::string[newCapacity];
    
    for (int i = 0; i < quantity; i++) {
        newArray[i] = array[i];
    }
    
    delete [] array;
    array = newArray;
    capacity = newCapacity;
}

bool Set::add(std::string s){
    if (contains(s)) {
        return false;
    }
    
    if (quantity >= capacity) {
        resize();
    }
    
    array[quantity] = s;
    quantity++;
    return true;
}

bool Set::contains(std::string s){
    for( int i = 0; i < this->quantity; ++i ){
        if( array[i] == s ){
            return true;
        }
    }
    return false;
}

bool Set::remove(std::string s){
    for (int i = 0; i < quantity; i++) {
        if (array[i] == s) {
            for (int j = i; j < quantity - 1; j++) {
                array[j] = array[j + 1];
            }
            quantity--;
            return true;
        }
    }
    return false;
}

void Set::clear(){
    quantity = 0;
}

int Set::size(){
    return this->quantity;
}

bool Set::isEmpty(){
    return this->quantity == 0;
}