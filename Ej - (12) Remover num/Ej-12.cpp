//
// Created by BANGHO on 08/12/2023.
//

#include <iostream>
#include "Lista.h"

/*
 */

using namespace std;

int main() {
    Lista<int> lista1;

    int n1;
    cout << " ---------- LISTA 1 ----------- " << endl;

    cout << "Tamano: ";
    cin >> n1;
    int valor;

    for (int i = 0; i < n1; i++) {
        cout << "Elemento " << i << ": ";
        cin >> valor;
        lista1.insertar(i, valor);
    }
    cout << endl;

    int num;
    cout << "numero: ";
    cin >> num;

    cout << "LISTA ORIGINAL: " << endl;
    lista1.imprimir();

    lista1.removerNum(num);
    cout << endl;
    cout << "LISTA MODIFICADA: ";
    lista1.imprimir();

}

