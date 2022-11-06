/**
 * @file Fallas.hpp
 * @brief Implementacion de la clase Falla
 * @authors 
 * Paulina Cardoso Fuentes  - A01701490,
 * María Fernanda Hernández Montes  - A01704918,
 * Paola Adriana Millares Forno - A01705674
 * @date 26/01/2021
 */

#ifndef FALLA_HPP
#define FALLA_HPP

#include <string>

using namespace std;

class Falla
{
private:
    string falla;
    int ocurrencias;
    int ocurrenciasMes[12] = {};
    Falla *siguiente;
    Falla *anterior;
public:
    // Constructor y destructor
    Falla(string falla, int mes, Falla *siguiente, Falla *anterior);
    ~Falla();
    // Getters y setters
    string getFalla() { return this->falla; }
    void setFalla(string falla) { this->falla = falla; }
    int getOcurrencias() { return this->ocurrencias; }
    void setOcurrencias(int ocurrencias) { this->ocurrencias = ocurrencias; }
    Falla *getSiguiente() { return this->siguiente; }
    void setSiguiente(Falla *siguiente) { this->siguiente = siguiente; }
    Falla *getAnterior() { return this->anterior; }
    void setAnterior(Falla *anterior) { this->anterior = anterior; }
    // Metodos
    void aumentarOcurrencias(int mes);
    string imprimirOcurrencias();
};

//=====================================================================
// 
//  Método: Falla
//  Descripcíón: Inicializador del objeto
//
//=====================================================================
Falla::Falla(string falla, int mes, Falla *siguiente, Falla *anterior) {
    this->falla = falla;
    ocurrencias = 1;
    ocurrenciasMes[mes-1] = 1;
    this->siguiente = siguiente;
    this->anterior = anterior;
}

//=====================================================================
// 
//  Método: ~Falla
//  Descripcíón: Destructor del objeto
//
//=====================================================================
Falla::~Falla() {
}

//=====================================================================
// 
//  Método: aumentarOcurrencias
//  Descripcíón: Aumenta el número de ocurrencias
//
//=====================================================================
void Falla::aumentarOcurrencias(int mes) {
    ocurrencias++;
    ocurrenciasMes[mes-1]++;
}

//=====================================================================
// 
//  Método: imprimirOcurrencias
//  Descripcíón: Se encarga de mostrar las ocurrencias en un string
//
//=====================================================================
string Falla::imprimirOcurrencias() {
    stringstream aux;
    aux << "\nFalla: " << falla << endl;
    aux << "\nOcurrencias totales: " << ocurrencias << endl;
    aux << "Enero:\t\t" << ocurrenciasMes[0] << endl;
    aux << "Febrero:\t" << ocurrenciasMes[1] << endl;
    aux << "Marzo:\t\t" << ocurrenciasMes[2] << endl;
    aux << "Abril:\t\t" << ocurrenciasMes[3] << endl;
    aux << "Mayo:\t\t" << ocurrenciasMes[4] << endl;
    aux << "Junio:\t\t" << ocurrenciasMes[5] << endl;
    aux << "Julio:\t\t" << ocurrenciasMes[6] << endl;
    aux << "Agosto:\t\t" << ocurrenciasMes[7] << endl;
    aux << "Septiembre:\t" << ocurrenciasMes[8] << endl;
    aux << "Octubre:\t" << ocurrenciasMes[9] << endl;
    aux << "Noviembre:\t" << ocurrenciasMes[10] << endl;
    aux << "Diciembre:\t" << ocurrenciasMes[11] << endl;
    return aux.str();
}

#endif