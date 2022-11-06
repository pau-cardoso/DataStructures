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
    Nodo * getSiguiente(){return this->siguiente;}
    void setSiguiente(Nodo * siguiente){this->siguiente=siguiente;}
    //Constructores
    Nodo(T valor,Nodo * siguiente){
        this->valor=valor;
        this->siguiente=siguiente;
    }
};

template <typename T>
class ListaSimpleTemplate{
    Nodo<T> * head;
    int tam;
    public:
        int getTam(){return this->tam;}
        void setTam(int tam){this->tam=tam;}
        Nodo<T> * getHead(){return this->head;}
        void setHead(Nodo<T> * head){this->head=head;}

        ListaSimpleTemplate(){
            this->head=nullptr;
            this->tam=0;
        }

        //Agregar nodo al inicio
        void agregarInicio(T valor){
            Nodo<T> * nuevo=new Nodo<T>(valor,this->head);  //Crear el nuevo nodo
            this->head=nuevo; //Actualizando el head de la lista al nuevo nodo
            //this->head=new Nodo(valor,this->head);
            this->tam++; //Actualizando el tamaño
        }

        //Agregar nodo al final
        void agregarFinal(T valor){
            Nodo<T> * nuevo=new Nodo<T>(valor,nullptr);  //Crear el nuevo nodo
            if(this->head){//Lista tiene nodos
                Nodo<T> * nodo=this->head;
                //Encontrar el último nodo
                while(nodo->getSiguiente())
                    nodo=nodo->getSiguiente();
                nodo->setSiguiente(nuevo); //Actualizar el ultimo siguiente con el nuevo
            }else{ //Lista vacia
                this->head=nuevo;
            }
            this->tam++;
        }
        
        void imprimirLista(){
            Nodo<T> * nodo=this->head;
            while(nodo){
                cout<<nodo->getValor()<<" ";
                nodo=nodo->getSiguiente();
            }
            cout<<endl;
        }

        Nodo<T> * buscarNodo(T valor){
            Nodo<T> * nodo=this->head;
            while(nodo){
                if(nodo->getValor()==valor)
                    return nodo;
                nodo=nodo->getSiguiente();
            }
            return nullptr; //No encontre el elemento a buscar
        }
        
};

template <typename T>
class ListaCircular{
    Nodo<T> * last;
    int tam;
    public:
        int getTam(){return this->tam;}
        void setTam(int tam){this->tam=tam;}
        Nodo<T> * getLast(){return this->last;}
        void setHead(Nodo<T> * last){this->last=last;}

        ListaCircular(){
            this->last=nullptr;
            this->tam=0;
        }

        void agregarInicio(T valor){
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

        //Agregar al final O(1)
        void agregarFinal(T valor){
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

        void imprimirLista(){
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
        
};