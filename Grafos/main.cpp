#include "grafo.hpp"

int main(){
    Grafo<string> * ejemploGrafo=new Grafo<string>();
    ejemploGrafo->insertarNodoGrafo("Monterrey");
    ejemploGrafo->insertarNodoGrafo("Cd. Victoria");
    ejemploGrafo->insertarNodoGrafo("CDMX");
    ejemploGrafo->insertarNodoGrafo("Torreón");
    ejemploGrafo->agregarArco("CDMX","Cd. Victoria",1);
    ejemploGrafo->agregarArco("CDMX","Torreón",1);
    ejemploGrafo->agregarArco("Monterrey","Cd. Victoria",1);
    ejemploGrafo->agregarArco("Monterrey","Torreón",1);
    ejemploGrafo->agregarArco("Torreón","Monterrey",1);
    ejemploGrafo->agregarArco("Torreón","CDMX",1);    
    ejemploGrafo->agregarArco("Cd. Victoria","Monterrey",1);
    ejemploGrafo->agregarArco("Cd. Victoria","CDMX",1);
    ejemploGrafo->imprimirGrafo();

    ejemploGrafo->BreadthFirst(5);
    ejemploGrafo->DepthFirst(2);

}