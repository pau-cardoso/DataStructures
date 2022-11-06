#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Nodo{

public:
    T valor;
    Nodo *siguiente;
    T getValor() {return this->valor;}
    void setValor(T valor) {this->valor = valor;}
    Nodo * getSiguiente() {return this->siguiente;}
    void setSiguiente(Nodo * siguiente) {this->siguiente = siguiente;}
 
    Nodo(T valor, Nodo * siguiente){
        this->valor = valor;
        this->siguiente = siguiente;
    }
};

template <typename T>
class Lista{
    Nodo<T> * head;
    int tam;
    public:
        int getTam(){return this->tam;}
        void setTam(int tam){this->tam = tam;}
        Nodo<T> * getHead(){return this->head;}
        void setHead(Nodo<T> * head){this->head = head;}

        Lista(){
            this->head = nullptr;
            this->tam = 0;
        }

        void create(T valor){
            Nodo<T> *nuevo = new Nodo<T>(valor, this->head);

            if (head == 0)
            {
                //        agregar al inicio
                nuevo->siguiente = head; // apunta a donde apuntaba head(o sea 0)
                head = nuevo;
                tam++;
                return;
            }
            //    añadir al final
            Nodo<T> *p = new Nodo<T>(valor, this->head);
            while (p->siguiente != 0)
            {
                p = p->siguiente;
            }
            nuevo->siguiente = 0;
            p->siguiente = nuevo;
            tam++;
        }

        int read(T valor)
        {
            Nodo<T> *p;
            p = head;
            int posicion = 0;
            while (posicion < tam){

                if (valor == p->valor){
                    return posicion;
                }

                posicion++;
                p = p->siguiente;
            }
            return -1;
        }
        void update(int indice, T valor){
            Nodo<T> *p;
            if (head == 0){
                return;
            }
            p = head;
            for (int i = 0; i < tam && p != 0; i++){
                
                if (i == indice){
                    p->valor = valor;
                    return;
                }
                p = p->siguiente;
            }
        }

        int del(int indice){
            T valor;
            Nodo<T> *p, *q;
            if (head == 0)
                return -1;

            if (indice == 0){
                // Elimina el primero
                p = head;
                head = p->siguiente;
                valor = p->valor;
                delete p;
                tam--;
            }
            else{
                // Elimina el del medio
                p = head;
                q = p->siguiente;
                for (int i = 1; i < tam; i++){
                    if (i == indice){
                        valor = q->valor;
                        p->siguiente = q->siguiente;
                        delete q;
                        tam--;
                    }
                    p = p->siguiente;
                    q = q->siguiente;
                }
            }
            return 0;
        }

        void imprimirLista()
        {
            cout << endl;
            Nodo<T> *nodo = this->head;
            while (nodo)
            {
                cout << nodo->getValor() << " ";
                nodo = nodo->getSiguiente();
            }
            cout << endl << endl;
        }
};
