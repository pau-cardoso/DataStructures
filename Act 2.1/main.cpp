/**
 * @file main.cpp
 * @brief Archivo main para estructura de datos lista simple
 * @author Paulina Cardoso Fuentes - A01701490
 * @date 26/01/2021
 */

#include <iostream>
#include "ListaSimple.hpp"

using namespace std;

int main() {
    
    ListaSimple<int> lista;

    cout << "==== Se agregan los elementos 8, 3, 2, 9, 5 a la lista ====" << endl; // CREATE
    lista.create(8);
    lista.create(3);
    lista.create(2);
    lista.create(9);
    lista.create(5);

    cout << "\nLa lista es:\n"<< lista.imprimirLista() << endl;

    cout << "========== Buscar 3 en la lista de enteros ==========" << endl; // READ
    cout << lista.read(3)<<endl;
    cout << "\n\n========== Buscar 7 en la lista de enteros ==========" << endl; // READ
    cout << lista.read(7)<<endl;
    
    cout << "\n\n==== Actualizar el elemento en la posicion 0 a 12 ====" << endl; // UPDATE
    lista.update(0,12);
    cout << lista.imprimirLista() << endl;
    cout << "\n==== Actualizar el elemento en la posicion 2 a 7 ====" << endl; // UPDATE
    lista.update(2,7);
    cout << lista.imprimirLista() << endl;

    cout << "\n======= Eliminar el elemento en la posicion 0 =======" << endl; // DELETE
    lista.del(0);
    cout << lista.imprimirLista() << endl;
    cout << "\n======= Eliminar el elemento en la posicion 3 =======" << endl; // DELETE
    lista.del(3);
    cout << lista.imprimirLista() << endl;

    return 0;
}