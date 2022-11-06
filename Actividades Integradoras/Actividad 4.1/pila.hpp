#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
//Listas

using namespace std;

template <typename T>
class NodoPila{
    //Atributos
    T valor;
    NodoPila<T> * siguiente;
    public:
        //get
        T getValor(){return this->valor;}
        NodoPila<T> * getSiguiente(){return this->siguiente;}
        //set
        void setValor(T valor){this->valor=valor;}
        void setSiguiente(NodoPila<T>* siguiente){this->siguiente=siguiente;}
        //constructor
        NodoPila(T valor,NodoPila<T> * siguiente){
            this->valor=valor;
            this->siguiente=siguiente;
        }
};

template <typename T>
class ListaP{
    //Atributos
    NodoPila<T> * head;
    int tam;
    public:
        //Metodos get y set        
        NodoPila<T> * getHead(){return this->head;}
        int getTam(){return this->tam;}
        void setHead(NodoPila<T> * head){this->head=head;}
        void setTam(int tam){this->tam=tam;}
        //Método constructor
        ListaP(){
            this->head=nullptr;
            this->tam=0;
        }
        //Operaciones de la lista

        //Agregar un nodo al inicio de la lista
        void agregarInicio(T valor){
            NodoPila<T> * nuevo=new NodoPila<T>(valor,this->head); // Creando el nuevo nodo
            this->head=nuevo; //Actualizar la head de la lista
            this->tam++; //Actualizamos el tamaño
        }

        //Agregar un nodo al final de la lista
        void agregarFinal(T valor){
            NodoPila<T> * nuevo=new NodoPila<T>(valor,nullptr);
            if(this->head){//Verificar si la lista esta vacia
                NodoPila<T> * elemento=this->head;
                while(elemento->getSiguiente())
                    elemento=elemento->getSiguiente();
                elemento->setSiguiente(nuevo);                
            }else{
                this->head=nuevo;
            }
            this->tam++;
        }

        //Eliminar un nodo al inicio de la lista
        NodoPila<T> * eliminarInicio(){
            if(this->head){
                NodoPila<T> * eliminado=this->head; //Guardo la direccion del elemento a eliminar
                this->head=this->head->getSiguiente(); //Actualizar el head
                this->tam--;
                return eliminado;
            }
            return nullptr;            
        }

        //Imprimir los nodos de la lista
        void imprimirLista(){
            NodoPila<T> * elemento=this->head;
            while(elemento){
                cout<<elemento->getValor()<<endl;//Cambio
                elemento=elemento->getSiguiente();
            }
            cout<<endl;
        }
};

template <typename T>
class Pila{
    ListaP<T> * pila;
    public:
        void setPila(ListaP<T> * pila){this->pila=pila;}
        ListaP<T> * getPila(){return this->pila;}

        Pila(){
            this->pila=new ListaP<T>();
        }

        ~Pila(){
            delete pila;
        }

        

        //Meter un elemento en la pila
        void push(T valor){
            this->pila->agregarInicio(valor);
        }

        //Dar el elemento en el top
        NodoPila<T> * top(){
            return this->pila->getHead();
        }

        //Regresar si la pila esta vacía
        bool isEmpty(){
            if(this->pila->getHead())
                return false;
            return true;
        }

        NodoPila<T> * pop(){
            return this->pila->eliminarInicio();
        }

        void imprimirPila(){
            this->pila->imprimirLista();
        }

};

#endif