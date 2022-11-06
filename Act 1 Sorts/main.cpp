/**
 * @file main.cpp
 * @brief Archivo main para correr la Actividad 1 ed TC1031
 * @author Paulina Cardoso Fuentes - A01701490
 * @date 17/01/2021
 */

#include <vector>   // Libreria para manejar vectores
#include <iostream> // Input y output
#include <stdlib.h> // Números aleatorios
#include <time.h>   // Hora de la computadora
#include <string>   // Libreria de strings
#include "Ordenamientos.hpp" // Archivo header con las funciones de ordenamiento y busquedas

using namespace std;

int main()
{
    vector<int> a(5), b(7), c(13), d(20); // Reserva espacio para vectores de tamaños 5, 7, 13 y 20
    int numero; // Numero que se desea buscar

    // Caso 1: Vector de 5
    cout << "\n********** Caso 1 **********\n"
         << endl;
    vectorAleatorio(a);
    cout << "\nIntercambio: \t";
    ordenaInsercion(a);
    cout << "Burbuja: \t";
    ordenaBurbuja(a);
    cout << "Quicksort: \t";
    ordenaQuicksort(a);
    cout << "Merge: \t\t";
    ordenaMerge(a);
    cout << endl;

    // Caso 2: Vector de 7
    cout << "\n********** Caso 2 **********\n"
         << endl;
    vectorAleatorio(b);
    cout << "\nIntercambio: \t";
    ordenaInsercion(b);
    cout << "Burbuja: \t";
    ordenaBurbuja(b);
    cout << "Quicksort: \t";
    ordenaQuicksort(b);
    cout << "Merge: \t\t";
    ordenaMerge(b);
    cout << endl;

    // Caso 3: Vector de 13
    cout << "\n********** Caso 3 **********\n"
         << endl;
    vectorAleatorio(c);
    cout << "\nIntercambio: \t";
    ordenaInsercion(c);
    cout << "Burbuja: \t";
    ordenaBurbuja(c);
    cout << "Quicksort: \t";
    ordenaQuicksort(c);
    cout << "Merge: \t\t";
    ordenaMerge(c);
    cout << endl;

    // Caso 4: Vector de 20
    cout << "\n********** Caso 4 **********\n"
         << endl;
    vectorAleatorio(d);
    cout << "\nIntercambio: \t";
    ordenaInsercion(d);
    cout << "Burbuja: \t";
    ordenaBurbuja(d);
    cout << "Quicksort: \t";
    ordenaQuicksort(d);
    cout << "Merge: \t\t";
    ordenaMerge(d);
    cout << endl;

    // Busquedas
    cout << "\n********** Búsquedas **********\n"
         << endl;
    imprimirVector(d);

    // Repeticion 4 veces para las busquedas
    for (int i = 0; i < 4; i++)
    {
        cout << "\nDame un número a buscar: ";
        cin >> numero; 
        cout << "Búsq. Binaria: \t";
        busquedas("binaria", d, numero);
        cout << "Búsq. Secuencial: ";
        busquedas("secuencial", d, numero);
    }
    cout << endl;
    return 0;
}