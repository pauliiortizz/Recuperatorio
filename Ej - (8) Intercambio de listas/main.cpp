#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    Lista<int> lista1;
    Lista<int> lista2;

    int n1, n2;
    cout << " ---------- LISTA 1 ----------- " << endl;

    cout << "Tamano: ";
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        cout << "Elemento " << i << ": ";
        int valor;
        cin >> valor;
        lista1.insertarUltimo(valor);
    }

    cout << endl;

    cout << " ---------- LISTA 2 ----------- " << endl;

    cout << "Tamano: ";
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        cout << "Elemento " << i << ": ";
        int valor;
        cin >> valor;
        lista2.insertarUltimo(valor);
    }

    cout << endl;
    cout << "LISTA 1 ORIGINAL: ";
    lista1.imprimir();
    cout << "LISTA 2 ORIGINAL: ";
    lista2.imprimir();
    cout << endl;

    Lista<int> aux;

    aux = lista1;
    lista1 = lista2;
    lista2 = aux;

    cout << "LISTA 1 MODIFICADA: ";
    lista1.imprimir();
    cout << "LISTA 2 MODIFICADA: ";
    lista2.imprimir();


}
