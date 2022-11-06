//Bibliotecas
#include <iostream> //input y output
#include <stdlib.h> // números aleatorios
#include <time.h>   //hora de la computadora

using namespace std; //Definir el espacio de nombres

//generar un arreglo aleatorio
void generarArreglo(int arreglo[], int tam)
{
    srand((unsigned)time(0)); //inicializar la semilla de generación de numeros aleatorios
    //srand(7); //inicializar la semilla de generación de numeros aleatorios
    for (int i = 0; i < tam; i++)
        arreglo[i] = rand() % 100; //rand regresa un número pseudo aleatori en tre 0 y el número máximo que pueda expresar la computadora
}

//imprimir un arreglo
void imprimirArreglo(int arreglo[], int tam)
{
    for (int i = 0; i < tam; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}

void metodoIntercambio(int arreglo[], int n)
{
    int i, j, auxiliar; // declaración conjunta de variables del mismo tipo
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arreglo[j] < arreglo[i])
            {
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[i];
                arreglo[i] = auxiliar;
            }
        }
    }
}

void metodoBurbuja(int arreglo[], int n)
{
    //Declaración individual de variables
    bool flag = true;
    int i;
    int j;
    int auxiliar;
    for (i = 0; i < n && flag; i++)
    {
        flag = false;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arreglo[j + 1] < arreglo[j])
            {
                //swap o intercambio
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = auxiliar;
                flag = true;
            }
        }
    }
}

void metodoSeleccion(int arreglo[], int n)
{
    int pasada, j, indicemenor, aux;
    for (pasada = 0; pasada < n - 1; pasada++)
    {
        indicemenor = pasada;
        //Busqueda del indice del menor valor
        for (j = indicemenor + 1; j < n; j++)
            if (arreglo[j] < arreglo[indicemenor])
                indicemenor = j; //Actualizar el indice del elemento menor actual
        //swap o intercambio
        aux = arreglo[pasada];
        arreglo[pasada] = arreglo[indicemenor];
        arreglo[indicemenor] = aux;
    }
}

void metodoInsercion(int arreglo[], int n)
{
    int i, j, aux;
    for (i = 1; i < n; i++)
    { //Pasadas
        j = i;
        aux = arreglo[i];
        while (j > 0 && aux < arreglo[j - 1])
        { //Intercambios
            arreglo[j] = arreglo[j - 1];
            j--;
        }
        arreglo[j] = aux;
    }
}

void merge(int arreglo[], int inicio, int mitad, int fin)
{
    int i, j, k;
    int n1 = mitad - inicio + 1; //numero de elementos de izq
    int n2 = fin - mitad;        //numero de elementos de der
    // Reservar espacio derecha e izquierda
    int Izq[n1], Der[n2];
    // Copiar datos de arreglo en izq y der
    for (i = 0; i < n1; i++)
        Izq[i] = arreglo[inicio + i];
    for (j = 0; j < n2; j++)
        Der[j] = arreglo[mitad + 1 + j];

    //Realizar merge cuando tenemos dos arreglos
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (Izq[i] <= Der[j])
        {
            arreglo[k] = Izq[i];
            i++;
        }
        else
        {
            arreglo[k] = Der[j];
            j++;
        }
        k++;
    }

    //Vaciar lo que resta de der
    while (j < n2)
    {
        arreglo[k] = Der[j];
        j++;
        k++;
    }

    //Vaciar lo que resta de izq
    while (i < n1)
    {
        arreglo[k] = Izq[i];
        i++;
        k++;
    }
}

void mergeSort(int arreglo[], int inicio, int fin)
{
    if (inicio < fin)
    { //Caso de recursión
        int mitad = inicio + (fin - inicio) / 2;
        mergeSort(arreglo, inicio, mitad);  //Parte izq
        mergeSort(arreglo, mitad + 1, fin); //Parte der

        merge(arreglo, inicio, mitad, fin); //Integrar nuestro arreglo
    }
    //Caso base
}

int main()
{
    int tam;
    cout << "Ingrese el tamaño del arreglo: "; //Imprimir un mensaje en pantalla
    cin >> tam;
    int arreglo[tam];
    //Ejemplo
    generarArreglo(arreglo, tam);
    imprimirArreglo(arreglo, tam);
    mergeSort(arreglo, 0, tam - 1);
    imprimirArreglo(arreglo, tam);
    return 0;
}
