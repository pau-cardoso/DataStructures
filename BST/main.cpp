#include <iostream>
#include "bst.hpp"
#include "Queue.hpp"

using namespace std;

int main(){
    BST<int> * arbol=new BST<int>(); // Creacion de un nuevo arbol binario
    int opcion, valNodo, predecesor; 
    
    // Se agregan nodos al arbol
    arbol->agregaNodoIterativo(60);
    arbol->agregaNodoIterativo(74);
    arbol->agregaNodoIterativo(41);
    arbol->agregaNodoIterativo(53);
    arbol->agregaNodoIterativo(55);
    arbol->agregaNodoIterativo(16);
    arbol->agregaNodoIterativo(25);
    arbol->agregaNodoIterativo(65);
    arbol->agregaNodoIterativo(63);
    arbol->agregaNodoIterativo(70);
    arbol->agregaNodoIterativo(62);
    arbol->agregaNodoIterativo(46);
    arbol->agregaNodoIterativo(64);
    arbol->agregaNodoIterativo(42);
    arbol->imprimirArbolInOrder();
    
    // Funcion visit() para imprimir el arbol
    // La funcion visit tiene una complejidad O(n)
    cout << "De que manera desea imprimir el arbol? Introduzca el numero" << endl;
    cout << "\n1. Preorder\n2. Postorder\n3. Level by level" << endl;
    cin >> opcion;
    arbol->visit(opcion);

    // Funcion height() para imprimir la altura del arbol
    // La funcion height tiene una complejidad O(n)
    cout << "\nLa altura del arbol es: " << arbol->height() << endl;
    
    // Funcion antecesor() para conocer el predecesor de un nodo
    // La funcion antecesor tiene una complejidad O(n)
    for (int i = 0; i < 2; i++) {
        cout << "\nIntroduzca el valor del nodo del que desea saber su antecesor(predecesor): ";
        cin >> predecesor;
        if (!arbol->antecesor(predecesor)) 
            cout << "No existe ese valor o no tiene antecesor" << endl;
        else
            cout << "El valor del nodo antecesor de " << predecesor << " es: " << arbol->antecesor(predecesor)->getValor() << endl;
    }

    // Funcion whatLevelAmI() para saber el nivel de un nodo
    // La funcion whatLevelAmI tiene una complejidad O(n)
    for (int i = 0; i < 2; i++) {
        cout << "\nIntroduzca el valor del nodo del que desea saber su nivel: ";
        cin >> valNodo;
        cout << "El nivel del nodo con valor " << valNodo << " es: " << arbol->whatLevelAmI(valNodo) << endl;
    }

    cout << endl;
    
    return 0;
}