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
#include "grafo.hpp" //Archivo de la clase Grafo

using namespace std;

int main() {
    
    ifstream datos; //Stack
    ListaCDL<IP> listaIP1;
    ListaCDL<IP> listaIP2;
    BST<Accesos> arbolAccesos;
    Grafo<string> grafoIP;
    
    //Lectura de archivo con los registros
    datos.open("bitacoraTest1.txt");
    string mes, dia, hora, ip1, ip2, falla;
    
    // Separa los datos por atributos y agrega a la lista de IPs
    while (datos.good()){
        getline(datos, mes, ' ');
        getline(datos, dia, ' ');
        getline(datos, hora, ' ');
        getline(datos, ip1, ' ');
        getline(datos, ip2, ' ');
        getline(datos, falla);
        listaIP1.agregar(ip1);
        listaIP2.agregar(ip2);
        grafoIP.insertarNodoGrafo(ip1);
        grafoIP.insertarNodoGrafo(ip2);
        grafoIP.agregarArco(ip1, ip2, 1);
    }
    datos.close();

    // Impresion de todas las IPs con su numero de accesos
    cout << "\n======== Grafo de IP ========\n" << endl;
    grafoIP.imprimirGrafo();

    cout << "\n======== DFS ========\n" << endl;
    grafoIP.DepthFirst(5);
    // Escritura de archivo para la impresion de la lista circular de IPs
    grafoIP.archivoGrafo();

    
    // Agregar los nodos para el arbol binario de accesos
    IP *current = listaIP1.getHead();
    do {
        arbolAccesos.agregaNodoIterativo(*new Accesos(current->getAccesos(), current->getIP()));
        current = current->getSiguiente();
    } while (current != listaIP1.getHead());

    // Busqueda de una falla dada por el usuario
    cout << "\n======== Arbol de fallas ========\n" << endl;
    arbolAccesos.imprimirArbolInOrder();
    arbolAccesos.imprimirArbolPostOrder();
    arbolAccesos.imprimirArbolPreOrder();

    // Busqueda de registros de una hora dada por el usuario
    int numAccesos;
    cout << "\n======== Busqueda de accesos ========\n" << endl;
    cout << "Dame un numero de accesos a buscar: \n";
    cin >> numAccesos;
    NodoArbolBinario<Accesos> *accesoBuscado = arbolAccesos.buscarNodo(*new Accesos(numAccesos," "));
    if (!accesoBuscado) 
        cout << "No se encuentra el numero de accesos" << endl;
    else
        cout << accesoBuscado->getValor().imprimirLista() << endl;


    return 0;
}