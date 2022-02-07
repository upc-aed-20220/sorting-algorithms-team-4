#include <iostream>
using namespace std;

void imprimir(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ; ";
    }
    cout << endl;
}

int  max(int array[], int n) {
    int mayor = array[0];
    for (int i = 0; i < n; i++) {
        if (mayor < array[i])
            mayor = array[i];
    }
    return mayor;
}

void countingSort(int array[], int n, int posicion) {

    int conteo[10];
    int arrayOrd[6];

    for (int i = 0; i < 10; i++) 
        conteo[i] = 0;

    for (int i = 0; i < n; i++) 
        conteo[(array[i] / posicion) % 10]++;

    for (int i = 1; i < 10; i++) 
        conteo[i] = conteo[i] + conteo[i - 1];

    for (int i = n-1; i >= 0; i--) {
        arrayOrd[conteo[(array[i] / posicion) % 10] - 1] = array[i];
        conteo[(array[i] / posicion) % 10]--;
    }

    for (int i = 0; i < n; i++)
        array[i] = arrayOrd[i];
}

void radixSort(int array[], int n) {
    int maximo = max(array, n);

    for (int posicion = 1; maximo/posicion > 0; posicion = posicion * 10) {
        countingSort(array, n, posicion);
    }
}

int main() {
    int array[6] = { 123,134,136,32,63,14 };

    
    imprimir(array, 6);
    
    radixSort(array, 6);

    imprimir(array, 6);

    return 0;
}