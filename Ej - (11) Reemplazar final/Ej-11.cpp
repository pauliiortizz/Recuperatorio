#include <iostream>
#include "Lista.h"

/*
Implementar un método en la clase lista que reciba como parámetro un valor entero “pos”. El método debe
buscar el nodo en la posición “pos” y moverlo al inicio. Considerar el uso excepciones de ser necesario. (Solo
moviendo enlaces. No creando nodos nuevos).
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

    int pos;
    cout << "Posicion: ";
    cin >> pos;

    cout << "LISTA ORIGINAL: " << endl;
    lista1.imprimir();

    lista1.reemplazarFinal(pos);

    cout << endl;
    cout << "LISTA MODIFICADA: ";
    lista1.imprimir();

}

