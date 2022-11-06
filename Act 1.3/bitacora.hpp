#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Bitacora {
    // Atributos
    private:
        string mes;
        string dia;
        string hora;
        string tiempo;
        string ipp;
        string falla;
        int clave;
    // Metodos
    public:
        Bitacora(string mes, string dia, string hora, string ipp, string falla);
        string getMes() { return this -> mes;}
        void setMes(string mes) { this -> mes = mes; }
        string getDia() { return this -> dia;}
        void setDia(string dia) { this -> dia = dia; }
        string getHora() { return this -> hora;}
        void setHora(string hora) { this -> hora = hora; }
        string getTiempo() { return this -> tiempo;}
        void setTiempo(string tiempo) { this -> tiempo = tiempo; }
        string getIPP() { return this -> ipp;}
        void setIPP(string ipp) { this -> ipp = ipp; }
        string getFalla() { return this -> falla;}
        void setFalla(string falla) { this -> falla = falla; }
        int getClave() { return this -> clave;}
        void setClave(int clave) { this -> clave = clave; }
        string mesANumero();
        void asignarClave();
        void imprimirRegistro();
};

Bitacora :: Bitacora(string mes, string dia, string hora, string ipp, string falla) {
    this -> mes = mes;
    this -> dia = dia;
    this -> hora = hora;
    this -> ipp = ipp;
    this -> falla = falla;
    // Llamar al metodo asignar clave
}

string Bitacora :: mesANumero() {
    if ( this -> mes.compare("Jun") )
        return "6";
    else if ( this -> mes.compare("Jul") )
        return "7";
    else if ( this -> mes.compare("Aug") )
        return "8";
    else if ( this -> mes.compare("Sep") )
        return "9";
    else if ( this -> mes.compare("Oct") )
        return "10";
    else if ( this -> mes.compare("Nov") )
        return "11";
    else if ( this -> mes.compare("Dec") )
        return "12";
    return "-1";
}

void Bitacora :: asignarClave(){
    string id = this -> mesANumero() + this -> dia; // Concatenar el mes con el dia para crear clave
    stringstream string2int(id);
    string2int >> this -> clave; // Conversion de string a entero
}
void Bitacora :: imprimirRegistro() {
    cout << this-> clave << " " << this-> mes << " " << this-> dia << " " << this-> hora << " " << this-> ipp << " " << this-> falla << endl;
}