#ifndef NODE_H
#define NODE_H

template <class T> struct Node{
    public:
    Node<T>(T value){
        this->value = value;
        next = nullptr;
    }
        Node* next;
        T value;
};



#endif // NODE_H
