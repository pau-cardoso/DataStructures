#include "listaDL.hpp"

int main() {
    ListaDL<string> *lista = new ListaDL<string>();
    lista->agregarInicio("Maria");
    lista->agregarInicio("Raul");
    lista->agregarInicio("Rita");
    lista->agregaFinal("Jason");
    lista->imprimirLista();
    lista->imprimirListaReversa();

    ListaCDL<string> *lista2 = new ListaCDL<string>();
    lista2->agregarInicio("Teresa");
    lista2->agregarInicio("Miguel");
    lista2->agregarInicio("Juan");
    lista2->agregarFinal("Gaby");
    lista2->imprimirLista();
    lista2->imprimirListaReversa(); // O(n)

    // Lista CDL en el stack que almacene objetos de la clase Ejemplo en stack
    ListaCDL<Ejemplo> lista3;
    Ejemplo a(13, 14);
    Ejemplo b;
    lista3.agregarInicio(a);
    lista3.agregarInicio(b);
    lista3.imprimirLista();

    // Lista CDL en el stack que almacene objetos de la clase Ejemplo en heap
    ListaCDL<Ejemplo *> lista4;
    lista4.agregarInicio(new Ejemplo(12, 13));
    lista4.agregarInicio(new Ejemplo());
    lista4.imprimirListaHeap();

    // Lista CDL en el heap que almacene objetos de la clase Ejemplo en stack
    ListaCDL<Ejemplo> * lista5 = new ListaCDL<Ejemplo>();
    Ejemplo c(45,67);
    Ejemplo d;
    lista5->agregarInicio(c);
    lista5->agregarInicio(d);
    lista5->imprimirLista();
    
    // Lista CDL en el heap que almacene objetos de la clase Ejemplo en heap
    ListaCDL<Ejemplo *> * lista6 = new ListaCDL<Ejemplo *>();
    lista6->agregarInicio(new Ejemplo(10,5));
    lista6->imprimirListaHeap();

    return 0;
}