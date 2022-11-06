#include <iostream>
using namespace std;

class Ejemplo
{
        int dato1;
        int dato2;

    public:
        int getDato1() { return this->dato1; }
        void setDato1(int dato1) { this->dato1 = dato1; }
        int getDato2() { return this->dato2; }
        void setDato2(int dato2) { this->dato2 = dato2; }

        friend ostream &operator<<(ostream &salida, const Ejemplo &objeto) {
            salida << objeto.dato1 << " " << objeto.dato2 << endl;
            return salida;
        }

        Ejemplo(int dato1, int dato2) {
            this->dato1 = dato1;
            this->dato2 = dato2;
        }
        Ejemplo() {
            this->dato1 = 0;
            this->dato2 = 0;
        }
};

template <typename T>
class NodoDL
{
    T valor;
    NodoDL<T> *siguiente;
    NodoDL<T> *anterior;

public:
    //Metodos
    T getValor() { return this->valor; }
    void setValor(T valor) { this->valor = valor; }
    NodoDL<T> *getSiguiente() { return this->siguiente; }
    void setSiguiente(NodoDL<T> *siguiente) { this->siguiente = siguiente; }
    NodoDL<T> *getAnterior() { return this->anterior; }
    void setAnterior(NodoDL<T> *anterior) { this->anterior = anterior; }

    //Constructores
    NodoDL(T valor, NodoDL<T> *siguiente, NodoDL<T> *anterior)
    {
        this->valor = valor;
        this->siguiente = siguiente;
        this->anterior = anterior;
    }
};

template <typename T>
class ListaDL
{
    NodoDL<T> *head;
    int tam;

public:
    int getTam() { return this->tam; }
    void setTam(int tam) { this->tam = tam; }
    NodoDL<T> *getHead() { return this->head; }
    void setHead(NodoDL<T> *head) { this->head = head; }

    ListaDL()
    {
        this->head = nullptr;
        this->tam = 0;
    }

    void agregarInicio(T valor)
    {
        NodoDL<T> *nuevo = new NodoDL<T>(valor, this->head, nullptr); //Crear nuevo nodo
        if (this->head)                                               //Lista con elementos
            this->head->setAnterior(nuevo);
        this->head = nuevo; //Actualizar el head de listaDL
        this->tam++;        //Actualizar el tamaño
    }

    void agregaFinal(T valor)
    {
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

    void imprimirLista()
    {
        NodoDL<T> *nodo = this->head;
        while (nodo)
        {
            cout << nodo->getValor() << " ";
            nodo = nodo->getSiguiente();
        }
        cout << endl;
    }

    void imprimirListaReversa()
    {
        if (this->head)
        {
            NodoDL<T> *nodo = this->head;
            //Encontrar el último
            while (nodo->getSiguiente())
                nodo = nodo->getSiguiente();

            while (nodo)
            {
                cout << nodo->getValor() << " ";
                nodo = nodo->getAnterior();
            }
            cout << endl;
        }
        else
            cout << "Lista vacia" << endl;
    }
};

template <typename T>
class ListaCDL
{
    NodoDL<T> *head;
    int tam;

public:
    int getTam() { return this->tam; }
    void setTam(int tam) { this->tam = tam; }
    NodoDL<T> *getHead() { return this->head; }
    void setHead(NodoDL<T> *head) { this->head = head; }

    ListaCDL()
    {
        this->head = nullptr;
        this->tam = 0;
    }

    void agregarVacio(T valor)
    {
        NodoDL<T> *nuevo = new NodoDL<T>(valor, nullptr, nullptr);
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        this->head = nuevo;
    }

    void agregarInicio(T valor)
    {
        if (this->head)
        { //Lista con nodos
            NodoDL<T> *nuevo = new NodoDL<T>(valor, this->head, this->head->getAnterior());
            this->head->getAnterior()->setSiguiente(nuevo);
            this->head->setAnterior(nuevo);
            this->head = nuevo;
        }
        else //Lista sin nodos
            this->agregarVacio(valor);
        this->tam++;
    }

    void agregarFinal(T valor)
    {
        if (this->head)
        { //Lista con nodos
            NodoDL<T> *nuevo = new NodoDL<T>(valor, this->head, this->head->getAnterior());
            this->head->getAnterior()->setSiguiente(nuevo);
            this->head->setAnterior(nuevo);
        }
        else //Lista sin nodos
            this->agregarVacio(valor);
        this->tam++;
    }

    void imprimirLista()
    {
        if (this->head)
        {
            NodoDL<T> *elemento = this->head;
            do
            {
                cout << elemento->getValor() << endl;
                elemento = elemento->getSiguiente();
            } while (elemento != this->head);
            cout << endl;
        }
        else
        {
            cout << "Lista vacía" << endl;
        }
    }

    void imprimirListaHeap()
    {
        if (this->head)
        {
            NodoDL<T> *elemento = this->head;
            do
            {
                cout << *elemento->getValor() << endl;
                elemento = elemento->getSiguiente();
            } while (elemento != this->head);
            cout << endl;
        }
        else
        {
            cout << "Lista vacía" << endl;
        }
    }

    void imprimirListaReversa()
    {
        if (this->head)
        {
            NodoDL<T> *elemento = this->head->getAnterior();
            do
            {
                cout << elemento->getValor() << endl;
                elemento = elemento->getAnterior();

            } while (elemento != this->head->getAnterior());
            cout << endl;
        }
        else
        {
            cout << "Lista vacía" << endl;
        }
    }
};