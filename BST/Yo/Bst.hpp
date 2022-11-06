#include <iostream>

using namespace std;

template <class T> class BST;

template <typename T>
class NodoArbolB {
    private:
        T valor;
        NodoArbolB * izq;
        NodoArbolB * der;
        NodoArbolB * padre;
    public:
        // Constructor y destructor
        NodoArbolB(NodoArbolB<T> *padre, T valor);
        ~NodoArbolB();
    friend class BST<T>;
};

// Constructor
template <typename T>
NodoArbolB<T> :: NodoArbolB(NodoArbolB<T> *padre, T valor) {
    this -> valor = valor;
    izq = NULL;
    der =NULL;
    this -> padre = padre;
}

// Destructor
template <typename T>
NodoArbolB<T> :: ~NodoArbolB() {
    delete this->valor;
    // cout << "Ejecute el destructor"
}

template <typename T>
class BST {

    private:
    NodoArbolB<T> *root;
    int size;

    public:
        // Constructor y destructor
        BST(); // te amo <3 awwww yo mas <3 
        ~BST();
        // Metodos
        void agregarNodoIterativo(T valor);  
        NodoArbolB<T> *buscarNodo(T valor);
};

template <typename T>
BST<T> :: BST() {
    size = 0;
    root = NULL;
}

template <typename T>
BST<T> :: ~BST() {
    delete this;
}

template <typename T>
void BST<T> :: agregarNodoIterativo(T valor) {
    NodoArbolB<T> * actual = root, * pdre;

    // Arbol vacio
    if (!this->root) {
        root = new NodoArbolB<T>(nullptr,valor);
        return;
    }
    if (!this->buscarNodo(valor)) {
        // Arbol con valores
        // Encontrar al nodo padre
        while (actual) {
            pdre = actual;
            if (valor < actual -> valor)
                actual = actual -> izq;
            else 
                actual = actual -> der;
        }
        if (valor < pdre->valor) // El elemento es menor que el padre
            pdre->izq = new NodoArbolB<T>(pdre,valor);
        else
            pdre->der = new NodoArbolB<T>(pdre,valor);
    } else
        cout << "Valor repetido" << endl;
} 

template <typename T>
NodoArbolB<T>* BST<T> :: buscarNodo(T value) {
    NodoArbolB<T> * actual = root;
    while (actual) {
        if (actual->valor == value)
            return actual;
        else
            actual = actual->valor > value? actual->izq : actual->der;
    }
    return actual;
}

template <typename T>
static NodoArbolB<T> * NodoArbolB<T>* BST<T> :: valorMenor(NodoArbolB<T> * actual){
    if(actual){
        while(actual->getIzq()){
            actual=actual->getIzq();
        }
        return actual;
    }
    return actual;
}

void NodoArbolB :: imprimirArbolInOrder(){
    NodoArbolBinario<T>::imprimirInOrder(this->root);
    cout<<endl;
}
