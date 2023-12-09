#include <iostream>
#include "Cola.h"

using namespace std;

/*
Agregue un método a la clase Cola que inserte un nodo con un nuevo dato después de la enésima ocurrencia de
ese mismo dato partiendo la búsqueda desde el tope. Si no hay ocurrencias de mencionado dato, encolarlo al
fondo. Considerar el uso excepciones de ser necesario
 */

int main(){
    Cola<int> cola;
    int n;
    int valor;
    cout << "Ingrese el tamano de la cola: ";
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Elemento " << i << ": ";
        cin >> valor;
        cola.encolar(valor);
    }

    int dato;
    cout <<"Ingrese el dato que desea ingresar en la cola: ";
    cin >> dato;
    cout << endl;
    cout << "Cola original: ";
    cola.imprimir();
    cola.insertarDespuesEnesimaOcurrencia(dato,1);
    cout << "Cola Modificada: ";
    cola.imprimir();

}