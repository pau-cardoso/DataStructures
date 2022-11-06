/**
 * @file ListaSimple.hpp
 * @brief Implementacion de la clase Lista Simple
 * @authors 
 * Paulina Cardoso Fuentes  - A01701490,
 * María Fernanda Hernández Montes  - A01704918,
 * Paola Adriana Millares Forno - A01705674
 * @date 03/02/2021
 */

#ifndef LISTA_SIMPLE_HPP
#define LISTA_SIMPLE_HPP

#include <iostream>

using namespace std;

template <typename T>
class NodoLS {
    //Atributos
    T valor;
    NodoLS * siguiente;
    public:
    //Metodos
    T getValor(){return this->valor;}
    void setValor(T valor){this->valor=valor;}
    NodoLS * getSiguiente(){return this->siguiente;}
    void setSiguiente(NodoLS * siguiente){this->siguiente=siguiente;}
    //Constructores
    NodoLS(T valor,NodoLS * siguiente){
        this->valor=valor;
        this->siguiente=siguiente;
    }
};

template <typename T>
class ListaSimple{
    NodoLS<T> * head;
    int tam;
    public:
        int getTam(){return this->tam;}
        void setTam(int tam){this->tam=tam;}
        NodoLS<T> * getHead(){return this->head;}
        void setHead(NodoLS<T> * head){this->head=head;}

        ListaSimple(){
            this->head=nullptr;
            this->tam=0;
        }

        //=====================================================================
        //
        //  Método: agregarInicio
        //  Descripcíón: Agrega un nodo al inicio de la lista
        //  Complejidad: O(1)
        //
        //=====================================================================
        void agregarInicio(T valor){
            NodoLS<T> * nuevo=new NodoLS<T>(valor,this->head);  
            this->head=nuevo; 
            this->tam++; 
        }
        //=====================================================================
        //
        //  Método: agregarFinal
        //  Descripcíón: Agrega un nodo al final de la lista
        //  Complejidad: O(n)
        //
        //=====================================================================
        void agregarFinal(T valor){
            NodoLS<T> * nuevo=new NodoLS<T>(valor,nullptr);  
            if(this->head){//Lista tiene nodos
                NodoLS<T> * nodo=this->head;
                //Encontrar el último nodo
                while(nodo->getSiguiente())
                    nodo=nodo->getSiguiente();
                nodo->setSiguiente(nuevo); //Actualizar el ultimo siguiente con el nuevo
            }else{ //Lista vacia
                this->head=nuevo;
            }
            this->tam++;
        }

        //=====================================================================
        //
        //  Método: imprimirLista
        //  Descripcíón: Imprime los elementos de la lista
        //  Complejidad: O(n)
        //
        //=====================================================================
        string imprimirLista(){
            stringstream aux;
            NodoLS<T> * nodo=this->head;
            while(nodo){
                aux << nodo->getValor()<<", ";
                nodo=nodo->getSiguiente();
            }
            aux << endl;
            return aux.str();
        }

        //=====================================================================
        //
        //  Método: buscarNodo
        //  Descripcíón: Busca un valor en la lista
        //  Complejidad: O(n)
        //
        //=====================================================================
        NodoLS<T> * buscarNodo(T valor){
            NodoLS<T> * nodo=this->head;
            while(nodo){
                if(nodo->getValor()==valor)
                    return nodo;
                nodo=nodo->getSiguiente();
            }
            return nullptr; //No encontre el elemento a buscar
        }
        
};

#endif