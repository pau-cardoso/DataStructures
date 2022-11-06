#include <iostream>
#include <vector>
//Listas

using namespace std;



template <typename T>
class Nodo{
    //Atributos
    T valor;
    Nodo<T> * siguiente;
    public:
        //get
        T getValor(){return this->valor;}
        Nodo<T> * getSiguiente(){return this->siguiente;}
        //set
        void setValor(T valor){this->valor=valor;}
        void setSiguiente(Nodo<T>* siguiente){this->siguiente=siguiente;}
        //constructor
        Nodo(T valor,Nodo<T> * siguiente){
            this->valor=valor;
            this->siguiente=siguiente;
        }
};

template <typename T>
class Lista{
    //Atributos
    Nodo<T> * head;
    int tam;
    public:
        //Metodos get y set        
        Nodo<T> * getHead(){return this->head;}
        int getTam(){return this->tam;}
        void setHead(Nodo<T> * head){this->head=head;}
        void setTam(int tam){this->tam=tam;}
        //Método constructor
        Lista(){
            this->head=nullptr;
            this->tam=0;
        }
        //Operaciones de la lista

        //Agregar un nodo al inicio de la lista
        void agregarInicio(T valor){
            Nodo<T> * nuevo=new Nodo<T>(valor,this->head); // Creando el nuevo nodo
            this->head=nuevo; //Actualizar la head de la lista
            this->tam++; //Actualizamos el tamaño
        }

        //Agregar un nodo al final de la lista
        void agregarFinal(T valor){
            Nodo<T> * nuevo=new Nodo<T>(valor,nullptr);
            if(this->head){//Verificar si la lista esta vacia
                Nodo<T> * elemento=this->head;
                while(elemento->getSiguiente())
                    elemento=elemento->getSiguiente();
                elemento->setSiguiente(nuevo);                
            }else{
                this->head=nuevo;
            }
            this->tam++;
        }
        
        //Imprimir los nodos de la lista
        void imprimirLista(){
            Nodo<T> * elemento=this->head;
            while(elemento){
                cout<<elemento->getValor()<<endl;
                elemento=elemento->getSiguiente();
            }
            cout<<endl;
        }

        //Eliminar un nodo al inicio de la lista
        Nodo<T> * eliminarInicio(){
            if(this->tam==0)
                return nullptr;
            Nodo<T> * eliminado=this->head;
            this->head=this->head->getSiguiente();
            this->tam--;
            return eliminado;
        }

};

template <typename T>
class Conexion{//Nodos color rojo
    T nombreNodo;
    int peso;

    public:
        Conexion(T nombreNodo, int peso){
            this->nombreNodo=nombreNodo;
            this->peso;
        }
};

template <typename T>
class NodoGrafo{//Nodos colo azul
    T nombreNodo;
    Lista<Conexion<T> *> * conexiones;
    public:
        NodoGrafo(T nombreNodo){
            this->nombreNodo=nombreNodo;
            this->conexiones=new Lista<Conexion<T>*>();
        }
};

template <typename T>
class Grafo{
    int numNodos;
    Lista<NodoGrafo<T> *> * nodos;

    public:
        Grafo(){
            this->numNodos=0;
            this->nodos=new Lista<NodoGrafo<T>*>();
        }

        void insertarNodoGrafo(T nombreNodo){
            this->nodos->agregarInicio(new NodoGrafo<T>)
        }

};

