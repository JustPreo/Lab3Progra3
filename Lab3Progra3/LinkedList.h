#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
template<class T> class LinkedList{
public:
    LinkedList<T>(){
        head = nullptr;
    }

    Node<T>* head;

    void push_back(T value);//Push ultimo elem
    void insert(int pos , T value);//Push en x pos
    bool erase(int pos);//Borar x pos
    Node<T>* at(int pos);//Conseguir elemento en x pos
    int size();//Conseguir el size
    void clear();//Borra la lista
    void print();//Print a la lista
};

template <class T>
void LinkedList<T>::push_back(T value){
    Node<T>* nodeNew= new Node<T>(value);
    //Revisamoos si es nullptr
    if (head == nullptr)
    {
        head = nodeNew;
        std::cout <<"Creo uno nuevo en el head?\n";
        return;
    }
    Node<T>* it = this->head;

    while (it != nullptr){//Va hasta el final de la lista
        it = it->next;
    }
    it = nodeNew;
    std::cout <<"Creo uno nuevo?\n";

}

template <class T>
void LinkedList<T>::insert(int pos,T value){
    if (pos > size() || size()==0){
        return;//Retorna porque no se puede insertar
    }
    Node<T>* nodeReplace = at(pos);
    nodeReplace->value = value;
}

template <class T>//La pos la tienen que poner de 0-size();
bool LinkedList<T>::erase(int pos){
    //Valor null (No hay cosas en la lista)
    if(this->head == nullptr) return false;

    //Remove head
    //Pos == 0 , then delete
    if(pos==0) {
        Node<T>* tmpToDelete = head;
        head = head->next;
        delete tmpToDelete;
        return true;
    }
    //Resto de cosas
    int contador = 0;
    Node<T>* it = this->head;
    while(it != nullptr){

        if(it->next != nullptr && contador == pos) {//

            Node<T>* tmpToDelete = it->next;
            it->next = it->next->next;
            delete tmpToDelete;
            return true;
        }

        it = it->next;
        contador ++;
    }

}

template <class T>
    Node<T>* LinkedList<T>::at(int pos){
    if (pos > size()||size ()==0){
        return nullptr;//Error porque el valor es mas grande o size == 0
    }
    int contador = 0;
    Node<T> *it = head;
    while (it != nullptr){
        if (contador == pos){
            return it;
        }
        contador++;
        it = it->next;
    }
    return nullptr;

}

template <class T>
int LinkedList<T>::size(){
    if (head == nullptr)
    {
        return 0;
    }

    int contador = 0;
    Node<T> *it = head;
    while (it != nullptr){
        it->next;//Ir al ultimo de la lista
        contador++;
    }
    return contador;
}

template <class T>
void LinkedList<T>::clear(){
    int contador = size()-1;
    while (contador != -1)
    {
        delete at(contador);
        contador--;
    }
    head = nullptr;
}
template <class T>
void LinkedList<T>::print(){
    if (size()==0){
        std::cout <<"No hay elementos en la lista pipipi\n";
        return;
    }
    for (int i = 0;i <size();i++)
    {
        std::cout <<"["<<i<<"]"<<at(i)->value<<"\n";
    }
}


#endif // LINKEDLIST_H
