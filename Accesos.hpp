/**
 * @file Accesos.hpp
 * @brief Implementacion de la clase Accesos
 * @authors 
 * Paulina Cardoso Fuentes  - A01701490,
 * María Fernanda Hernández Montes  - A01704918,
 * Paola Adriana Millares Forno - A01705674
 * @date 28/01/2021
 */

#ifndef ACCESOS_HPP
#define ACCESOS_HPP

#include <iostream>
#include "ListaSimple.hpp"

using namespace std;

/**
 * @class Accesos
 * @brief Clase para representar cada Acceso dentro del arbol binario
*/
class Accesos {
    private:
        int accesos;
        ListaSimple<string> listaIP;
    public:
        // Constructor y destructor
        Accesos();
        Accesos(int numAccesos, string ip);
        ~Accesos();
        // Getters y setters
        string getIP() { return listaIP.getHead()->getValor(); }
        int getAccesos() { return this->accesos; }
        void addIP(string ip);
        string imprimir();
        string imprimirLista();
        bool operator< (Accesos comparacion);
        bool operator> (Accesos comparacion);
        bool operator== (Accesos comparacion);
        friend ostream & operator << (ostream &os, Accesos &a);
};

//=====================================================================
// 
//  Método: Accesos
//  Descripcíón: Inicializador del objeto
//
//=====================================================================
Accesos :: Accesos() {
    accesos = 0;
}

//=====================================================================
// 
//  Método: Accesos
//  Descripcíón: Inicializador del objeto
//
//=====================================================================
Accesos :: Accesos(int numAccesos, string ip) {
    accesos = numAccesos;
    addIP(ip);
}

//=====================================================================
// 
//  Método: ~Accesos
//  Descripcíón: Destructor del objeto
//
//=====================================================================
Accesos :: ~Accesos() {
}

//=====================================================================
//
//  Método: addIP
//  Descripcíón: Agrega un elemento a la lista que contiene ip's
//  Complejidad: O(1)
//
//=====================================================================
void Accesos :: addIP(string ip) {
    listaIP.agregarFinal(ip);
}

//=====================================================================
//
//  Método: imprimir
//  Descripcíón: Imprime los elementos de la listaIP
//  Complejidad: O(n)
//
//=====================================================================
string Accesos :: imprimir() {
    stringstream aux;
    aux << "Accesos: " << accesos << endl;
    aux << listaIP.imprimirLista();
    return aux.str();
}

//=====================================================================
//
//  Método: imprimirLista
//  Descripcíón: Imprime la lista en la cual se encuentran los datos de
//               las direcciones Ip
//  Complejidad: O(n)
//
//=====================================================================
string Accesos :: imprimirLista() {
    stringstream aux;
    aux << listaIP.imprimirLista();
    return aux.str();
}

//=====================================================================
//
//  Método: Operator<
//  Descripcíón: regrsa un dato true o false, si es que accesos es menor 
//               a la comparación de accesos
//  Complejidad: O(1)
//
//=====================================================================
bool Accesos :: operator< (Accesos comparacion) {
    return accesos < comparacion.accesos;
}

//=====================================================================
//
//  Método: Operator>
//  Descripcíón: regrsa un dato true o false, si es que accesos es mayor
//               a la comparación de accesos
//  Complejidad: O(1)
//
//=====================================================================
bool Accesos :: operator> (Accesos comparacion) {
    return accesos > comparacion.accesos;
}

//=====================================================================
//
//  Método: Operator==
//  Descripcíón: regrsa un dato true o false, si es que accesos es igual
//               a la comparación de accesos
//  Complejidad: O(1)
//
//=====================================================================
bool Accesos :: operator== (Accesos comparacion) {
    return comparacion.accesos == accesos;
}

//===================================================================
//
//  Operador: <<
//  Descripción: Sobrecarga de operador
//  Complejidad: O(1)
//
//===================================================================
ostream & operator << (ostream &os, Accesos &a) {
    os << a.getAccesos();
    return os;
}

#endif