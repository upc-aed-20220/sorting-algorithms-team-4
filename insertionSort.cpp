#include <iostream>
using namespace std;

void imprimir(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ; ";
    }
    cout << endl;
}

void insertionSort(int array[], int n) {
    int aux;
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            if (array[j - i] < array[j - 1 - i]) {
                aux = array[j - i];
                array[j - i] = array[j - 1 - i];
                array[j - 1 - i] = aux;
            }
        }
        imprimir(array, n);
    }
}

int main() {
    int array[6] = { 123,134,136,32,63,14 };

    
    imprimir(array, 6);
    
    insertionSort(array, 6);

    imprimir(array, 6);

    return 0;
}