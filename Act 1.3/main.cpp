#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>
#include "bitacora.hpp"

int main() {
    Bitacora * prueba; // heap
    prueba = new Bitacora("Oct", "09", "10:32:24", "255.254.1:4567", "Error");
    prueba -> imprimirRegistro(); // Seleccion via apuntador

    // Escribir un archivo
    ofstream miArchivo("prueba1.txt");
    for (int i = 0; i <= 10; i++)
        miArchivo << i << "\n";
    miArchivo << "Esto es una prueba" << "\n";
    miArchivo.close();
    //Lectura de archivos

    ifstream datos; //Stack
    datos.open("bitacoraSecundaria-1.txt");
    string entrada;
    while (getline(datos,entrada))
        cout << entrada << endl;
    datos.close();

    // Lectura de archivo separada
    datos.open("bitacoraSecundaria-1.txt");
    string mes, dia, hora, ipp, falla;
    vector<Bitacora*> log; // Vector con objetos dentro del heap
    vector<Bitacora> log2; // vector con objetos dentro del stack

    while ( datos.good() )
    {
        getline(datos, mes, ' ');
        getline(datos, dia, ' ');
        getline(datos, hora, ' ');
        getline(datos, ipp, ' ');
        getline(datos, falla, ' ');
        log.push_back( new Bitacora(mes, dia, hora, ipp, falla) );
    }
    datos.close();

    for (Bitacora * entry:log)
        entry -> imprimirRegistro();

    log[0] -> imprimirRegistro();
    return 0;
}