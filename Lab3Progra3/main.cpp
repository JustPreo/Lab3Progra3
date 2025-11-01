#include "LinkedList.h"
#include "Operation.h"
#include "Stack.h"
#include "node.h"
#include <QCoreApplication>
#include <string>
#include <iostream>//Lo dejo porque despues lo usare
using std::cout;
using std::cin;
using std::string;
int main(int argc, char *argv[])
{





    QCoreApplication a(argc, argv);
    LinkedList<string> l;
    Stack<Operation> UndoS;
    Stack<Operation> RedoS;
    int opcion = 1;
    while (opcion != 0){
    cout<<"=== Mini Editor ===\n";
    cout <<"1) Insertar palabra\n";
    cout <<"2) Eliminar palabra\n";
    cout <<"3) Reemplazar palabra\n";
    cout <<"4) Mostrar documento\n";
    cout <<"5) Deshacer (Undo)\n";
    cout <<"6) Rehacer (Redo)\n";
    cout <<"0) Salir\n";
    cout <<"Selecciona opcion:\n";
    cin >>opcion;
    if (opcion == 1){
        string palabra = "";
        cout <<"Palabra a Ingresar\n";
        cin>>palabra;
        l.push_back(palabra);

        Operation op("", palabra, OpType::INSERT, l.size()-1);//Funcion tipo insert
        UndoS.push(op);
    }
    else if (opcion ==2){
        cout <<"Posicion de palabra a eliminar\n";
        cout <<"[0-"<<l.size()-1<<"]\n";
        int num = 0;
        cin >>num;

        Node<string>* nodeToDelete = l.at(num);
        if (nodeToDelete) {
            Operation op(nodeToDelete->value, "", OpType::DELETE, num);//Tipo delete
            UndoS.push(op);
            l.erase(num);
            RedoS = Stack<Operation>();
        }
    }
    else if (opcion ==3){
        cout <<"Posicion de palabra a reemplazar\n";
        cout <<"[0-"<<l.size()-1<<"]\n";
        int num = 0;
        cin >>num;
        string palabra = "";
        cout <<"Palabra a Ingresar\n";
        cin>>palabra;

        Node<string>* node = l.at(num);
        if (node) {
            Operation op(node->value, palabra, OpType::REPLACE, num);//Tipo replkace
            UndoS.push(op);
            l.insert(num, palabra);
            RedoS = Stack<Operation>();
        }
    }
    else if (opcion ==4){
        l.print();
    }
    else if (opcion == 5){
        // Undo
        Operation op = UndoS.pop();
    //TIPO INSERT
        if (op.type == OpType::INSERT) {
            l.erase(op.pos);
            Operation redoOp("", op.newValue, OpType::INSERT, op.pos);
            RedoS.push(redoOp);
        }
        //TIPO DELETE
        else if (op.type == OpType::DELETE) {
            l.insert(op.pos, op.oldValue);
            Operation redoOp(op.oldValue, "", OpType::DELETE, op.pos);
            RedoS.push(redoOp);
        }
        //TIPO DELETE
        else if (op.type == OpType::REPLACE) {
            l.insert(op.pos, op.oldValue);
            Operation redoOp(op.oldValue, op.newValue, OpType::REPLACE, op.pos);
            RedoS.push(redoOp);
        }
    }
    else if (opcion == 6)
    {
        //Funcion de Redo
        Operation op = RedoS.pop();

        if (op.type == OpType::INSERT) {
            l.insert(op.pos, op.newValue);
            UndoS.push(op);
        }
        else if (op.type == OpType::DELETE) {
            l.erase(op.pos);
            UndoS.push(op);
        }
        else if (op.type == OpType::REPLACE) {
            l.insert(op.pos, op.newValue);
            UndoS.push(op);
        }
    }
    else if (opcion != 0){
        cout <<"Opcion Invalida\n";
    }

    }//Fin while







    return a.exec();
}
