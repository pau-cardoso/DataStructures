#include <iostream>
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

        //Eliminar un nodo al inicio de la lista
        Nodo<T> * eliminarInicio(){
            if(this->head){
                Nodo<T> * eliminado=this->head; //Guardo la direccion del elemento a eliminar
                this->head=this->head->getSiguiente(); //Actualizar el head
                this->tam--;
                return eliminado;
            }
            return nullptr;            
        }

        //Imprimir los nodos de la lista
        void imprimirLista(){
            Nodo<T> * elemento=this->head;
            while(elemento){
                cout<<elemento->getValor()<<endl;//Cambio
                elemento=elemento->getSiguiente();
            }
            cout<<endl;
        }
};

template <typename T>
class Pila{
    Lista<T> * pila;
    public:
        void setPila(Lista<T> * pila){this->pila=pila;}
        Lista<T> * getPila(){return this->pila;}

        Pila(){
            this->pila=new Lista<T>();
        }

        ~Pila(){
            delete pila;
        }

        

        //Meter un elemento en la pila
        void push(T valor){
            this->pila->agregarInicio(valor);
        }

        //Dar el elemento en el top
        Nodo<T> * top(){
            return this->pila->getHead();
        }

        //Regresar si la pila esta vacía
        bool isEmpty(){
            if(this->pila->getHead())
                return false;
            return true;
        }

        Nodo<T> * pop(){
            return this->pila->eliminarInicio();
        }

        void imprimirPila(){
            this->pila->imprimirLista();
        }

};

