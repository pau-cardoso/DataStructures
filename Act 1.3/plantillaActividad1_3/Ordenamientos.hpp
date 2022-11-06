/*
 * Creado por : 
 * 
 *   María Fernanda Hernández Montes  - A01704918
 *   Paulina Cardoso Fuentes  - A01701490 
 *   Paola Adriana Millares Forno - A01705674
 *
 * Fecha: 20/01/2021
*/

#ifndef ORDENAMIENTOS_HPP
#define ORDENAMIENTOS_HPP

#include <vector>
#include "bitacora.hpp"

/**!
 * Funcion para intercambiar la posicion de dos elementos
 * @param v Direccion del vector en el que hacer swap
 * @param i indice de un elemento a intercambiar
 * @param j indice del otro elemento a intercambiar
*/
template <class T>
void swap(vector<T> &v, int i, int j){
    T temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/**!
 * Particion para acomodar valores menores a un pivote de un lado para el ordenamiento por QuickSort
 * @see quickSort()
 * @param v Vector en el que hacer particion
 * @param inicio indice de inicio para la particion
 * @param fin indice del final del vector a particionar
*/
template <class T>
int particion(vector<T> &v, int inicio, int fin)
{
    int pivot = v[inicio]->getClave(); // Pivote, sera el primer valor de nuestro arreglo
    int i = inicio + 1;                // i inicia despues del pivote
    for (int j = i; j <= fin; j++){
        if (v[j]->getClave() < pivot){
            swap(v, i, j); // Intercambio de valores
            i++;
        }
    }
    swap(v, inicio, i - 1); // Se intercambia para que el pivote este en medio de los valores comparados
    return i - 1;           // Posicion del pivote
}

/**!
 * Funcion recursiva para realizar Quick Sort
 * @param v Vector en el que se realizara el quicksort
 * @param inicio indice de inicio del vector a ordenar
 * @param fin indice del final del vector a ordenar
*/
template <class T>
void quickSort(vector<T> &v, int inicio, int fin){
    if (inicio < fin){
        int pivot = particion(v, inicio, fin); // Posicion de pivote
        quickSort(v, inicio, pivot - 1);       // Parte izquierda
        quickSort(v, pivot + 1, fin);          // Parte derecha
    }
}

/**!
 * Metodo de ordenamiento por Quicksort 
 * Esta funcion sirve como ayuda para llamar a quickSort donde se desarrollará el método
 * 
 * @note La complejidad de Big O de este método de ordenamiento es de O(n^2)
 * 
 * @param v Copia de vector a ordenar
*/
template <class T>
void ordenaQuicksort(vector<T> &v){
    quickSort(v, 0, v.size() - 1); // Funcion auxiliar para el paso de parametros correctos
}

/**!
 * Busca el valor de un dato dado en un 
 * vector dado con el metodo Binario.
 * 
 * @note Esta busqueda tiene una complejidad Big O de O(log n)
 * 
 * @param v Vector en el que buscar el dato
 * @param dato Dato que buscar en el vector
 * @return Indice del elemento que se busca o -1 si no se encuentra
*/
template <class T>
int busqBinaria(vector<T> &v, int dato){
    int inicio = 0, fin = v.size() - 1, mitad, valMitad;
    while (inicio <= fin){
        mitad = (fin + inicio) / 2;
        valMitad = v[mitad] -> getClave();

        if (dato == valMitad)
            return mitad;

        else if (dato < valMitad)
            fin = mitad - 1;

        else
            inicio = mitad + 1;
    }
    return inicio;
}

#endif