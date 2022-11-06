#include "listaSimpleTemplate.hpp"

int main(){
    ListaSimpleTemplate<int> * lista=new ListaSimpleTemplate<int>(); //Crea lista en el heap con head=nullptr y tam=0
    lista->agregarInicio(3);
    lista->agregarInicio(10);
    lista->agregarInicio(19);
    lista->imprimirLista();
    lista->agregarFinal(100);
    lista->imprimirLista(); 
    ListaSimpleTemplate<int> lista2;
    lista2.agregarInicio(4);
    lista2.agregarInicio(10);
    lista2.agregarFinal(45);
    lista2.imprimirLista();

    ListaSimpleTemplate<string> lista3;
    lista3.agregarInicio("Programacion");
    lista3.agregarFinal("Estructuras de datos");
    lista3.imprimirLista();

    ListaCircular<float> lista4;
    lista4.agregarInicio(3.4);
    lista4.agregarInicio(6.5);
    lista4.agregarFinal(11.1);
    lista4.imprimirLista();   
    

    return 0;
}