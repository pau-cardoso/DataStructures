/**
 * @brief Programa de funciones iterativas, recursivas y directas
 * @author Paulina Cardoso Fuentes - A01701490
 * @date 08/01/2021
 */

#include <iostream>
using namespace std;

/**
 * @brief Calcula la sumatoria de 1 hasta n con un metodo iterativo
 * @param n un entero positivo
 * @return la sumatoria 1 hasta n
 */
int sumaIterativa ( int n ) {

    int resultado = 0;
    for (int i = 1; i <= n; i++) 
        resultado += i;

    return resultado;
}


/**
 * @brief Calcula la sumatoria de 1 hasta n con un metodo recursivo
 * @param n un entero positivo
 * @return la sumatoria 1 hasta n
 */
int sumaRecursiva ( int n ) {

    if ( n == 1 ) {
        return 1;
    }
    return ( n + sumaRecursiva( n-1 ) );
}


/**
 * @brief Calcula la sumatoria de 1 hasta n con un metodo matematico directo
 * @param n un entero positivo
 * @return la sumatoria 1 hasta n
 */
int sumaDirecta ( int n ) {
    return ( ( n * (n + 1) ) / 2 );
}

int main(int argc, char const *argv[]) {
    int n = 5;
    cout << sumaIterativa(n) << endl;
    cout << sumaRecursiva(n) << endl;
    cout << sumaDirecta(n) << endl;
    return 0;
}

