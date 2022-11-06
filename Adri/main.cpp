#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

#include "Sorts.hpp"

using namespace std;

void reiniciarVector1(vector<int> v, int a[]){
    for(int i = 0; i < 5; i++){
        v[i] = a[i];
    }
}
void reiniciarVector2(vector<int> v, int a[]){
    for (int i = 0; i < 7; i++){
        v[i] = a[i];
    }
}
void reiniciarVector3(vector<int> v, int a[]){
    for (int i = 0; i < 13; i++){
        v[i] = a[i];
    }
}
void reiniciarVector4(vector<int> v, int a[]){
    for (int i = 0; i < 20; i++){
        v[i] = a[i];
    }
}

int main(){

    Sorts<int> prueba;
    int a1[] = {2, 5, 1, 3, 4};
    int a2[] = {15, 18, 5, 0, 1, 16, 19};
    int a3[] = {1, 2, 3, 4, 5, 6, 7, 0, 92, 0, 11, 15, 92};
    int a4[] = {58, 92, 75, 5, 21, 92, 84, 91, 64, 54, 3, 28, 11, 61, 65, 4, 1, 8, 52, 78};

    vector<int> v1 = {2, 5, 1, 3, 4};
    vector<int> res1 = {1, 2, 3, 4, 5};

    vector<int> v2 = {15, 18, 5, 0, 1, 16, 19};
    vector<int> res2 = {0, 1, 5, 15, 16, 18, 19};

    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 0, 92, 0, 11, 15, 92};
    vector<int> res3 = {0, 0, 1, 2, 3, 4, 5, 6, 7, 11, 15, 92, 92};

    vector<int> v4 = {58, 92, 75, 5, 21, 92, 84, 91, 64, 54, 3, 28, 11, 61, 65, 4, 1, 8, 52, 78};
    vector<int> res4 = {1, 3, 4, 5, 8, 11, 21, 28, 52, 54, 58, 61, 64, 65, 75, 78, 84, 91, 92, 92};

    cout << "Ordenamiento Intercambio\n";
    cout << "1. " << (res1 == prueba.ordenaIntercambio(v1) ? "succes\n" : "fail\n");
    cout << "2. " << (res2 == prueba.ordenaIntercambio(v2) ? "succes\n" : "fail\n");
    cout << "3. " << (res3 == prueba.ordenaIntercambio(v3) ? "succes\n" : "fail\n");
    cout << "4. " << (res4 == prueba.ordenaIntercambio(v4) ? "succes\n" : "fail\n");
    cout << "\n";

    reiniciarVector1(v1, a1);
    reiniciarVector2(v2, a2);
    reiniciarVector3(v3, a3);
    reiniciarVector4(v4, a4);

    cout << "Ordenamiento Burbuja\n";
    cout << "1. " << (res1 == prueba.ordenaBurbuja(v1) ? "succes\n" : "fail\n");
    cout << "2. " << (res2 == prueba.ordenaBurbuja(v2) ? "succes\n" : "fail\n");
    cout << "3. " << (res3 == prueba.ordenaBurbuja(v3) ? "succes\n" : "fail\n");
    cout << "4. " << (res4 == prueba.ordenaBurbuja(v4) ? "succes\n" : "fail\n");
    cout << "\n";

    reiniciarVector1(v1, a1);
    reiniciarVector2(v2, a2);
    reiniciarVector3(v3, a3);
    reiniciarVector4(v4, a4);

    cout << "Ordenamiento Merge\n";
    cout << "1. " << (res1 == prueba.ordenaMerge(v1) ? "succes\n" : "fail\n");
    cout << "2. " << (res2 == prueba.ordenaMerge(v2) ? "succes\n" : "fail\n");
    cout << "3. " << (res3 == prueba.ordenaMerge(v3) ? "succes\n" : "fail\n");
    cout << "4. " << (res4 == prueba.ordenaMerge(v4) ? "succes\n" : "fail\n");
    cout << "\n";

    reiniciarVector1(v1, a1);
    reiniciarVector2(v2, a2);
    reiniciarVector3(v3, a3);
    reiniciarVector4(v4, a4);

    cout << "Ordenamiento Quick\n";
    cout << "1. " << (res1 == prueba.ordenaQuick(v1, 0, v1.size()-1) ? "succes\n" : "fail\n");
    cout << "2. " << (res2 == prueba.ordenaQuick(v2, 0, v2.size() - 1) ? "succes\n" : "fail\n");
    cout << "3. " << (res3 == prueba.ordenaQuick(v3, 0, v3.size() - 1) ? "succes\n" : "fail\n");
    cout << "4. " << (res4 == prueba.ordenaQuick(v4, 0, v4.size() - 1) ? "succes\n" : "fail\n");
    cout << "\n";

    cout << "Busqueda secuencial\n";
    cout << "1. " << (3 == prueba.busqSecuencial(res1, 4) ? "success\n" : "fail\n");
    cout << "2. " << (-1 == prueba.busqSecuencial(res2, 100) ? "success\n" : "fail\n");
    cout << "3. " << (0 == prueba.busqSecuencial(res3, 0) ? "success\n" : "fail\n");
    cout << "4. " << (17 == prueba.busqSecuencial(res4, 91) ? "success\n" : "fail\n");
    cout << "\n";

    cout << "Busqueda binaria\n";
    cout << "1. " << (3 == prueba.busqBinaria(res1, 4) ? "success\n" : "fail\n");
    cout << "2. " << (4 == prueba.busqBinaria(res2, 16) ? "success\n" : "fail\n");
    cout << "3. " << (0 == prueba.busqBinaria(res3, 0) ? "success\n" : "fail\n");
    cout << "4. " << (17 == prueba.busqBinaria(res4, 91) ? "success\n" : "fail\n");
    cout << "\n";
    return 0;
}
