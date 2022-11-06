#include "pila.hpp"
#include <string>

int main(){
    Pila<int> pila1;
    cout<<pila1.isEmpty()<<endl;
    cout<<pila1.pop()<<endl;
    pila1.push(45);
    pila1.push(100);
    pila1.push(12);
    pila1.imprimirPila();
    cout<<"***********"<<endl;
    cout<<pila1.pop()->getValor()<<endl;
    Nodo<int> * aux=pila1.pop();
    cout<<aux->getValor()<<endl;
    cout<<aux->getValor()<<endl;
    cout<<"***********"<<endl;
    pila1.imprimirPila();
    delete aux;

    return 0;
}