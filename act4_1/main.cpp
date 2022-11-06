#include "grafo.hpp"
#include <fstream>

int main(){
    Grafo<string> * ejemploGrafo=new Grafo<string>();
    ifstream datos;
    datos.open("bitacoraTest1.txt");
    string aux,ip1,ip2;
    
    //1.-Construcción del grafo
    while(datos.good()){
        getline(datos,aux,' ');
        getline(datos,aux,' ');
        getline(datos,aux,' ');
        getline(datos,ip1,' ');
        getline(datos,ip2,' ');
        getline(datos,aux);
        //Agregar ips de origen y destino si es que no existen
        if(!ejemploGrafo->buscarNodo(ip1))
            ejemploGrafo->insertarNodoGrafo(ip1);
        if(!ejemploGrafo->buscarNodo(ip2))
            ejemploGrafo->insertarNodoGrafo(ip2);
        //Agregar el arco
        Arco<string> * arcoNuevo= ejemploGrafo->buscarArco(ip1, ip2);
        if(arcoNuevo)
            arcoNuevo->setPeso(arcoNuevo->getPeso()+1);//Ya existe el arco entonces solo actualizo el peso
        else
            ejemploGrafo->agregarArco(ip1,ip2,1);        
    }

    ejemploGrafo->imprimirGrafo();
    datos.close();
    return 0;    
}