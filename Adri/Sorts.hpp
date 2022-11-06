#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Sorts{
    
    private:
        void swap(vector<T> &, int, int);
        void mergeSplit(vector<T> &, vector<T> &, int, int);
        void mergeArray(vector<T> &, vector<T> &, int, int, int);
        void copyArray(vector<T> &, vector<T> &, int, int);
        int partition(vector<T> &, int, int);

    public:
        vector<T> ordenaIntercambio(vector<T> &);
        vector<T> ordenaBurbuja(vector<T> &);
        vector<T> ordenaMerge(vector<T> &);
        vector<T> ordenaQuick(vector<T> &, int , int);
        int busqSecuencial(vector<T> &, int);
        int busqBinaria(vector<T> &, int);
};

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j){

    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
vector<T> Sorts<T>::ordenaIntercambio(vector<T> &v){
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
        
            if(v[j] > v[i]){
                swap(v, i, j);
            }
        }
    }
    return v;
}

template <class T>
vector<T> Sorts<T>::ordenaBurbuja(vector<T> &v){

    for (int i = v.size() - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
        
            if (v[j] > v[j + 1]){
                swap(v, j, j + 1);
            }
        }
    }
    return v;
}

template <class T>
vector<T> Sorts<T>::ordenaMerge(vector<T> &v){
    
    vector<T> temporal(v.size());
    
    mergeSplit(v, temporal, 0, v.size() - 1);
    
    return v;
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high){

    int mid;

    if((high - low) < 1){
        return;
    }
    else{
        mid = (high + low) / 2;
        mergeSplit(A, B, low, mid);
        mergeSplit(A, B, mid + 1, high);
        mergeArray(A, B, low, mid, high);
        copyArray(A, B, low, high);
    }
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high){
   
    int i = low, j = mid + 1, k = low;

    while (i <= mid and j <= high){
        
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;
        }
        else{
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid){
        for (; j <= high; j++){
            B[k++] = A[j];
        }
    }
    else{
        for (; i <= mid; i++){
            B[k++] = A[i];
        }
    }
}

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector <T> &B, int low, int high){

    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

template <class T>
vector<T> Sorts<T>::ordenaQuick(vector<T> &v, int low, int high){
   
    if (low < high){
        int pi = partition(v, low, high);

        ordenaQuick(v, low, pi - 1);  
        ordenaQuick(v, pi + 1, high); 
    }
    return v;
}

template <class T>
int Sorts<T>::partition(vector<T> &v, int low, int high){
    
    int piv = v[low];
    int i = low + 1;
    
    for (int j = i; j <= high; j++){
    
        if(v[j] < piv){
            swap(v, i, j);
            i++;
        }
    }
    
    swap(v, low, i - 1);
    return (i - 1);
}

template <class T>
int Sorts<T>::busqSecuencial(vector<T> &v, int n){

    for(int i = 0; i < v.size(); i++){
    
        if(v[i] == n){
            cout << "Posicion: "<< i <<"; Comparaciones: " << i + 1 << "; ";
            return i;
        }
    }

    cout << "No se encontro el numero; Comparaciones: "<< v.size() <<"; ";
    return -1;
}
template <class T>
int Sorts<T>::busqBinaria(vector<T> &v, int n){
    
    int mid;
    int bot = 0;
    int top = v.size() - 1;
    int i = 1;
    
    while (bot < top){
    
        mid = (top + bot) / 2;
        if (n == v[mid]){
            cout << "Posicion: " << mid << "; Comparaciones: " << i + 1 << "; ";
            return mid;
        }
        else if (n < v[mid]){
            top = mid - 1;
        }
        else if (n > v[mid]){
            bot = mid + 1;
        }
        i++;
    }
   
    cout << "Posicion: " << bot << "; Comparaciones: " << i + 1 << "; ";
    return bot;

}

#endif