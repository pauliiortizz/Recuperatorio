//
// Created by BANGHO on 07/12/2023.
//
//Programe un método recursivo que invierta los números de un arreglo de enteros.

#include <iostream>
using namespace std;

void invertirArreglo(int arreglo[], int inicio, int fin) {
    // Caso base: cuando inicio es mayor o igual a fin, no hay elementos para intercambiar
    if (inicio >= fin) {
        return;
    }

    // Intercambiar los elementos en las posiciones inicio y fin
    int temp = arreglo[inicio];
    arreglo[inicio] = arreglo[fin];
    arreglo[fin] = temp;

    // Llamada recursiva con los índices actualizados
    invertirArreglo(arreglo, inicio + 1, fin - 1);
}

int main() {
    // Ejemplo de uso
    int n;

    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    int arreglo[n];
    for (int i=0; i<n; i++){
        cout << "Elemento " << i << ": ";
        cin >> arreglo[i];
    }

    // Mostrar arreglo original
    cout << "ARREGLO ORIGINAL: ";
    for (int i = 0; i < n; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // Llamar al método recursivo para invertir el arreglo
    invertirArreglo(arreglo, 0, n - 1);

    // Mostrar arreglo invertido
    cout << "ARREGLO INVERTIDO: ";
    for (int i = 0; i < n; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    return 0;
}

