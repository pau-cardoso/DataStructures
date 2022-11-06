#include "Listas.hpp"
#include <iostream>
#include <string>

using namespace std;

void menu(){

    cout << "1. Buscar en la lista\n"; 
    cout << "2. Actualizar la lista\n"; 
    cout << "3. Agregar un elemento a la lista\n";
    cout << "4. Eliminar un elemento de la lista\n";
    cout << "5. Salir\n";

}

int main(){
    int opcion, tam;
    cout << "¿Desea que su lista contenga numeros o palabras?\n";
    cout << "1. Numeros\n";
    cout << "2. Palabras\n";
    cin >> opcion;
    if(opcion == 1){
        Lista<int> lNumerica;
        int valor;
        cout << "¿Cuantos datos quiere agregar a la lista?\n";
        cin >> tam;
        for (int i = 0; i < tam; i++)
        {
            cout << "Ingrese el dato " << i + 1 << endl;
            cin >> valor;
            lNumerica.create(valor);
        }

        lNumerica.imprimirLista();
        do
        {
            menu();
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                int busq;
                cout << "Ingrese el valor que desea buscar\n";
                cin >> valor;
                busq = lNumerica.read(valor);
                lNumerica.imprimirLista();
                if (busq == -1){
                    cout << "No se encontro el numero\n";
                }
                else{
                    cout << "El indice del numero que busco es: " << busq << endl;
                }
                lNumerica.imprimirLista();
                break;
            case 2:
                int n;
                lNumerica.imprimirLista();
                cout << "Ingrese la posicion del numero que desea modificar\n";
                cin >> n;
                cout << "Ingrese el numero por el que quiere remplazarlo\n";
                cin >> valor;
                lNumerica.update(n, valor);
                lNumerica.imprimirLista();
                break;
            case 3:
                cout << "Ingrese el numero que desea agregar\n";
                cin >> valor;
                lNumerica.create(valor);
                lNumerica.imprimirLista();
                break;
            case 4:
                lNumerica.imprimirLista();
                cout << "Ingrese la posicion del numero que desea eliminar\n";
                cin >> valor;
                lNumerica.del(valor);
                lNumerica.imprimirLista();
                break;
            case 5: 
                lNumerica.imprimirLista();
                break;
            case 6:
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << "Opcion invalida\n";
                break;
            }
        } while (opcion != 5);

    }
    else{
        Lista<string> lPalabra;
        string valor;
        cout << "¿Cuantos datos quiere agregar a la lista?\n";
        cin >> tam;
        for (int i = 0; i < tam; i++)
        {
            cout << "Ingrese el dato " << i + 1 << endl;
            cin >> valor;
            lPalabra.create(valor);
        }

        lPalabra.imprimirLista();
        do
        {
            menu();
            cin >> opcion;
            switch (opcion){
            case 1:
                int busq;
                cout << "Ingrese la palabra que desea buscar\n";
                cin >> valor;
                busq = lPalabra.read(valor);
                if(busq == -1){
                    cout << "No se encontro la palabra\n";
                }
                else{
                    cout << "El indice de la palabra que busco es: " << busq << endl;
                }
                lPalabra.imprimirLista();
                break;
            case 2:
                int n;
                lPalabra.imprimirLista();
                cout << "Ingrese la posicion de la palabra que desea modificar\n";
                cin >> n;
                cout << "Ingrese la palabra por la que quiere remplazarla\n";
                cin >> valor;
                lPalabra.update(n, valor);
                lPalabra.imprimirLista();
                break;
            case 3:
                cout << "Ingrese la palabra que desea agregar\n";
                cin >> valor;
                lPalabra.create(valor);
                lPalabra.imprimirLista();
                break;
            case 4:
                lPalabra.imprimirLista();
                cout << "Ingrese la posicion de la palabra que desea eliminar\n";
                cin >> n;
                lPalabra.del(n);
                lPalabra.imprimirLista();
                break;
            case 5:
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << "Opcion invalida\n";
                break;
            }
        } while (opcion != 6);
    }
    return 0;
}