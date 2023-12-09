#include <iostream>
#include "Cola.h"
using namespace std;

/*
 * Implementar una función Reemplazar que tenga como argumentos una pila de enteros y dos valores enteros:
 * nuevo y viejo, de forma que si viejo aparece en algún lugar de la pila, sea reemplazado por nuevo.
 */

Pila<int> reemplazar(Pila<int> pila, int nuevo, int viejo) {
    int aux;
    while (pila.esVacia()){
        throw 404;
    }

    Pila<int> pilaaux;

    while (!pila.esVacia()){      //
        aux=pila.pop();
        if (aux==viejo){
            pilaaux.push(nuevo);
        }
        else {
            pilaaux.push(aux);
        }
    }

    return pilaaux;
}

int main(){
    Pila<int> pila;

    int n;
    int valor;
    cout << "Ingrese el tamano de la pila: ";
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        pila.push(valor);
    }

    int nuevo, viejo;

    cout << "Ingrese el valor VIEJO: ";
    cin >> viejo;
    cout << "Ingrese el valor NUEVO: ";
    cin >> nuevo;

    cout << "Pila Original: ";
    pila.imprimir();

    Pila<int> pilA = reemplazar(pila, nuevo, viejo);

    cout << "Pila Modificada: ";
    for (int i = 0; i < n; ++i) {
        cout <<  pilA.pop() << endl;
    }

}
