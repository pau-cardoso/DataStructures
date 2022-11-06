/**
 * @file ListaDL.hpp
 * @brief Implementacion de la clase ListaCDL para el uso de listas circulares doblemente ligadas
 * @authors 
 * Paulina Cardoso Fuentes  - A01701490,
 * María Fernanda Hernández Montes  - A01704918,
 * Paola Adriana Millares Forno - A01705674
 * @date 28/01/2021
 */

#ifndef LISTA_CIRCULAR_HPP
#define LISTA_CIRCULAR_HPP

using namespace std;

template <typename T>
class ListaCDL
{
    private:
        T *head;
        int tam;

    public:
        // Constructor
        ListaCDL();
        // Setters y getters
        int getTam() { return this->tam; }
        void setTam(int tam) { this->tam = tam; }
        T *getHead() { return this->head; }
        void setHead(T *head) { this->head = head; }
        // Metodos
        void agregarVacio(string ip);
        void agregar(string ip);
        bool buscarIP(string ip);
        string imprimirLista();
};

//=====================================================================
// 
//  Método: ListaCDL
//  Descripcíón: Inicializador del objeto
//  Complejidad: O(1)
//
//=====================================================================
template <typename T>
ListaCDL<T> :: ListaCDL() {
    this->head = nullptr;
    this->tam = 0;
}

//=====================================================================
//
//  Método: agregarVacio
//  Descripcíón: Se encarga de crear un nodo vacío dentro de la lista
//  Complejidad: O(1)
//
//=====================================================================
template <typename T>
void ListaCDL<T> :: agregarVacio(string ip) {
    T *nuevo = new T(ip, nullptr, nullptr);
    nuevo->setSiguiente(nuevo);
    nuevo->setAnterior(nuevo);
    this->head = nuevo;
}

//=====================================================================
//
//  Método: agregar
//  Descripcíón: Crea una nueva falla dentro de la lista
//  Complejidad: O(1)
//
//=====================================================================
template <typename T>
void ListaCDL<T> :: agregar(string ip) {
    if (head) { //Lista con nodos
        if ( !buscarIP(ip) ) {
            T *nuevo = new T(ip, head, head->getAnterior());
            head->getAnterior()->setSiguiente(nuevo);
            head->setAnterior(nuevo);
        }
    }
    else //Lista sin nodos
        this->agregarVacio(ip);
    this->tam++;
}

//=====================================================================
//
//  Método: buscarFalla
//  Descripcíón: Dado un tipo de falla y el mes de ocurrencia, se
//  realiza la búsqueda dentro de la lista. Arroja verdadero o falso.
//  Complejidad: O(n)
//
//=====================================================================
template <typename T>
bool ListaCDL<T> :: buscarIP(string ip) {
    if (head) {
        T *elemento = head;
        do {
            if (elemento->getIP() == ip ) {
                elemento->aumentarAccesos();
                return true;
            }
            elemento = elemento->getSiguiente();
        } while (elemento != this->head);
    }
    return false;
}

//=====================================================================
//
//  Método: imprimirLista
//  Descripcíón: A través de este método imprimimos la lista de fallas
//  Complejidad: O(n)
//
//=====================================================================
template <typename T>
string ListaCDL<T> :: imprimirLista() {
    stringstream aux;
    if (this->head) {
        T *elemento = this->head;
        do {
            aux << elemento->imprimirIP() << endl;
            elemento = elemento->getSiguiente();
        } while (elemento != this->head);
        aux << endl;
    } else {
        aux << "Lista vacía" << endl;
    }
    return aux.str();
}

#endif