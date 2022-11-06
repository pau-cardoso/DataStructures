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

class ListaCDL
{
    private:
        Falla *head;
        int tam;

    public:
        // Constructor
        ListaCDL();
        // Setters y getters
        int getTam() { return this->tam; }
        void setTam(int tam) { this->tam = tam; }
        Falla *getHead() { return this->head; }
        void setHead(Falla *head) { this->head = head; }
        // Metodos
        void agregarVacio(string sfalla, int mes);
        void agregar(string sfalla, int mes);
        bool buscarFalla(string sfalla, int mes);
        string buscarFalla(string sfalla);
        void imprimirLista();
        void imprimirListaHeap();
};

//=====================================================================
// 
//  Método: ListaCDL
//  Descripcíón: Inicializador del objeto
//
//=====================================================================
ListaCDL :: ListaCDL() {
    this->head = nullptr;
    this->tam = 0;
}

//=====================================================================
//
//  Método: agregarVacio
//  Descripcíón: Se encarga de crear un nodo vacío dentro de la lista
//  Complejidad: O(1)
//=====================================================================
void ListaCDL :: agregarVacio(string sfalla, int mes) {
    Falla *nuevo = new Falla(sfalla, mes, nullptr, nullptr);
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
void ListaCDL :: agregar(string sfalla, int mes) {
    if (head) { //Lista con nodos
        if ( !buscarFalla(sfalla, mes) ) {
            Falla *nuevo = new Falla(sfalla, mes, head, head->getAnterior());
            head->getAnterior()->setSiguiente(nuevo);
            head->setAnterior(nuevo);
        }
    }
    else //Lista sin nodos
        this->agregarVacio(sfalla, mes);
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
bool ListaCDL :: buscarFalla(string sfalla, int mes) {
    if (head) {
        Falla *elemento = head;
        do {
            if (elemento->getFalla() == sfalla ) {
                elemento->aumentarOcurrencias(mes);
                return true;
            }
            elemento = elemento->getSiguiente();
        } while (elemento != this->head);
    }
    return false;
}

//=====================================================================
//
//  Método: buscarFalla
//  Descripcíón: Dado un tipo de falla, se busca en la lista y se arroja
//  ya sea la ocurrencia o el string que indica que dicha falla no existe
//  Complejidad: O(n)
//
//=====================================================================
string ListaCDL :: buscarFalla(string sfalla) {
    if (head) {
        Falla *elemento = head;
        do {
            if (elemento->getFalla() == sfalla )
                return elemento->imprimirOcurrencias();
            elemento = elemento->getSiguiente();
        } while (elemento != this->head);
    }
    return "\nNo existe la falla\n";
}

//=====================================================================
//
//  Método: imprimirLista
//  Descripcíón: A través de este método imprimimos la lista de fallas
//  Complejidad: O(n)
//
//=====================================================================
void ListaCDL :: imprimirLista() {
    if (this->head) {
        Falla *elemento = this->head;
        do {
            cout << elemento->getFalla() << endl;
            elemento = elemento->getSiguiente();
        } while (elemento != this->head);
        cout << endl;
    } else {
        cout << "Lista vacía" << endl;
    }
}

//=====================================================================
//
//  Método: imprimirListaHeap
//  Descripcíón: A través de este método imprimimos la lista de fallas
//  del Heap
//  Complejidad: O(n)
//
//=====================================================================
void ListaCDL :: imprimirListaHeap() {
    if (this->head) {
        Falla *elemento = this->head;
        do {
            cout << elemento->getFalla() << endl;
            elemento = elemento->getSiguiente();
        } while (elemento != this->head);
        cout << endl;
    } else {
        cout << "Lista vacía" << endl;
    }
}

#endif