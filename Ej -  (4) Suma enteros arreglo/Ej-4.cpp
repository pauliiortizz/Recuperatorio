//
// Created by BANGHO on 07/12/2023.
//
//Programe un método recursivo que calcule la suma de un arreglo de números enteros.
#include <iostream>
using namespace std;
//Escribir una función recursiva que devuelva la suma de los primeros N enteros

int sumaEnteros(int n, int arreglo[]) {
    // Caso base: cuando n es 0, la suma es 0
    if (n == 0) {
        return 0;
    }

    // Caso recursivo: la suma de los primeros N enteros es N + la suma de los primeros N-1 enteros
    return arreglo[n-1] + sumaEnteros(n-1, arreglo);
}

int main(){
    cout << "Ingrese El tamano del arreglo: ";
    int n;
    cin >> n;
    int arreglo[n];

    for (int i=0; i<n; i++){
        cout << "Elemento " << i << ": ";
        cin >> arreglo[i];
    }

    int resultado= sumaEnteros(n, arreglo);
    cout << "La suma de los primeros " << n << " numeros es: " << resultado;
};