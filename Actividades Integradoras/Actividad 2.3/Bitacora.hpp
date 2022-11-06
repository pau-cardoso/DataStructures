/**
 * @file Bitacora.hpp
 * @brief Implementacion de la clase Bitacora
 * @authors 
 * Paulina Cardoso Fuentes  - A01701490,
 * María Fernanda Hernández Montes  - A01704918,
 * Paola Adriana Millares Forno - A01705674
 * @date 28/01/2021
 */

#ifndef BITACORA_HPP
#define BITACORA_HPP

#include <string>
#include <iostream>
#include <sstream> //Lectura de flujos de strings
#include <ostream>

using namespace std;

class Bitacora {
    //Atributos
    private:
        string mes;
        string dia;
        string hora;
        string ipp;
        string falla;
        int clave;
    
    public:
        //Constructor
        Bitacora(string mes, string dia, string hora, string ipp, string falla);
        // Setters y getters
        string getMes() { return this->mes; }
        void setMes(string mes) { this->mes = mes; }
        string getDia() { return this->dia; }
        void setDia(string dia) { this->dia = dia; }
        string getHora() { return this->hora; }
        void setHora(string hora) { this->hora = hora; }
        string getIpp() { return this->ipp; }
        void setIpp(string ipp) { this->ipp = ipp; }
        string getFalla() { return this->falla; }
        void setFalla(string falla) { this->falla = falla; }
        int getClave() { return this->clave; }
        void setClave(int clave) { this->clave = clave; }
        string getHoraIndividual(){return this->hora.substr(0,2); } 
        // Metodos
        string mesANumero();
        void asignarClave();
        string imprimirRegistro();
        string escritura();
        friend ostream & operator << (ostream &os, const Bitacora &b);
};

//=====================================================================
// 
//  Método: Bitacora
//  Descripcíón: Inicializador del objeto
//  Complejidad O(1);
//
//=====================================================================
Bitacora :: Bitacora(string mes, string dia, string hora, string ipp, string falla) { // Constructor
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->ipp = ipp;
    this->falla = falla;
    this->asignarClave(); //Llama al metodo asignar clave
}


//=====================================================================
// 
//  Método: mesANumero
//  Descripcíón: A través de este método nos es posible trabajar con los meses al 
//  identificarlos como valor numérico.
//
//=====================================================================
string Bitacora :: mesANumero() {
    if (!this->mes.compare("Jun")) // ! not
        return "6";
    else if (!this->mes.compare("Jul"))
        return "7";
    else if (!this->mes.compare("Aug"))
        return "8";
    else if (!this->mes.compare("Sep"))
        return "9";
    else if (!this->mes.compare("Oct"))
        return "10";
    else if (!this->mes.compare("Nov"))
        return "11";
    else if (!this->mes.compare("Dec"))
        return "12";
    else if (!this->mes.compare("Jan"))
        return "1";
    else if (!this->mes.compare("Feb"))
        return "2";
    else if (!this->mes.compare("Mar"))
        return "3";
    else if (!this->mes.compare("Apr"))
        return "4";
    else if (!this->mes.compare("May"))
        return "5";
    else
        return "0";
}


//===================================================================
//
//  Método: asignarClave
//  Descripción: Creación de una clave que nos permita realizar la 
//  comparación
//  Complejidad: O(1)
//
//===================================================================
void Bitacora :: asignarClave() { 
    string id = this->mesANumero() + this->dia; //Concatenar el mes con el dia para crear la clave
    stringstream string2int(id);
    string2int >> this->clave; //Conversion de string a int
}

//===================================================================
//
//  Método: imprimirRegistro
//  Descripción: A través de este método mostramos los registros en pantalla
//  Complejidad: O(1)
//
//===================================================================
string Bitacora :: imprimirRegistro() {
    stringstream str;
    str << this->clave << " " << this->mes << " " << this->dia << " " << this->hora << " " << this->ipp << " " << this->falla << "\n";
    return str.str();
}

//===================================================================
//
//  Método: escritura
//  Descripción: Especificamos la manera en la que deberá mostrarse la línea
//  Complejidad: O(1)
//
//===================================================================
string Bitacora :: escritura() {
    return (this->mes + " " + this->dia + " " + this->hora + " " + this->ipp + " " + this->falla);
}

//===================================================================
//
//  Operador: <<
//  Descripción: Sobrecarga de operador
//  Complejidad: O(1)
//
//===================================================================
ostream & operator << (ostream &os,const Bitacora &b) {
    os << b.clave << " " << b.mes << " " << b.dia << " " << b.hora << " " << b.ipp << " " << b.falla << endl;
    return os;
}

#endif