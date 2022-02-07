#include <iostream>
using namespace std;

void imprimir(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ; ";
    }
    cout << endl;
}

void merge(int array[], int inicio, int medio, int final) {

    int n1 = medio - inicio + 1;
    int n2 = final - medio;

    int L[1], M[1];

    for (int i = 0; i < n1; i++)
        L[i] = array[inicio + i];
    for (int j = 0; j < n2; j++)
        M[j] = array[medio + 1 + j];

    int i=0, j=0, k=inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int inicio, int final) {
    if (inicio < final) {
        int medio = inicio + (final - inicio) / 2;

        mergeSort(array, inicio, medio);
        mergeSort(array, medio + 1, final);

        merge(array, inicio, medio, final);
    }
}

int main() {
    int array[6] = { 123,134,136,32,63,14 };

    
    imprimir(array, 6);
    
    mergeSort(array, 0, 6);

    imprimir(array, 6);

    return 0;
}