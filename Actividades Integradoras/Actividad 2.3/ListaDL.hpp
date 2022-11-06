/**
 * @file ListaDL.hpp
 * @brief Implementacion de la clase ListaDL y NodoDL para el uso de listas doblemente ligadas
 * @authors 
 * Paulina Cardoso Fuentes  - A01701490,
 * María Fernanda Hernández Montes  - A01704918,
 * Paola Adriana Millares Forno - A01705674
 * @date 28/01/2021
 */

#ifndef LISTA_DL_HPP
#define LISTA_DL_HPP

template <typename T>
class NodoDL
{
    T valor;
    NodoDL<T> *siguiente;
    NodoDL<T> *anterior;

public:
    // Getters y setters
    T getValor() { return this->valor; }
    void setValor(T valor) { this->valor = valor; }
    NodoDL<T> *getSiguiente() { return this->siguiente; }
    void setSiguiente(NodoDL<T> *siguiente) { this->siguiente = siguiente; }
    NodoDL<T> *getAnterior() { return this->anterior; }
    void setAnterior(NodoDL<T> *anterior) { this->anterior = anterior; }

    // Constructor
    NodoDL(T valor, NodoDL<T> *siguiente, NodoDL<T> *anterior) {
        this->valor = valor;
        this->siguiente = siguiente;
        this->anterior = anterior;
    }
};

template <typename T>
class ListaDL
{
    private:
        NodoDL<T> *head;
        int tam;

    public:
        // Constructor
        ListaDL();
        // Setters y getters
        int getTam() { return this->tam; }
        void setTam(int tam) { this->tam = tam; }
        NodoDL<T> *getHead() { return this->head; }
        void setHead(NodoDL<T> *head) { this->head = head; }
        // Metodos
        void agregarInicio(T valor);
        void agregaFinal(T valor);
        void imprimirListaHeap();
        string buscarHora(string hora);
};

//=====================================================================
//
//  Método: ListaDL
//  Descripcíón: Inicializador del objeto
//  Complejidad: O(1)
//
//=====================================================================
template <typename T>
ListaDL<T> :: ListaDL() {
    this->head = nullptr;
    this->tam = 0;
}

//=====================================================================
//
//  Método: agregarInicio
//  Descripcíón: Se encarga de crear un nodo y agregarlo al inicio de la lista
//  Complejidad: O(1)
//
//=====================================================================
template <typename T>
void ListaDL<T> :: agregarInicio(T valor) {
    NodoDL<T> *nuevo = new NodoDL<T>(valor, this->head, nullptr); //Crear nuevo nodo
    if (this->head)                                               //Lista con elementos
        this->head->setAnterior(nuevo);
    this->head = nuevo; //Actualizar el head de listaDL
    this->tam++;        //Actualizar el tamaño
}

//=====================================================================
//
//  Método: agregaFinal
//  Descripcíón: Crea un nuevo nodo dentro de la lista y lo agrega al final
//  Complejidad: O(n)
//
//=====================================================================
template <typename T>
void ListaDL<T> :: agregaFinal(T valor) {
    NodoDL<T> *nuevo = new NodoDL<T>(valor, nullptr, nullptr);
    if (this->head)
    {
        //Encontrar el ultimo nodo
        NodoDL<T> *nodo = this->head;
        while (nodo->getSiguiente())
        {
            nodo = nodo->getSiguiente();
        }
        nodo->setSiguiente(nuevo);
        nuevo->setAnterior(nodo);
    }
    else
        this->head = nuevo;
    this->tam++;
}

//=====================================================================
//
//  Método: imprimirListaHeap
//  Descripcíón: A través de este método imprimimos la lista de bitacoras
//               del Heap
//  Complejidad: O(n)
//
//=====================================================================
template <typename T>
void ListaDL<T> :: imprimirListaHeap() {
    NodoDL<T> *nodo = this->head;
    while (nodo)
    {
        cout << *nodo->getValor();
        nodo = nodo->getSiguiente();
    }
    cout << endl;
}

//=====================================================================
//
//  Método: buscarHora
//  Descripcíón: Dado un string con la hora, se busca en la lista y se
//  arroja, ya sea las ocurrencias con esa hora, o el string que indica
//  que dicha falla no existe
//  Complejidad: O(n)
//
//=====================================================================
template <typename T>
string ListaDL<T> :: buscarHora(string hora){
    NodoDL<T> *nodo = head;
    stringstream aux; 
    while (nodo) {
        if ( nodo->getValor()->getHoraIndividual() == hora )
            aux << *nodo->getValor() << endl;
        nodo = nodo->getSiguiente();
    }
    return aux.str(); 
}

#endif