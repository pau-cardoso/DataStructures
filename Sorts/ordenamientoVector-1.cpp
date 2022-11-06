#include <vector> //Estructura de control para manejar arreglos
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <typeinfo> 

using namespace std;

//C++ 11
void imprimirVector11(vector<int> vec){
    for(int elemento:vec)
        cout<<elemento<<" ";
    cout<<endl;    
}

void imprimirVector(vector<int> vec){
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

//void vectorAleatorio(vector<int> vec){ Paso como copia

void vectorAleatorio(vector<int> &vec){ //Paso como referencia
    srand((unsigned)time(0));
    for(int i=0; i<vec.size(); i++){ 
        vec[i] = rand()%100;         
        cout << vec[i] <<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a (10);  //vector<tipoDato> nombreVariable  -> generar un vector de 0´s de 10 posiciones
    auto b={1, 3, 4, 5, 6, 7}; // Es un vector<int> 
    
    vector<int> c (5,9);// (tamaño, valor inicial) 
    vector<int> d = { 3,4,5,6,7,8};
    vector<int> e {4,6,4,3,5};

    vectorAleatorio(a);
    imprimirVector(a);
    imprimirVector(b);
    imprimirVector(c);
    imprimirVector(d);
    imprimirVector(e);        
}