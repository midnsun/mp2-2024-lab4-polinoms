#include "myVector.h"
#pragma once

template <typename T>
class myStack : protected myVector<T> {
private:
    using myVector<T>::sizevar;
public:
    using myVector<T>::size;
    myStack() : myVector<T>() {} 
    myStack(const myStack& st) : myVector(*dynamic_cast<const myVector*>(&st)) {}
    myStack(myStack&& st) : myVector(*dynamic_cast<myVector*>(&st)) {}
    myStack& operator=(const myStack& st) {
        this->myVector<T>::operator=(*dynamic_cast<const myVector*>(&st));
        return *this;
    }
    myStack& operator=(myStack&& st) {
        this->myVector<T>::operator=(*dynamic_cast<myVector*>(&st));
        return *this;
    }
    bool isEmpty() const { return sizevar == 0; }
    void push(const T& v) {
        this->myVector<T>::push_back(v);
    }
    const T& pop() {;
        return this->myVector<T>::operator[](--this->myVector<T>::sizevar);
    }
    T& top() {
        return this->myVector<T>::operator[](this->myVector<T>::sizevar - 1);
    }
    void clear() {
        this->myVector<T>::resize(0);
    }
};