/**
 * @file ListaSimple.hpp
 * @brief Elaboracion de la estructura de datos de listas simples
 * @author Paulina Cardoso Fuentes - A01701490
 * @date 26/01/2021
 */

#include <sstream>
#include <string>

using namespace std;

template <typename T>
class Nodo {
    private:
        //Atributos 
        T valor;
        Nodo *siguiente;
    public:
        // Constructor
        Nodo(T valor, Nodo *siguiente) {
            this->valor = valor;
            this->siguiente = siguiente;
        }
        //Metodos getters y setters
        T getValor() { return this->valor; }
        void setValor(T valor) { this->valor = valor; }
        Nodo *getSiguiente() { return this->siguiente; }
        void setSiguiente(Nodo *siguiente) { this->siguiente = siguiente; }
};

template <typename T>
class ListaSimple {
    // Atributos
    private:
        Nodo<T> *head; // cabeza de la lista
        int size; // tamaño

    public:
        // Constructores
        ListaSimple() {
            this->head = nullptr;
            this->size = 0;
        }
        // Getters y setters
        int getsize() { return this->size; }
        void setsize(int size) { this->size = size; }
        Nodo<T> *getHead() { return this->head; }
        void setHead(Nodo<T> *head) { this->head = head; }
        // Metodos de la clase
        void create(T valor);           // C
        string read(T valor);           // R
        void update(int pos, T valor);  // U
        void del(int pos);              // D
        string imprimirLista();
};

/**!
 * Agrega un nuevo nodo a la lista 
 * 
 * @note Tiene una complejidad Big O de O(n)
 * 
 * @param valor valor a insertar en la lista
*/
template <typename T>
void ListaSimple<T>::create(T valor) {
    Nodo<T> *nuevo = new Nodo<T>(valor, nullptr); //Crear el nuevo nodo
    if (this->head) { //Lista tiene nodos
        Nodo<T> *nodo = this->head;
        //Encontrar el último nodo
        while (nodo->getSiguiente())
            nodo = nodo->getSiguiente(); // Recorre la lista
        nodo->setSiguiente(nuevo); // Actualiza el ultimo siguiente con el nuevo
    }
    else { // Lista vacia
        this->head = nuevo;
    }
    this->size++; // Actualiza el tamanio
}


/**!
 * Lee (busca, obtiene, etc.) un elemento dentro de la estructura de datos
 * 
 * @note Tiene una complejidad Big O de O(n)
 * 
 * @param valor Valor a buscar dentro de la lista
 * @return String que te indica la posicion en la que se encuentra el valor o si no se encontró
*/
template <typename T>
string ListaSimple<T>::read(T valor) {
    Nodo<T> *nodo = this->head;
    int pos = 0;
    while (nodo) { // Recorre los elementos de la lista
        if (nodo->getValor() == valor) // Compara si el valor dado coincide con el del nodo
            return "El valor se encuentra en la posicion "+ to_string(pos); // Regresa la posicion en la que se encontro
        nodo = nodo->getSiguiente();
        pos++;
    }
    return "No se encontro el valor"; //No encontre el elemento a buscar
}


/**!
 * Actualiza un elemento dentro de la estructura de datos
 * 
 * @note Tiene una complejidad Big O de O(n)
 * 
 * @param pos entero con la posicion del elemento a actualizar
 * @param valor valor al que se desea actualizar el elemento
*/
template <typename T>
void ListaSimple<T>::update(int pos, T valor) {
    Nodo<T> *current = this->head;
    if (size == 0) {
        return;
    }
    
    for (int i = 0; i < pos; i++) {
        current = current->getSiguiente();
    }
    current->setValor(valor);
}


/**!
 * Borra un elemento dentro de la estructura de datos
 * 
 * @note Tiene una complejidad Big O de O(n)
 * 
 * @param pos entero con la posicion del elemento a borrar
*/
template <typename T>
void ListaSimple<T>::del(int pos) {
    Nodo<T> *current = head;

    if (pos >= size) {
        return;
    }

    else if (pos == 0) {
        head = current->getSiguiente();
        delete current;
    }

    else {
        for (int i = 0; i < pos-1; i++) {
            current = current->getSiguiente();
        }
        if (pos == size-1) {
            current->setSiguiente(nullptr);
        }
        else {
            current->setSiguiente(current->getSiguiente()->getSiguiente());
        }
        delete current->getSiguiente();
    }
    size--;
}


/**!
 * Realiza un string con todos los elementos de la lista simple
 * 
 * @note Tiene una complejidad Big O de O(n)
 * 
 * @return String con los valores de la lista
*/
template <typename T>
string ListaSimple<T>::imprimirLista() {
    stringstream str;
    Nodo<T> *nodo = head;
    while (nodo) { // Ya esto no es el problema superalo jajaja
        str << nodo->getValor() << " ";
        nodo = nodo->getSiguiente();
    }
    str << endl;
    return str.str();
}