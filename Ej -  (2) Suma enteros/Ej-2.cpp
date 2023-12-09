//
// Created by BANGHO on 07/12/2023.
//
#include <iostream>
using namespace std;
//Escribir una función recursiva que devuelva la suma de los primeros N enteros

int sumaEnteros(int n) {
    // Caso base: cuando n es 0, la suma es 0
    if (n == 0) {
        return 0;
    }

    // Caso recursivo: la suma de los primeros N enteros es N + la suma de los primeros N-1 enteros
    return n + sumaEnteros(n - 1);
}

int main(){
    cout << "Ingrese N: ";
    int n;
    cin >> n;

    int resultado;
    resultado= sumaEnteros(n);
    cout << "La suma de los primeros " << n << " numeros es: " << resultado;
};