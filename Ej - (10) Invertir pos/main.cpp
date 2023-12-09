#include <iostream>
#include "Lista.h"

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
    lista1.imprimir();

    int pos;
    cout << "Posicion: ";
    cin >> pos;
    cout << "LISTA MODIFICADA: ";
    lista1.printInverso(pos);
    lista1.imprimir();


}
