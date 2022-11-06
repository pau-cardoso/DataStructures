/**
 * @file IP.hpp
 * @brief Implementacion de la clase IP
 * @authors 
 * Paulina Cardoso Fuentes  - A01701490,
 * María Fernanda Hernández Montes  - A01704918,
 * Paola Adriana Millares Forno - A01705674
 * @date 02/02/2021
 */

#ifndef IP_HPP
#define IP_HPP

using namespace std;

class IP {
    private:
        string ip;
        int accesos;
        IP *siguiente;
        IP *anterior;
    public:
        // Constructor y destructor
        IP(string ip, IP *siguiente, IP *anterior);
        ~IP();
        // Getters y setters
        string getIP() { return this->ip; }
        void setIP(string ip) { this->ip = ip; }
        int getAccesos() { return this->accesos; }
        void setAccesos(int accesos) { this->accesos = accesos; }
        IP *getSiguiente() { return this->siguiente; }
        void setSiguiente(IP *siguiente) { this->siguiente = siguiente; }
        IP *getAnterior() { return this->anterior; }
        void setAnterior(IP *anterior) { this->anterior = anterior; }
        // Metodos
        void aumentarAccesos();
        string imprimirIP();
};

//=====================================================================
//
//  Método: IP
//  Descripcíón: Inicializador del objeto
//  Complejidad: O(1)
//
//=====================================================================
IP::IP(string ip, IP *siguiente, IP *anterior) {
    this->ip = ip;
    accesos = 1;
    this->siguiente = siguiente;
    this->anterior = anterior;
}

//=====================================================================
//
//  Método: ~IP
//  Descripcíón: Destructor del objeto
//  Complejidad: O(1)
//
//=====================================================================
IP::~IP() {
}

//=====================================================================
//
//  Método: aumentarOcurrencias
//  Descripcíón: Aumenta el número de ocurrencias
//  Complejidad: O(1)
//
//=====================================================================
void IP::aumentarAccesos() {
    accesos++;
}

//=====================================================================
//
//  Método: imprimirOcurrencias
//  Descripcíón: Se encarga de mostrar las ocurrencias en un string
//  Complejidad: O(1)
//
//=====================================================================
string IP::imprimirIP() {
    stringstream aux;
    aux << ip << " " << accesos;
    return aux.str();
}
// ip, accesos
// 25.122.114.4:8001 accesos: 3

#endif