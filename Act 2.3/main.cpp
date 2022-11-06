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
#include "Bitacora.hpp" // Archivo de la clase Bitacora
#include "Falla.hpp"    // Archivo de la clase Falla
#include "ListaDL.hpp"  // Archivo de la clase ListaDL y NodoDL
#include "ListaCDL.hpp" // Archivo de la clase ListaCDL

int main() {
    
    ifstream datos; //Stack
    ListaDL<Bitacora*> listaBitacora;
    ListaCDL listaFallas;

    //Lectura de archivo con los registros
    datos.open("bitacoraSecundaria-1.txt");
    string mes, dia, hora, ipp, falla;
    
    // Separa los datos por atributos y crea un objeto Bitacora por cada registro
    while (datos.good()){
        getline(datos, mes, ' ');
        getline(datos, dia, ' ');
        getline(datos, hora, ' ');
        getline(datos, ipp, ' ');
        getline(datos, falla);
        listaBitacora.agregaFinal(new Bitacora(mes,dia,hora,ipp,falla));
    }
    datos.close();

    // Impresion de todos los registros
    cout << "\n======== Lista de registros ========\n" << endl;
    listaBitacora.imprimirListaHeap();

    // Recorre la lista doblemente ligada con los registros y agrega las fallas a la lista circular
    // De encontrar una falla repetida, se aumentan sus ocurrencias
    NodoDL<Bitacora*> *current = listaBitacora.getHead(); 
    for (int i = 0; i < listaBitacora.getTam(); i++) {
        listaFallas.agregar( current->getValor()->getFalla(), stoi( current->getValor()->mesANumero() ) );
        current = current->getSiguiente();
    }

    // Impresion de todas las fallas posibles
    cout << "\n======== Lista de fallas ========\n" << endl;
    listaFallas.imprimirListaHeap();

    // Busqueda de una falla dada por el usuario
    cout << "\n======== Busqueda de fallas ========\n" << endl;
    string sfalla;
    cout << "Cual falla desea buscar? ";
    getline(cin, sfalla);
    cout << listaFallas.buscarFalla(sfalla) << endl;

    // Escritura de archivo para la busqueda de fallas
    ofstream miArchivo("BusquedaFalla.txt");
    miArchivo << "======== Busqueda de fallas ========" << endl;
    miArchivo << listaFallas.buscarFalla(sfalla) << endl;
    miArchivo.close();

     // Busqueda de registros de una hora dada por el usuario
    string horas, minutos, segundos;
    cout << "\n======== Busqueda de hora ========\n" << endl;
    cout << "Dame una hora a buscar en formato HH:MM:SS \n";
    getline(cin, horas, ':');
    cout << listaBitacora.buscarHora(horas) << endl;

    // Escritura de archivo para la busqueda de hora
    ofstream miArchivo2("BusquedaHora.txt");
    miArchivo2 << "======== Busqueda de hora ========\n" << endl;
    miArchivo2 << "Hora: " << horas << "\n" << endl;
    miArchivo2 << listaBitacora.buscarHora(horas);
    miArchivo2.close(); 


    return 0;
}