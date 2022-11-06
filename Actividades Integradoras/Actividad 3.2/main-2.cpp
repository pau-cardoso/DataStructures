/**
 * @file main.cpp
 * @brief Archivo ejecutable que lee un archivo de registros y almacena la informacion en diferentes listas
 * @authors 
 *  Paulina Cardoso Fuentes  - A01701490,
 *  María Fernanda Hernández Montes  - A01704918,
 *  Paola Adriana Millares Forno - A01705674
 * @date 27/01/2021
 */

#include <iostream>     // Biblioteca para input y output
#include <fstream>      // Biblioteca para lectura y escritura de archivos
#include <sstream>      // Biblioteca para lectura y escritura de archivos
#include <string>       // Biblioteca para lectura y escritura de archivos
#include "IP.hpp"    // Archivo de la clase Falla
#include "Accesos.hpp"    // Archivo de la clase Falla
#include "bst.hpp"    // Archivo de la clase Falla
#include "ListaSimple.hpp"    // Archivo de la clase Falla
#include "ListaCDL.hpp" // Archivo de la clase ListaCDL

int main() {
    
    ifstream datos; //Stack
    ListaCDL<IP> listaIP;
    BST<Accesos> arbolAccesos;

    //Lectura de archivo con los registros
    datos.open("BitacoraPrueba.txt");
    string mes, dia, hora, ipp, falla;
    
    // Separa los datos por atributos y agrega a la lista de IPs
    while (datos.good()){
        getline(datos, mes, ' ');
        getline(datos, dia, ' ');
        getline(datos, hora, ' ');
        getline(datos, ipp, ' ');
        getline(datos, falla);
        listaIP.agregar(ipp);
    }
    datos.close();

    // Impresion de todas las IPs con su numero de accesos
    cout << "\n======== Lista de IP ========\n" << endl;
    cout << listaIP.imprimirLista();

    // Escritura de archivo para la impresion de la lista circular de IPs
    ofstream miArchivo("ListaIP.txt");
    miArchivo << listaIP.imprimirLista();
    miArchivo.close();

    // Agregar los nodos para el arbol binario de accesos
    IP *current = listaIP.getHead();
    do {
        arbolAccesos.agregaNodoIterativo(*new Accesos(current->getAccesos(), current->getIP()));
        current = current->getSiguiente();
    } while (current != listaIP.getHead());


    // Busqueda de una falla dada por el usuario
    cout << "\n======== Arbol de accesos ========\n" << endl;
    cout << "Arbol PreOrder: ";
    arbolAccesos.imprimirArbolPreOrder();
    cout << "Arbol InOrder: ";
    arbolAccesos.imprimirArbolInOrder();

    // Busqueda de registros de una hora dada por el usuario
    int numAccesos;
    cout << "\n======== Busqueda de accesos ========\n" << endl;
    for (int i = 0; i < 2; i++) {        
        cout << "Dame un numero de accesos a buscar: \n";
        cin >> numAccesos;
        NodoArbolBinario<Accesos> *accesoBuscado = arbolAccesos.buscarNodo(*new Accesos(numAccesos," "));
        if (!accesoBuscado) 
            cout << "No se encuentra el numero de accesos" << endl;
        else
            cout << accesoBuscado->getValor().imprimirLista() << endl;
    }


    return 0;
}