//
// Created by BANGHO on 07/12/2023.
//
/*
 * Escribir un programa que encuentre la suma de los enteros positivos pares desde N hasta 2.
 * Chequear que si N es impar se imprima un mensaje de error.
 */

#include <iostream>
using namespace std;
//Escribir una función recursiva que devuelva la suma de los primeros N enteros

int sumaEnteros(int n) {
    // Caso base: cuando n es 0, la suma es 0
    if (n == 0) {
        return 0;
    }

    // Caso recursivo: la suma de los primeros N enteros es N + la suma de los primeros N-1 enteros
    return n + sumaEnteros(n - 2);
}

int main(){
    cout << "Ingrese N: ";
    int n;
    cin >> n;
    while (n%2!=0 || n==0){
        cout << "NO es posible ingresar un numero IMPAR o el numero 0"<< endl;
        throw 404;
    }

    int resultado;
    resultado= sumaEnteros(n);
    cout << "La suma de los numeros pares desde " << n << " hasta 2, es: " << resultado;
};