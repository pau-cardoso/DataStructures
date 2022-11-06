#include <iostream>
#include "Queue.hpp"

using namespace std;

/**
 * @class NodoArbolBinario
 * @brief Clase para representar cada nodo dentro del arbol binario
*/
template <typename T>
class NodoArbolBinario
{
    T valor;
    NodoArbolBinario<T> *izq;
    NodoArbolBinario<T> *der;
    NodoArbolBinario<T> *padre;

public:
    //Métodos get
    T getValor() { return this->valor; }
    NodoArbolBinario<T> *getIzq() { return this->izq; }
    NodoArbolBinario<T> *getDer() { return this->der; }
    NodoArbolBinario<T> *getPadre() { return this->padre; }
    //Métodos set
    void setValor(T valor) { this->valor = valor; }
    void setIzq(NodoArbolBinario<T> *izq) { this->izq = izq; }
    void setDer(NodoArbolBinario<T> *der) { this->der = der; }
    void setPadre(NodoArbolBinario<T> *padre) { this->padre = padre; }
    //Otros metodos
    static void imprimirInOrder(NodoArbolBinario<T> *actual);
    static void imprimirPreOrder(NodoArbolBinario<T> *actual);
    static void imprimirPostOrder(NodoArbolBinario<T> *actual);
    static void imprimirLevelByLevel(NodoArbolBinario<T> *actual);
    static NodoArbolBinario<T> *valorMenor(NodoArbolBinario<T> *actual);
    static NodoArbolBinario<T> *valorMayor(NodoArbolBinario<T> *actual);
    static int suma(int a, int b);
    static int height(NodoArbolBinario<T> *actual);

    //Constructor
    NodoArbolBinario(NodoArbolBinario<T> *padre, T valor) {
        this->valor = valor;
        this->izq = nullptr;
        this->der = nullptr;
        this->padre = padre;
    }

    //Destructor (delete)
    ~NodoArbolBinario() {}
};

/**
 * Imprime el arbol a partir de un nodo dado con un recorrido InOrder
 * @note La complejidad es de O(n)
 * @param actual Nodo a partir del cual se quiere imprimir el resto del arbol
*/
template <typename T>
void NodoArbolBinario<T> :: imprimirInOrder(NodoArbolBinario<T> *actual) {
    if (!actual)
        return;
    else {
        imprimirInOrder(actual->izq);
        cout << actual->valor << " ";
        imprimirInOrder(actual->der);
    }
}

/**
 * Imprime el arbol a partir de un nodo dado con un recorrido PreOrder
 * @note La complejidad es de O(n)
 * @param actual Nodo a partir del cual se quiere imprimir el resto del arbol
*/
template <typename T>
void NodoArbolBinario<T> :: imprimirPreOrder(NodoArbolBinario<T> *actual) {
    if (!actual)
        return;
    else {
        cout << actual->valor << " ";
        imprimirPreOrder(actual->izq);
        imprimirPreOrder(actual->der);
    }
}

/**
 * Imprime el arbol a partir de un nodo dado con un recorrido PostOrder
 * @note La complejidad es de O(n)
 * @param actual Nodo a partir del cual se quiere imprimir el resto del arbol
*/
template <typename T>
void NodoArbolBinario<T> :: imprimirPostOrder(NodoArbolBinario<T> *actual) {
    if (!actual)
        return;
    else {
        imprimirPostOrder(actual->izq);
        imprimirPostOrder(actual->der);
        cout << actual->valor << " ";
    }
}

/**
 * Imprime el arbol a partir de un nodo dado con un recorrido LevelByLevel
 * @note La complejidad es de O(n)
 * @param actual Nodo a partir del cual se quiere imprimir el resto del arbol
*/
template <typename T>
void NodoArbolBinario<T> :: imprimirLevelByLevel(NodoArbolBinario<T> *actual) {
    Queue<NodoArbolBinario<T>*> queue;
    queue.push(actual);
    NodoArbolBinario<T> *nodo;
    while ( queue.front() ) {
        nodo = queue.pop();
        if ( nodo->getIzq() )
            queue.push( nodo->getIzq() );
        if ( nodo->getDer() )
            queue.push( nodo->getDer() );
        cout << nodo->getValor() << " ";
    }
}

//Buscar el nodo menor de un subarbol con raiz en el nodo actual
template <typename T>
NodoArbolBinario<T> *NodoArbolBinario<T> :: valorMenor(NodoArbolBinario<T> *actual) {
    if (actual) {
        while (actual->getIzq()) {
            actual = actual->getIzq();
        }
        return actual;
    }
    return actual;
}

//Buscar el nodo mayor de un subarbol con raiz en el nodo actual
template <typename T>
NodoArbolBinario<T> *NodoArbolBinario<T> :: valorMayor(NodoArbolBinario<T> *actual) {
    if (actual) {
        while (actual->getDer()) {
            actual = actual->getDer();
        }
        return actual;
    }
    return actual;
}

/**
 * Calcula la altura a partir de un nodo dado
 * @param nodo Nodo del cual se quiere calcular la altura
 * @return Un entero que indica la altura del nodo dado
*/
template <typename T>
int NodoArbolBinario<T> :: height(NodoArbolBinario<T> *actual) {
    if (!actual)
        return 0;
    else {
        int heightIzq = height(actual->getIzq());
        int heightDer = height(actual->getDer());
        
        if (heightIzq > heightDer)
            return (heightIzq + 1);
        else 
            return (heightDer + 1);
    }
}

template <typename T>
int NodoArbolBinario<T> :: suma(int a, int b) {
    return a + b;
}


/**
 * @class BST
 * @brief Binary Search Tree, clase para un arbol binario
*/
template <typename T>
class BST {

    private:
        NodoArbolBinario<T> *root;

    public:
        // Métodos get
        NodoArbolBinario<T> *getRoot() { return this->root; }
        // Métodos set
        void setRoot(NodoArbolBinario<T> *root) { this->root = root; }
        // Otros metodos
        void agregaNodoIterativo(T valor);
        NodoArbolBinario<T> *buscarNodo(T valor);
        void imprimirArbolInOrder();
        void imprimirArbolPreOrder();
        void imprimirArbolPostOrder();
        void imprimirArbolLevelByLevel();
        void eliminarNodo(T valor);
        int height();
        int whatLevelAmI(T valor);
        NodoArbolBinario<T>* antecesor(T valor);
        void visit(int opcion);

        // Método constructor
        BST() {
            this->root = nullptr;
        }
        // Metodo destructor
        ~BST() {}
};

/**
 * Agrega un nuevo nodo al arbol en la posicion segun el valor que se desea agregar
 * @param valor Valor que se desea agregar
*/
template <typename T>
void BST<T> :: agregaNodoIterativo(T valor) {
    NodoArbolBinario<T> *actual = this->root;
    NodoArbolBinario<T> *padre;
    //Arbol vacío
    if (!this->root) {
        this->root = new NodoArbolBinario<T>(nullptr, valor);
        return;
    }
    if (!this->buscarNodo(valor)) {
        //Árbol con valores
        //Encontrar al nodo padre
        while (actual) {
            padre = actual;
            if (valor < actual->getValor()) //Determina la relación de orden
                actual = actual->getIzq();
            else
                actual = actual->getDer();
        }
        if (valor < padre->getValor()) //El elemento es menor que el padre
            padre->setIzq(new NodoArbolBinario<T>(padre, valor));
        else
            padre->setDer(new NodoArbolBinario<T>(padre, valor));
    }
    else
        cout << "Valor repetido" << endl;
}

/**
 * Busca el valor dado como parametro en algun nodo del arbol
 * @param valor Valor a buscar dentro del arbol
 * @return El nodo con el valor buscado
*/
template <typename T>
NodoArbolBinario<T> *BST<T> :: buscarNodo(T valor) {
    NodoArbolBinario<T> *actual = this->root;
    while (actual) {
        if (actual->getValor() == valor)
            return actual;
        else
            actual = actual->getValor() > valor ? actual->getIzq() : actual->getDer();
    }
    return nullptr;
}

/**
 * Imprime el arbol segun la opcion que desea el usuario
 * @note La complejidad es de O(n)
 * @param opcion Un entero (1-3) segun la opcion que desea el usuario@return un entero con la altura del arbol o -1 en caso de que no haya nodos en el arbol
*/
template <typename T>
void BST<T> :: visit(int opcion) {
    if (!root)
        cout << "-1" << endl;
    else if (opcion == 1)
        imprimirArbolPreOrder();
    else if (opcion == 2)
        imprimirArbolPostOrder();
    else
        imprimirArbolLevelByLevel();
}

/**
 * Regresa la altura del arbol binario completo
 * @note La complejidad es de O(n)
 * @return un entero con la altura del arbol o -1 en caso de que no haya nodos en el arbol
*/
template <typename T>
int BST<T> :: height() {
    if (!root)
        return -1;
    else
        return NodoArbolBinario<T>::height(this->root);
}

/**
 * Regresará un entero que indica el nivel en que se encuentra un dato, 
 * o -1 en caso de que no se encuentre en el BST
 * @note La complejidad es de O(n)
 * @param valor Dato a buscar su altura
 * @return Entero indicando el nivel del dato en el BST, o -1 si no se encuentra
*/
template <typename T>
int BST<T> :: whatLevelAmI(T valor) {
    NodoArbolBinario<T> *nodo = buscarNodo(valor);
    if (!nodo)
        return -1;
    else {
        int cont = 0;
        while (nodo->getPadre()) {
            cont++;
            nodo = nodo->getPadre();
        }
    return cont;
    }
}

/**
 * Regresa el antecesor de un valor dentro del árbol
 * @note La complejidad es de O(n)
 * @param valor El dato del cual se desea conocer su antecesor
 * @return Nodo antecesor
*/
template <typename T>
NodoArbolBinario<T>* BST<T> :: antecesor(T valor) { 
    NodoArbolBinario<T> *nodo = buscarNodo(valor);
    if (!nodo) 
        return nullptr;
    else
        return NodoArbolBinario<T>::valorMayor(nodo->getIzq());
}


/**
 * Elimina el nodo del arbol con el valor dado como parametro
 * @param valor Valor que se desea eliminar en el arbol
*/
template <typename T>
void BST<T> :: eliminarNodo(T valor) {
    NodoArbolBinario<T> *eliminar = this->buscarNodo(valor);
    NodoArbolBinario<T> *padre = nullptr;

    if (eliminar) {
        //Establer el nodo padre
        padre = eliminar->getPadre();
        //Caso de eliminar un nodo hoja
        if (!eliminar->getIzq() && !eliminar->getDer())
        {
            //Actualizar referencia del padre
            if (padre->getValor() > eliminar->getValor())
                padre->setIzq(nullptr); //Si el nodo hoja a eliminar es el nodo izq
            else
                padre->setDer(nullptr);
            //Liberar nodo
            delete eliminar;
        }
        else if (!eliminar->getIzq() && eliminar->getDer())
        { //Caso eliminar un nodo con hijo derecho
            //Actualizar los apuntadores
            if (padre->getValor() > eliminar->getValor())
                padre->setIzq(eliminar->getDer()); //Si el nodo a eliminar es el hijo izquierdo y tiene un nodo derecho
            else
                padre->setDer(eliminar->getDer()); //Si el nodo a eliminar es el hijo derecho y tiene un nodo derecho
            eliminar->getDer()->setPadre(padre);
            delete eliminar;
        }
        else if (eliminar->getIzq() && !eliminar->getDer())
        { //Caso eliminar un nodo con hijo izquierdo
            //Actualizar los apuntadores
            if (padre->getValor() > eliminar->getValor())
                padre->setIzq(eliminar->getIzq()); //Si el nodo a eliminar es el hijo izquierdo y tiene un nodo izquierdo
            else
                padre->setDer(eliminar->getIzq()); //Si el nodo a eliminar es el hijo derecho y tiene un nodo izquierdo
            eliminar->getIzq()->setPadre(padre);
            delete eliminar;
        }
        else
        { //Caso si el nodo tiene dos hijos
            //Sucesor
            NodoArbolBinario<T> *sucesor = NodoArbolBinario<T>::valorMenor(eliminar->getDer());
            //Copiar el valor del sucesor al nodo a eliminar
            eliminar->setValor(sucesor->getValor());
            if (sucesor->getPadre()->getValor() > sucesor->getValor())
                if (sucesor->getDer())
                {
                    sucesor->getPadre()->setIzq(sucesor->getDer());
                    sucesor->getDer()->setPadre(sucesor->getPadre());
                }
                else
                    sucesor->getPadre()->setIzq(nullptr); //Ocurre cuando el nodo izq no tiene hijo derecho
            else if (sucesor->getDer())
            {
                sucesor->getPadre()->setDer(sucesor->getDer());
                sucesor->getDer()->setPadre(sucesor->getPadre());
            }
            else
                sucesor->getPadre()->setDer(nullptr); //El nodo der no tiene hijo derecho
            delete sucesor;
        }
    }
    else
        cout << "Valor inexistente dentro del árbol" << endl;
}

/**
 * Imprime el arbol completo de forma InOrder
*/
template <typename T>
void BST<T> :: imprimirArbolInOrder() {
    NodoArbolBinario<T>::imprimirInOrder(this->root);
    cout << endl;
}

/**
 * Imprime el arbol completo de forma PreOrder
*/
template <typename T>
void BST<T> :: imprimirArbolPreOrder() {
    NodoArbolBinario<T>::imprimirPreOrder(this->root);
    cout << endl;
}

/**
 * Imprime el arbol completo de forma PostOrder
*/
template <typename T>
void BST<T> :: imprimirArbolPostOrder() {
    NodoArbolBinario<T>::imprimirPostOrder(this->root);
    cout << endl;
}

/**
 * Imprime el arbol completo de forma LevelByLevel
*/
template <typename T>
void BST<T> :: imprimirArbolLevelByLevel() {
    NodoArbolBinario<T>::imprimirLevelByLevel(this->root);
    cout << endl;
}
