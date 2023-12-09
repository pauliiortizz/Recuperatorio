//
// Created by BANGHO on 08/12/2023.
//
#include <iostream>
using namespace std;

// Función recursiva para invertir un número
int invertirNumero(int numero, int invertido = 0) {
    // Caso base: el número se ha invertido completamente
    if (numero == 0) {
        return invertido;
    }

    // Extraer el dígito menos significativo
    int digito = numero % 10;

    // Construir el número invertido
    invertido = invertido * 10 + digito;

    // Llamar recursivamente con el resto del número
    return invertirNumero(numero / 10, invertido);
}

int main() {
    int numero;

    // Solicitar al usuario que ingrese un número
    cout << "Ingrese un numero: ";
    cin >> numero;

    cout << endl;

    cout << "NUMERO A INVERTIR: " << numero << endl;

    // Llamar a la función para invertir el número
    int numeroInvertido = invertirNumero(numero);

    // Mostrar el número invertido
    cout << "NUMERO INVERTIDO: " << numeroInvertido << std::endl;

    return 0;
}

