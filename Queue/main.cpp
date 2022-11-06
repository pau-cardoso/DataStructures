#include "queue.hpp"
#include <string>

int main(){
    Queue<string> * queue1=new Queue<string>();
    queue1->push("Lulu");
    queue1->push("Julian");
    queue1->push("Esther");
    queue1->push("Ricardo");
    queue1->imprimirQueueStack();

    cout<<queue1->front()->getValor()<<endl;
    queue1->imprimirQueueStack();

    cout<<queue1->pop()->getValor()<<endl;
    queue1->imprimirQueueStack();
    
    Nodo<string> * nodo=queue1->pop();
    queue1->imprimirQueueStack();
    cout<<nodo->getValor()<<endl;





}