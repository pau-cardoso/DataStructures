#include "grafo.hpp"
#include <fstream>

int main(){
    Grafo<string> * ejemploGrafo=new Grafo<string>();
    ifstream datos;
    datos.open("bitacoraCompleta1.txt");
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

    // Solucion punto 4
    Lista<string> *listaIP = new Lista<string>();
    int maxPeso = 0;
    // Recorrer la lista de nodoGrafo
    Nodo<NodoGrafo<string>*> *actual = ejemploGrafo->getNodos()->getHead();
    while (actual) {
        // Recorrer la lista de los arcos del nodoGrafo actual
        int sumPeso = 0;
        Nodo<Arco<string>*>* nodoArco = actual->getValor()->getArcos()->getHead();

        // Sumar los pesos asociados a cada arco
        while (nodoArco) {
            sumPeso = sumPeso + nodoArco->getValor()->getPeso();
            nodoArco = nodoArco->getSiguiente();
        }

        // Buscar el nodoGrafo o nodosGrafos que tenga la suma de pesos mayor
        if (sumPeso == maxPeso)
            listaIP->agregarInicio(actual->getValor()->getValor());
        else if (sumPeso > maxPeso) {
            maxPeso = sumPeso;
            delete listaIP; // Liberar el espacio de memoria de la lista anterior 
            listaIP = new Lista<string>();
            listaIP->agregarInicio(actual->getValor()->getValor());
        }
        actual = actual->getSiguiente();
    }
    cout << "Cual o cuales son las direcciones IP que generan mas fallas?" << endl; 
    listaIP->imprimirLista();
    cout << "Numero de fallas: " << maxPeso << endl;

    datos.close();
    return 0;    
}