/*
 * Creado por : 
 * 
 *   María Fernanda Hernández Montes  - A01704918
 *   Paulina Cardoso Fuentes  - A01701490 
 *   Paola Adriana Millares Forno - A01705674
 *
 * Fecha: 20/01/2021
*/

#ifndef BITACORA_HPP
#define BITACORA_HPP

#include <string>
#include <iostream>
#include <sstream> //Lectura de flujos de strings

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
    //Métodos
public:
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

    Bitacora(string mes, string dia, string hora, string ipp, string falla){
        this->mes = mes;
        this->dia = dia;
        this->hora = hora;
        this->ipp = ipp;
        this->falla = falla;
        //Llamar al metodo asignar clave
        this->asignarClave();
    }

    string mesANumero(){
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

    void asignarClave(){
        string id = this->mesANumero() + this->dia; //Concatenar el mes con el dia para crear la clave
        stringstream string2int(id);
        string2int >> this->clave; //Conversion de string a int
    }

    void imprimirRegistro(){
        cout << this->clave << " " << this->mes << " " << this->dia << " " << this->hora << " " << this->ipp << " " << this->falla << "\n";
    }

    string escritura(){
        return (this->mes + " " + this->dia + " " + this->hora + " " + this->ipp + " " + this->falla);
    }
};

#endif