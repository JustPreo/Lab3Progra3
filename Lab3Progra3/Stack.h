#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 200

#include <iostream>
using std::cout;

template <typename T>
class Stack {
private:
    int size;
    T data[STACK_SIZE];


public:
    void push(T newValue); // inserta en el tope
    T pop(); // eliminar y retornar
    Stack(){
        size = 0;
    }
};

template <typename T>
void Stack<T>::push(T newValue) {
    data[size] = newValue;
    size ++;
    return;
}

template <typename T>
T Stack<T>::pop() {
    if(size == 0) return -1;
    T toReturn =  data[size - 1];
    size = size - 1;
    return toReturn;
}


#endif // STACK_H
