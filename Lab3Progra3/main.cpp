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
    }
    else if (opcion ==2){
        cout <<"Posicion de palabra a eliminar\n";
        cout <<"[0-"<<l.size()-1<<"]\n";
        int num = 0;
        cin >>num;
        l.erase(num);
    }
    else if (opcion ==3){
        cout <<"Posicion de palabra a reemplazar\n";
        cout <<"[0-"<<l.size()-1<<"]\n";
        int num = 0;
        cin >>num;
        string palabra = "";
        cout <<"Palabra a Ingresar\n";
        cin>>palabra;
        l.insert(num,palabra);
    }
    else if (opcion ==4){
        l.print();
    }
    else if (opcion == 5){
        //Funcion de undo!
    }
    else if (opcion == 6)
    {
        //Funcion de Redo!
    }
    else if (opcion != 0){
        cout <<"Opcion Invalida\n";
    }

    }//Fin while







    return a.exec();
}
