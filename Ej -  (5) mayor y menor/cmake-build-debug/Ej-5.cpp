//
// Created by BANGHO on 07/12/2023.
//
#include <iostream>
using namespace std;

int Mayornumero(int n, int arreglo[]) {
    // Caso base: cuando n es 0, el arreglo está vacío y no hay ningún número mayor
    if (n == 0) {
        throw 404;
    }

    // Caso base: cuando n es 1, el único número en el arreglo es el mayor
    if (n == 1) {
        return arreglo[0];
    }

    // Obtener el máximo entre el elemento actual y el máximo en el resto del arreglo
    int maxResto = Mayornumero(n - 1, arreglo);

    // Comparar el máximo del resto con el elemento actual y devolver el mayor
    if (arreglo[n - 1] > maxResto) {
        return arreglo[n - 1];
    } else {
        return maxResto;
    }
}
int Menornumero(int n, int arreglo[]) {
    // Caso base: cuando n es 0, el arreglo está vacío y no hay ningún número mayor
    if (n == 0) {
        throw 404;
    }

    // Caso base: cuando n es 1, el único número en el arreglo es el mayor
    if (n == 1) {
        return arreglo[0];
    }

    // Obtener el máximo entre el elemento actual y el máximo en el resto del arreglo
    int minResto = Menornumero(n - 1, arreglo);

    // Comparar el máximo del resto con el elemento actual y devolver el mayor
    if (arreglo[n - 1] < minResto) {
        return arreglo[n - 1];
    } else {
        return minResto;
    }
}

int main() {
    int n, arreglo[n];
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Elemento " << i << ": ";
        cin >> arreglo[i];
    }

    //int resultado = Mayornumero(n, arreglo);
    cout << "MAYOR NUMERO: " <<Mayornumero(n, arreglo)<< endl;
    cout << "MENOR NUMERO: " <<Menornumero(n, arreglo)-5;
    return 0;
}