#include <iostream>
using namespace std;
/*
 * Escriba una función recursiva que ordene de menor a mayor un arreglo de enteros
 * basándose en la siguiente idea: coloque el elemento más pequeño en la primera ubicación,
 * y luego ordene el resto del arreglo con una llamada recursiva.
 */

void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void ordenarMenoraMayor(int arr[], int n, int indice = 0) {
    if (indice == n - 1) {
        // Caso base: el arreglo está ordenado
        return;
    }

    // Encontrar el índice del elemento más pequeño en el resto del arreglo
    int indiceMinimo = indice;
    for (int i = indice + 1; i < n; ++i) {
        if (arr[i] < arr[indiceMinimo]) {
            indiceMinimo = i;
        }
    }

    // Intercambiar el elemento actual con el elemento más pequeño encontrado
    intercambiar(arr[indice], arr[indiceMinimo]);

    // Llamar recursivamente para ordenar el resto del arreglo
    ordenarMenoraMayor(arr, n, indice + 1);
}

int main() {
    int n, arreglo[n];
    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout <<"Elemento " << i << ": ";
        cin >> arreglo[i];
    }

    cout << "ARREGLO ORIGINAL: ";
    for (int i=0; i<n; i++){
        cout << arreglo[i] << "  ";
    }

    cout << endl;

    ordenarMenoraMayor(arreglo, n);

    cout << "ARREGLO ORDENADO EN ORDEN CRECIENTE: ";
    for (int i=0; i<n; i++){
        cout << arreglo[i] << "  ";
    }

    return 0;
}