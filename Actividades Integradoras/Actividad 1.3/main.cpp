/*
 * Este programa tiene como objetivo leer un archivo en el cual se encuentran distintas
 * fechas y fallas en un inicio de sesión. Una vez obtenidos estos datos, se realizara 
 * el ordenamiento por fechas y una busqueda segun las fechas escogídas por el usuario 
 * 
 * Creado por : 
 * 
 *   María Fernanda Hernández Montes  - A01704918
 *   Paulina Cardoso Fuentes  - A01701490 
 *   Paola Adriana Millares Forno - A01705674
 *
 * Fecha: 20/01/2021
*/

#include "bitacora.hpp"
#include <iostream>
#include <vector>
#include <fstream> //Biblioteca para lectura y escritura de archivos
#include "Ordenamientos.hpp"

int main() {
    
    ifstream datos; //Stack

    //Lectura de archivo separada
    datos.open("bitacoraPrincipal.txt");
    string mes, dia, hora, ipp, falla;
    vector<Bitacora *> log; //vector con objetos dentro del heap
    while (datos.good()){
        getline(datos, mes, ' ');
        getline(datos, dia, ' ');
        getline(datos, hora, ' ');
        getline(datos, ipp, ' ');
        getline(datos, falla);
        log.push_back(new Bitacora(mes, dia, hora, ipp, falla));
    }
    datos.close();

    // Impresion de datos sin ordenamiento
    cout << "\n======== Registros desordenados ========\n" << endl;
    for (Bitacora * entry:log)
        entry -> imprimirRegistro();


    ordenaQuicksort(log); // Realiza el ordenamiento por fecha (clave) de los registros mediante QuickSort

    // Impresion y escritura de archivo para los registros ordenados
    cout << "\n\n======== Registros ordenados ========\n" << endl;
    ofstream miArchivo("Ordenamientos.txt");
    miArchivo << "Bitacora ordenada" << "\n";
    for (int i = 0; i < log.size(); i++){
        miArchivo << log[i]->escritura() << "\n";
        log[i]->imprimirRegistro();
    }
    miArchivo.close();

    cout << "\n\n======== Busquedas ========" << endl;
    string m, d;
    cout << "\nIngrese el mes de inicio en formato numeral ejemplo (11): " << endl;
    cin >> m;
    cout << "\nIngrese el dia de inicio en formato numeral ejemplo (05): " << endl;
    cin >> d;
    int inicio = stoi(m + d);
    cout << "\nIngrese el mes final en formato numeral ejemplo (11): " << endl;
    cin >> m;
    cout << "\nIngrese el dia de final en formato numeral ejemplo (05): " << endl;
    cin >> d;
    int fin = stoi(m + d);

    int posInicio = busqBinaria(log, inicio);
    int posFin = busqBinaria(log, fin);

    ofstream miArchivo2("Busqueda.txt");
    miArchivo2 << "Bitacora de busquedas" << "\n";
    for (int i = posInicio; i <= posFin && i < log.size(); i++) {
        if (log[i]->getClave() <= fin){
            miArchivo2 << log[i]->escritura() << "\n";
        }
    }
    miArchivo2.close();

    return 0;
}