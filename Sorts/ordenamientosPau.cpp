#include <iostream> // input y output
#include <stdlib.h> // numeros aleatorios
#include <time.h> // hora de la computadora

using namespace std;

// generar un arreglo
void generarArreglo( int arreglo[], int tam) {
    srand( (unsigned)time(0)); // inicializar la semilla de generacion de numeros aleatorios
    for (int i = 0; i < tam; i++)
        arreglo[i] = rand()%100;
}

// imprimir un arreglo
void imprimirArreglo( int arreglo[], int tam) {
    for (int i = 0; i < tam; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

void metodoIntercambio( int arreglo[], int n) {
    int i, j, aux;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arreglo[j] < arreglo[i]) { 
                aux = arreglo[j];
                arreglo[j] = arreglo[i];
                arreglo[i] = aux;
            }   
        }
    }
}

void metodoBurbuja( int arreglo[], int n ) {
    // Declaracion individual de variables
    bool flag = true;
    int i, j, aux;
    for ( i=0; i < n && flag; i++) {
        flag = false;
        for ( j=0; j < n-1-i; j++) {
            if (arreglo[j+1] < arreglo[j]) { 
                aux = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
                flag = true;
            }
        }   
    }
}

void metodoSeleccion( int arreglo[], int n ) {
    int pasada, j, indiceMenor, aux;
    for ( pasada=0; pasada < n-1; pasada++) {
        indiceMenor = pasada;
        // Busqueda del menor valor
        for ( j=indiceMenor+1; j<n; j++) {
            if (arreglo[j] < arreglo[indiceMenor] )
                indiceMenor = j; // Actualizar el indice del elemento menor actual
        }
        // swap o intercambio
        aux = arreglo[pasada];
        arreglo[pasada] = arreglo[indiceMenor];
        arreglo[indiceMenor] = aux;
    }
}

int main() {
    int tam;
    cout << "Ingrese el tamaño del arreglo: "; // Imprimir el mensaje en pantalla
    cin >> tam;
    int arreglo [tam];
    // Metodo intercambio
    generarArreglo(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    metodoIntercambio(arreglo, tam);
    imprimirArreglo(arreglo, tam);

    // Metodo burbuja
    cout << "Ingrese el tamaño del arreglo: "; 
    cin >> tam;
    int arreglo1 [tam];
    generarArreglo(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    metodoBurbuja(arreglo, tam);
    imprimirArreglo(arreglo, tam);

    // Metodo seleccion
    cout << "Ingrese el tamaño del arreglo: "; 
    cin >> tam;
    int arreglo2 [tam];
    generarArreglo(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    metodoSeleccion(arreglo, tam);
    imprimirArreglo(arreglo, tam);
}