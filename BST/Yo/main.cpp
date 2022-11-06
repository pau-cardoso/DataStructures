#include <iostream>
#include "Bst.hpp"

int main(){ 
    BST<int> * arbol = new BST<int>();
    arbol -> agregarNodoIterativo(50);
    arbol -> agregarNodoIterativo(30);
    arbol -> agregarNodoIterativo(20);
    arbol -> agregarNodoIterativo(40);
    arbol -> agregarNodoIterativo(50);
    return 0; 
}