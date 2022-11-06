#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <vector>
#include "pila.hpp"
//Listas

using namespace std;



template <typename T>
class NodoG{
    //Atributos
    T valor;
    NodoG<T> * siguiente;
    public:
        //get
        T getValor(){return this->valor;}
        NodoG<T> * getSiguiente(){return this->siguiente;}
        //set
        void setValor(T valor){this->valor=valor;}
        void setSiguiente(NodoG<T>* siguiente){this->siguiente=siguiente;}
        //constructor
        NodoG(T valor,NodoG<T> * siguiente){
            this->valor=valor;
            this->siguiente=siguiente;
        }
};

template <typename T>
class ListaG{
    //Atributos
    NodoG<T> * head;
    int tam;
    public:
        //Metodos get y set        
        NodoG<T> * getHead(){return this->head;}
        int getTam(){return this->tam;}
        void setHead(NodoG<T> * head){this->head=head;}
        void setTam(int tam){this->tam=tam;}
        //Método constructor
        ListaG(){
            this->head=nullptr;
            this->tam=0;
        }
        //Operaciones de la lista

        //Agregar un nodo al inicio de la lista
        void agregarInicio(T valor){
            NodoG<T> * nuevo=new NodoG<T>(valor,this->head); // Creando el nuevo nodo
            this->head=nuevo; //Actualizar la head de la lista
            this->tam++; //Actualizamos el tamaño
        }

        //Agregar un nodo al final de la lista
        void agregarFinal(T valor){
            NodoG<T> * nuevo=new NodoG<T>(valor,nullptr);
            if(this->head){//Verificar si la lista esta vacia
                NodoG<T> * actual=this->head;
                while(actual->getSiguiente())
                    actual=actual->getSiguiente();
                actual->setSiguiente(nuevo);                
            }else{
                this->head=nuevo;
            }
            this->tam++;
        }
        
        //Imprimir los nodos de la lista
        void imprimirLista(){
            NodoG<T> * actual=this->head;
            while(actual){
                cout<<actual->getValor()<<endl;
                actual=actual->getSiguiente();
            }
            cout<<endl;
        }

        //Eliminar un nodo al inicio de la lista
        NodoG<T> * eliminarInicio(){
            if(this->tam==0)
                return nullptr;
            NodoG<T> * eliminado=this->head;
            this->head=this->head->getSiguiente();
            this->tam--;
            return eliminado;
        }

};

template <typename T>
class ListaCS{
    //Atributos
    NodoG<T> * last;
    int tam;
    public:
        //Metodos
        NodoG<T> * getLast(){return this->last;}
        int getTam(){return this->tam;}
        void setLast(NodoG<T> * last){this->last=last;}
        void setTam(int tam){this->tam=tam;}

        //Método constructor
        ListaCS(){
            this->last=nullptr;
            this->tam=0;
        }

        //Método destructor
        ~ListaCS(){
            this->eliminarTodos();
        }

        void agregar(T valor){
                //Creamos el nuevo nodo sin apuntar a ningun elemento
                NodoG<T> * nuevo=new NodoG<T>(valor,nullptr); 
                //Hacemos que el nuevo nodo apunte así mismo
                nuevo->setSiguiente(nuevo);
                //Establecemos el nuevo nodo como último dado que solo hay uno en nuestra lista
                this->last=nuevo;            
        }

        void agregarInicio(T valor){
            if(this->last){//Agregar al inicio si la lista no esta vacía
                //Creamos el nuevo nodo y lo conectamos con el que era el primer nodo
                NodoG<T> * nuevo=new NodoG<T>(valor,this->last->getSiguiente()); 
                //Actualizamos el apuntador del último nodo ahora conectado con el nuevo node    
                this->last->setSiguiente(nuevo); 
            }else{ //Agregar al inicio si la lista esta vacía
                this->agregar(valor);
            }
            this->tam++; //Actualizamos el tamaño
        }

        void agregarFinal(T valor){
            if(this->last){ //ListaG con elementos
                //Creamos el nuevo nodo apuntado al que era el nodo inicial
                NodoG<T> * nuevo=new NodoG<T>(valor,this->last->getSiguiente());
                //Actualizamos el siguiente del último nodo con el nuevo nodo
                this->last->setSiguiente(nuevo);
                //Actualizamos el apuntador del último al nuevo nodo
                this->last=nuevo;
            }else{ //ListaG Vacía
                this->agregar(valor);
            }            
            this->tam++; //Actualizamos el tamaño
        }
        //Heap
        void imprimirLista(){            
            if(this->last){
                NodoG<T> * elemento=this->last->getSiguiente();
                do{
                    cout<<*elemento->getValor()<<" ";
                    elemento=elemento->getSiguiente();
                }while(elemento!=this->last->getSiguiente());
                
            }
            cout<<endl;            
        }
        //Stack
        void imprimirLista2(){            
            if(this->last){
                NodoG<T> * elemento=this->last->getSiguiente();
                do{
                    cout<<elemento->getValor()<<" ";
                    elemento=elemento->getSiguiente();
                }while(elemento!=this->last->getSiguiente());
                
            }
            cout<<endl;            
        }

        void eliminarTodos(){
            if(this->tam!=0){
                NodoG<T> * elementoEliminar;
                NodoG<T> * elementoTransicion=this->last->getSiguiente();
                while(elementoTransicion!=this->last){
                    elementoEliminar=elementoTransicion;
                    elementoTransicion=elementoEliminar->getSiguiente();
                    delete elementoEliminar->getValor();
                    delete elementoEliminar;
                }
                delete this->last->getValor();
                delete this->last;
                this->last=nullptr;
                this->tam=0;
            }            
        }

        NodoG<T> * eliminarInicio(){
            if(this->tam==0)
                return nullptr;
            NodoG<T> * eliminado= this->last->getSiguiente();
            if(this->tam==1)
                this->last=nullptr;
            else
                this->last->setSiguiente(eliminado->getSiguiente());
            
            this->tam--;
            return eliminado;
        }
};

template <typename T>
class Queue{
    ListaCS<T> * queue;
    public:
        Queue(){
            this->queue=new ListaCS<T>();
        }
        void push(T valor){
            this->queue->agregarFinal(valor);
        }
        NodoG<T> * pop(){
            return this->queue->eliminarInicio();
        }

        NodoG<T> * front(){
            if(this->queue->getTam()!=0)
                return this->queue->getLast()->getSiguiente();
            else
                return nullptr;
        }
        //Heap *
        void imprimirQueue1(){
            this->queue->imprimirLista();              
        }

        //Stack 
        void imprimirQueue2(){
            this->queue->imprimirLista2();
        } 

};

//Clase que representa los arcos de un grafo asociado a un nodo especifico
template <typename T>
class Arco{
    T valor;  //valor que almacena el valor del nodo destino
    int peso; //atributo para almacenar el peso asociado al arco si es un grafo no ponderado colocar 1

    public:
        T getValor(){return this->valor;}
        int getPeso(){return this->peso;}
        void setValor(T valor){this->valor=valor;}
        void setPeso(int peso){this->peso=peso;}
        Arco(T valor, int peso){
            this->valor=valor;
            this->peso=peso;
        }
};

//Clase que representa los nodos que pertenecen al grafo
template <typename T>
class NodoGrafo{
    T valor;
    ListaG<Arco<T> *> * arcos;
    public:
        T getValor(){return this->valor;}
        ListaG<Arco<T> *> * getArcos(){return this->arcos;}
        void setValor(T valor){this->valor=valor;}
        void setArcos(ListaG<Arco<T> *> * arcos){this->arcos=arcos;}
        NodoGrafo(T valor){
            this->valor=valor;
            this->arcos=new ListaG<Arco<T>*>();
        }
};




template <typename T>
class Grafo{
    int numNodos;
    ListaG<NodoGrafo<T> *> * nodos;

    public:
        Grafo(){
            this->numNodos=0;
            this->nodos=new ListaG<NodoGrafo<T>*>();
        }

        void insertarNodoGrafo(T valor){
            //Si el nodo no existe
            if(!this->buscarNodo(valor)){
                this->nodos->agregarInicio(new NodoGrafo<T>(valor));
                this->numNodos++;
            }else //Si el nodo existe
                cout<<"NodoG ya existente"<<endl;
        }

        NodoGrafo<T> * buscarNodo(T valor){
            NodoG<NodoGrafo<T> *> * actual=this->nodos->getHead();
            while(actual){
                if(actual->getValor()->getValor()==valor) //NodoGrafo->getValor)
                    return actual->getValor();
                actual=actual->getSiguiente();
            }
            return nullptr;
        }

        //Método para agregar arcos
        void agregarArco(T valorNodoOrigen, T valorNodoDestino,int peso){
            //Validar que tanto el nodo origen como destino se encuentre en la lista de nodos del grafo
            NodoGrafo<T> * origen= this->buscarNodo(valorNodoOrigen);
            NodoGrafo<T> * destino= this->buscarNodo(valorNodoDestino);
            if(origen&&destino)
                //Agregar a la lista de conexiones del nodo origen el nodo destino
                origen->getArcos()->agregarInicio(new Arco<T>(destino->getValor(),peso));
            else
                cout<<"Ambos nodos tanto origen como destino deben existir dentro de lista"<<endl;
        }

        //Método para imprimir la lista de adyacencias
        void imprimirGrafo(){
            NodoG<NodoGrafo<T> *> * actual=this->nodos->getHead();
            while(actual){
                cout<<"NodoG:"<<actual->getValor()->getValor();
                NodoG<Arco<T> *> * auxiliar= actual->getValor()->getArcos()->getHead();
                while(auxiliar){
                    cout<<" -> "<<auxiliar->getValor()->getValor()<<":"<<auxiliar->getValor()->getPeso();
                    auxiliar=auxiliar->getSiguiente();
                }
                cout<<endl;
                actual=actual->getSiguiente();
            }
            cout<<endl;
        }

        NodoGrafo<T> * buscarId(int id){
            if(id>=0&&this->numNodos>id){
                int aux=0;
                NodoG<NodoGrafo<T> *> * actual=this->nodos->getHead();
                while(aux!=id){
                    actual=actual->getSiguiente();
                    aux++;
                }
                return actual->getValor();
            }
            return nullptr;
        }

        int buscarPosicion(T valor){
            int pos=0;
            NodoG<NodoGrafo<T> *> * actual= this->nodos->getHead();
            while(actual){
                if(actual->getValor()->getValor()==valor)
                    return pos;
                actual=actual->getSiguiente();
                pos++;        
            }
            return -1;
        }

        void BreadthFirst(int id){
            vector<bool> estados(this->numNodos,false); //Generar un vector de estados por cada nodo del grafo
            //Crear la queue de control
            Queue<NodoGrafo<T> *> * queue = new Queue<NodoGrafo<T>*>();
            estados[id]=true;
            queue->push(this->buscarId(id));
            while(queue->front()){
                NodoGrafo<T> * nodografo=queue->pop()->getValor();
                //Imprimir la información del nodografo
                cout<<nodografo->getValor()<<" ";
                //ListaG de arcos del nodografo
                NodoG<Arco<T> *> *actual=nodografo->getArcos()->getHead();
                while(actual){
                    int id_aux=this->buscarPosicion(actual->getValor()->getValor());
                    if(!estados[id_aux]){
                        estados[id_aux]=true;
                        queue->push(this->buscarId(id_aux));//Agregar los vecinos del nodo procesado siempre y cuando no hayan sido ingresados a la queue
                    }
                    actual=actual->getSiguiente();
                }
            }
            cout<<endl;
        }

        void DepthFirst(int id) {
            vector<bool> estados(this->numNodos,false); //Generar un vector de estados por cada nodo del grafo
            //Crear la pila de control
            Pila<NodoGrafo<T> *> * stack = new Pila<NodoGrafo<T>*>();

            stack->push(this->buscarId(id));
            while(stack->top()){
                NodoGrafo<T> * nodoGrafo=stack->pop()->getValor();
                //Imprimir la información del nodografo
                if( !estados[this->buscarPosicion(nodoGrafo->getValor())] ){
                    cout<<nodoGrafo->getValor()<<" ";
                    estados[this->buscarPosicion(nodoGrafo->getValor())] = true;
                }
                //ListaG de arcos del nodoGrafo
                NodoG<Arco<T> *> *actual=nodoGrafo->getArcos()->getHead();
                while(actual){
                    int id_aux=this->buscarPosicion(actual->getValor()->getValor());
                    if(!estados[id_aux]){
                        stack->push(this->buscarId(id_aux));//Agregar los vecinos del nodo procesado siempre y cuando no hayan sido ingresados a la queue
                    }
                    actual=actual->getSiguiente();
                }
            }
            cout<<endl;
        }

        // void DFS(int inicio, int meta){
           // int previo[numNodos];
           // vector<int> visita;
           // bool visitados[numNodos];
            
           // for(int i = 0; i < numNodos; i++){

           // }

       // }

};

#endif
