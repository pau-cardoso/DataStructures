/**
 * @file Queue.hpp
 * @brief Implementacion de la clase Queue
 * @authors 
 * Paulina Cardoso Fuentes  - A01701490,
 * María Fernanda Hernández Montes  - A01704918,
 * Paola Adriana Millares Forno - A01705674
 * @date 03/02/2021
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

using namespace std;

template <typename T>
class Nodo {
    //Atributos
    T valor;
    Nodo * siguiente;
    public:
    //Metodos
    T getValor(){return this->valor;}
    void setValor(T valor){this->valor=valor;}
    Nodo<T> * getSiguiente(){return this->siguiente;}
    void setSiguiente(Nodo<T> * siguiente){this->siguiente=siguiente;}
    //Constructores
    Nodo(T valor,Nodo<T> * siguiente){
        this->valor=valor;
        this->siguiente=siguiente;
    }
};

template <typename T>
class ListaCircular{
    Nodo<T> * last;
    int tam;
    public:
        // Constructor
        ListaCircular();
        // Setters y getters
        int getTam(){return this->tam;}
        void setTam(int tam){this->tam=tam;}
        Nodo<T> * getLast(){return this->last;}
        void setHead(Nodo<T> * last){this->last=last;}
        // Otros metodos
        void agregarInicio(T valor);
        void agregarFinal(T valor);
        Nodo<T> * eliminarInicio();
        void imprimirLista();
        void imprimirLista2();
};

//=====================================================================
//
//  Método: ListaCircular
//  Descripcíón: Constructor.
//  Complejidad: O(1)
//
//=====================================================================
template <typename T>
ListaCircular<T> :: ListaCircular(){
    this->last=nullptr;
    this->tam=0;
}

//=====================================================================
//
//  Método: agregarInicio
//  Descripcíón: Agrega un inicio a la lista circular
//  Complejidad: O(1)
//
//=====================================================================
template <typename T>
void ListaCircular<T> :: agregarInicio(T valor) {
    //Lista con nodos
    if(this->last){
            //this->last->getSiguiente()  es el head (primer nodo)
            Nodo<T> * nuevo= new Nodo<T>(valor,this->last->getSiguiente());
            //ACtualizamos el apuntador del último nodo ahora conectado con el nuevo nodo
            this->last->setSiguiente(nuevo);
    }else{ //Lista sin nodos (vacia)
        Nodo<T> * nuevo=new Nodo<T>(valor,nullptr); //Crear nodo
        nuevo->setSiguiente(nuevo); //Como solo hay un nodo el apuntador siguiente es asi mismo
        this->last=nuevo;
    }
    this->tam++;
}

//=====================================================================
//
//  Método: agregarFinal
//  Descripcíón: Agrega un nodo al final de la lista
//  Complejidad: O(1)
//
//=====================================================================
//Agregar al final O(1)
template <typename T>
void ListaCircular<T> :: agregarFinal(T valor) {
    if(this->last){ //Lista con elementos
        //Creamos el nuevo nodo apuntado al que era el nodo inicial
        Nodo<T> * nuevo=new Nodo<T>(valor,this->last->getSiguiente());
        //Actualizamos el siguiente del último nodo con el nuevo nodo
        this->last->setSiguiente(nuevo);
        //Actualizamos el apuntador del último al nuevo nodo
        this->last=nuevo;
    }else{ //Lista Vacía
        Nodo<T> * nuevo=new Nodo<T>(valor,nullptr); // Creando el nuevo nodo
        nuevo->setSiguiente(nuevo); // Como solo hay un nodo el apuntador siguiente será asi mismo
        this->last=nuevo; // El nuevo nodo será el último y el primero al mismo tiempo
    }            
    this->tam++; //Actualizamos el tamaño
}

//=====================================================================
//
//  Método: eliminarInicio
//  Descripcíón: Elimina el valor que se encuentre en el inicio de la
//               lista
//  Complejidad: O(1)
//
//=====================================================================
template <typename T>
Nodo<T> * ListaCircular<T> :: eliminarInicio(){
    if(this->last){
        Nodo<T> * actual=this->last->getSiguiente();
        if(this->tam==1)
            this->last=nullptr;
        else
            this->last->setSiguiente(actual->getSiguiente());
        this->tam--;
        return actual;
    }
    return nullptr;
}

//=====================================================================
//
//  Método: imprimirLista
//  Descripcíón: Imprime los elementos que se encuentran en la lista
//  Complejidad: O(n)
//
//=====================================================================
template <typename T>
void ListaCircular<T> :: imprimirLista() {
    if(this->last){
        Nodo<T> * actual=this->last->getSiguiente();
        do{
            cout<<actual->getValor()<<" "; //Imprimir el valor contenido en el nodo
            actual=actual->getSiguiente(); //Recorrer el apuntador actual al siguiente nodo
        }while (actual!=this->last->getSiguiente()); 
        cout<<endl;                            
    }else{
        cout<<"Lista Circular vacía"<<endl;
    }
}

//=====================================================================
//
//  Método: imprimirLista
//  Descripcíón: Imprime los elementos que se encuentran en la lista
//  Complejidad: O(n)
//
//=====================================================================
template <typename T>
void ListaCircular<T> :: imprimirLista2(){
    if(this->last){
        Nodo<T> * actual=this->last->getSiguiente();
        do{
            cout<<*actual->getValor()<<" "; //Imprimir el valor contenido en el nodo
            actual=actual->getSiguiente(); //Recorrer el apuntador actual al siguiente nodo
        }while (actual!=this->last->getSiguiente()); 
        cout<<endl;                            
    }else{
        cout<<"Lista Circular vacía"<<endl;
    }
}



template <typename T>
class Queue {
    ListaCircular<T> * queue;
    public:

        //=====================================================================
        //
        //  Método: Queue
        //  Descripcíón: Constructor
        //  Complejidad: O(1)
        //
        //=====================================================================
        Queue(){
            this->queue=new ListaCircular<T>();
        }

        //=====================================================================
        //
        //  Método: push
        //  Descripcíón: añade un valor al final de la lista
        //  Complejidad: O(1)
        //
        //=====================================================================
        void push(T valor){
            this->queue->agregarFinal(valor);
        }

        //=====================================================================
        //
        //  Método: push
        //  Descripcíón: Elimina el elemento del inicio de la lista
        //  Complejidad: O(n)
        //
        //=====================================================================
        T pop(){
            return this->queue->eliminarInicio()->getValor();
        }

        //=====================================================================
        //
        //  Método: front
        //  Descripcíón: nos dice el valor que sigue en la lista
        //  Complejidad: O(1)
        //
        //=====================================================================
        Nodo<T> * front(){
            if(this->queue->getLast())
                return this->queue->getLast()->getSiguiente();
            return nullptr;
        }
        //Heap *
        void imprimirQueueHeap(){
            this->queue->imprimirLista2();                         
        }

        //Stack 
        void imprimirQueueStack(){
            this->queue->imprimirLista();
        }
};

#endif