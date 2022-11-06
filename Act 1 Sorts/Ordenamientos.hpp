/**
 * @file Ordenamientos.hpp
 * @brief Funciones para los algoritmos de ordenamiento y búsquedas
 * @author Paulina Cardoso Fuentes - A01701490
 * @date 17/01/2021
 */

#include <vector>
#include <iostream>

using namespace std;

/**!
 * Imprime los elementos de un vector
 * @param vec Vector a imprimir
*/
void imprimirVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

/**!
 * Crea un vector con elementos aleatorios
 * @param vec Vector al que asignar elementos aleatorios
*/
void vectorAleatorio(vector<int> &vec)
{
    srand((unsigned)time(0));
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = rand() % 100;
        cout << vec[i] << " ";
    }
    cout << endl;
}

/**!
 * Funcion para intercambiar la posicion de dos elementos
 * @param v Direccion del vector en el que hacer swap
 * @param i indice de un elemento a intercambiar
 * @param j indice del otro elemento a intercambiar
*/
void swap(vector<int> &v, int i, int j)
{
    int temp = v[i];
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
int particion(vector<int> &v, int inicio, int fin)
{
    int pivot = v[inicio]; // Pivote, sera el primer valor de nuestro arreglo
    int i = inicio + 1; // i inicia despues del pivote
    for (int j = i; j <= fin; j++)
    {
        if (v[j] < pivot)
        {
            swap(v, i, j); // Intercambio de valores
            i++;
        }
    }
    swap(v, inicio, i - 1); // Se intercambia para que el pivote este en medio de los valores comparados
    return i - 1; // Posicion del pivote
}

/**!
 * Funcion recursiva para realizar Quick Sort
 * @param v Vector en el que se realizara el quicksort
 * @param inicio indice de inicio del vector a ordenar
 * @param fin indice del final del vector a ordenar
*/
void quickSort(vector<int> &v, int inicio, int fin)
{
    if (inicio < fin)
    {
        int pivot = particion(v, inicio, fin); // Posicion de pivote
        quickSort(v, inicio, pivot - 1); // Parte izquierda
        quickSort(v, pivot + 1, fin);    // Parte derecha
    }
}

/**!
 * Funcion para integrar nuestro vector ordenado para MergeSort
 * @param v Paso de vector como referencia
 * @param inicio indice del primer elemento en las ramificaciones (inicio)
 * @param mitad indice del elemento a la mitad 
 * @param fin indice del ultimo elemento en las ramificaciones (final)
*/
void merge(vector<int> &v, int inicio, int mitad, int fin)
{
    int i, j, k;
    int n1 = mitad - inicio + 1; // Numero de elementos de izq
    int n2 = fin - mitad;        // Numero de elementos de der
    int left[n1], right[n2];     // Reservar espacio izquierda y derecha

    // Copiar datos de arreglo en izq y der
    for (i = 0; i < n1; i++)
        left[i] = v[inicio + i];
    for (j = 0; j < n2; j++)
        right[j] = v[mitad + 1 + j];

    //Realizar merge cuando tenemos dos arreglos
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    //Vaciar lo que resta del lado derecho
    while (j < n2)
    {
        v[k] = right[j];
        j++;
        k++;
    }

    //Vaciar lo que resta del lado izquierdo
    while (i < n1)
    {
        v[k] = left[i];
        i++;
        k++;
    }
}

/**!
 * Funcion recursiva para el ordenamiento por Merge Sort
 * @param v Pase de vector por referencia
*/
void mergeSort(vector<int> &v, int inicio, int fin)
{
    if (inicio < fin) // Caso de recursión
    {
        int mitad = inicio + (fin - inicio) / 2;

        mergeSort(v, inicio, mitad);  // Parte izq
        mergeSort(v, mitad + 1, fin); // Parte der
        merge(v, inicio, mitad, fin); // Juntar nuestro arreglo
    }
    // Caso base
}

// ----------------------------------------------------------------------------

/**!
 * Metodo de ordenamiento de insercion
 * 
 * @note La complejidad de Big O de este método de ordenamiento es de O(n^2)
 * 
 * @param v Copia de vector a ordenar
*/
void ordenaInsercion(vector<int> v)
{
    //
    int i, j, aux;
    for (i = 1; i < v.size(); i++) // Pasadas
    { 
        j = i;
        aux = v[i];
        while (j > 0 && aux < v[j - 1]) //Intercambios
        { 
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }
    imprimirVector(v);
}


/**!
 * Metodo de ordenamiento de burbuja
 * 
 * @note La complejidad de Big O de este método de ordenamiento es de O(n^2) 
 * 
 * @param v Copia de vector a ordenar
*/
void ordenaBurbuja(vector<int> v)
{
    // Declaracion individual de variables
    bool flag = true;
    int i, j, aux;
    for (i = 0; i < v.size() && flag; i++)
    {
        flag = false;
        for (j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j + 1] < v[j])
            {
                swap(v, j, j + 1);
                flag = true;
            }
        }
    }
    imprimirVector(v);
}


/**!
 * Metodo de ordenamiento por Quicksort 
 * Esta funcion sirve como ayuda para llamar a quickSort donde se desarrollará el método
 * 
 * @note La complejidad de Big O de este método de ordenamiento es de O(n^2)
 * 
 * @param v Copia de vector a ordenar
*/
void ordenaQuicksort(vector<int> v)
{
    quickSort(v, 0, v.size() - 1); // Funcion auxiliar para el paso de parametros correctos
    imprimirVector(v);
}


/**!
 * Metodo de ordenamiento de Merge
 * 
 * @note La complejidad de Big O de este método de ordenamiento es de O(n log n)
 * 
 * @param v Copia de vector a ordenar
*/
void ordenaMerge(vector<int> &v)
{
    mergeSort(v, 0, v.size() - 1); // Funcion auxiliar para el paso de parametros correctos
    imprimirVector(v);
}


/**!
 * Busca el valor de un dato dado en un vector dado 
 * con el metodo secuencial 
 * 
 * @note Esta busqueda tiene una complejidad Big O de O(n)
 * 
 * @param v Vector en el que buscar el dato
 * @param dato Dato que buscar en el vector
 * @param comparaciones entero que cuenta las comparaciones dada por referencia
 * @return Indice del elemento que se busca o -1 si no se encuentra
*/
int busqSecuencial(vector<int> &v, int dato, int &comparaciones)
{
    comparaciones = 0;
    for (int i = 0; i < v.size(); i++)
    {
        comparaciones++;
        if (v[i] == dato)
            return i;
    }
    return -1;
}

/**!
 * Busca el valor de un dato dado en un 
 * vector dado con el metodo Binario.
 * 
 * @note Esta busqueda tiene una complejidad Big O de O(log n)
 * 
 * @param v Vector en el que buscar el dato
 * @param dato Dato que buscar en el vector
 * @param comparaciones entero que cuenta las comparaciones dada por referencia
 * @return Indice del elemento que se busca o -1 si no se encuentra
*/
int busqBinaria(vector<int> &v, int dato, int &comparaciones)
{
    comparaciones = 0;
    int inicio = 0, fin = v.size() - 1, mitad, valMitad;
    while (inicio <= fin)
    {
        mitad = (fin + inicio) / 2;
        valMitad = v[mitad];

        if (dato == valMitad)
        {
            comparaciones++;
            return mitad;
        }
        else if (dato < valMitad)
        {
            comparaciones += 2;
            fin = mitad - 1;
        }
        else
        {
            comparaciones += 3;
            inicio = mitad + 1;
        }
    }
    return -1;
}


/**!
 * Función para ayudar a la impresión de las búsquedas
 * @param busq Identificador para busqueda binaria o secuencial
 * @param v Vector en el que se haran las búsquedas
 * @param dato Dato a buscar en el vector
*/
void busquedas(string busq, vector<int> &v, int dato)
{
    int comparaciones, pos;
    // Se realizan las búsquedas llamando al metodo correspondiente
    if (busq == "binaria") // Busqueda binaria
        pos = busqBinaria(v, dato, comparaciones);
    else // Busqueda secuencial
        pos = busqSecuencial(v, dato, comparaciones);

    // Imprime los resultados de la posicion del dato y el numero de comparaciones
    if (pos != -1)
    {
        cout << "El número sí está, en la posición " << pos << endl;
        cout << "Comparaciones: " << comparaciones << endl;
    }
    else
    {
        cout << "El número no se encuentra" << endl;
        cout << "Comparaciones: " << comparaciones << endl;
    }
}