#include "Nodo.h"
#include <iostream>

using namespace std;

/*
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    Nodo<T> *inicio;
    T dato;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();

    void imprimir();

    void fnInvierte();

    void reemplazarTope(int pos);

    void printInverso(int pos);

    void reemplazarFinal(int pos);

    void removerNum(T dato);

    int buscarPosicion(T dato);

};

/**
 * Constructor de la clase Lista
 * @tparam T
 **/
template<class T>
Lista<T>::Lista() {
    inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 **/
template<class T>
Lista<T>::Lista(const Lista<T> &li) {
    inicio = nullptr;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 **/
template<class T>
Lista<T>::~Lista() {}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 **/
template<class T>
bool Lista<T>::esVacia() {
    return inicio == nullptr;
}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 **/
template<class T>
int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int tam = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 **/
template<class T>
void Lista<T>::insertar(int pos, T dato) {
    Nodo<T> *aux = inicio;
    int posActual = 0;
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    if (pos == 0) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux != nullptr && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 **/
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    insertar(0, dato);
}

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 **/
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    Nodo<T> *aux = inicio;
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    if (aux == nullptr) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);

}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    Nodo<T> *auxNodo = inicio;
    Nodo<T> *aBorrar;
    int posActual = 0;

    if (esVacia()) throw 404;

    if (pos == 0) {
        inicio = inicio->getSiguiente();
        delete auxNodo;
        return;
    }

    while (auxNodo != nullptr && posActual < pos - 1) {
        auxNodo = auxNodo->getSiguiente();
        posActual++;
    }

    if (auxNodo == nullptr) throw 404;

    aBorrar = auxNodo->getSiguiente();
    auxNodo->setSiguiente(auxNodo->getSiguiente()->getSiguiente());
    delete aBorrar;

}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 **/
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    if (pos < 0 || pos >= getTamanio()) {
        cerr << "Posición no válida." << endl;
        return;
    }

    Nodo<T> *actual = inicio;

    // Avanzar hasta la posición deseada
    for (int i = 0; i < pos; ++i) {
        actual = actual->getSiguiente();
    }

    // Reemplazar el dato en la posición dada
    actual->setDato(dato);
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 **/
template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;

    while (aux != nullptr) {
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }
    if (aux == nullptr) {
        throw 404;
    }
    inicio = nullptr;

}

/*
 * Implementar la función fnInvierte(lista).
 * Esta función invertirá el orden original de los elementos en la lista,
 * de tal forma que el último elemento será ahora el primero, el penúltimo será el segundo,
 * y así hasta que el primero sea el último. Considere que la lista no está vacía y que no se construirá una nueva,
 * sólo se invertirá el orden de los elementos de la lista original.
 */

template<class T>
void Lista<T>::fnInvierte() {
    Nodo<T> *aux = inicio, *anterior = nullptr, *siguiente = inicio;

    if (esVacia()) {
        return;
    }
    siguiente = siguiente->getSiguiente();

    while (siguiente != nullptr) {
        aux->setSiguiente(anterior);
        anterior = aux;
        aux = siguiente;
        siguiente = siguiente->getSiguiente();
    }
    aux->setSiguiente(anterior);
    inicio = aux;
}

template<class T>
void Lista<T>::imprimir() {
    Nodo<T> *aux = inicio;
    while (aux != nullptr) {
        cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

template<class T>
void Lista<T>::reemplazarTope(int pos){

        // Obtener el dato en la posición 'pos'
        T dato = getDato(pos);

        // Eliminar el nodo en la posición 'pos'
        remover(pos);

        // Insertar el dato al inicio de la lista
        insertarPrimero(dato);
}

template<class T>
void Lista<T>::printInverso(int pos) {
    Nodo<T> *anterior = nullptr;
    Nodo<T> *actual = inicio;

    // Avanzar hasta la posición deseada
    for (int i = 0; i < pos && actual; ++i) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    // Si no hay suficientes nodos, no invertir
    if (!actual) {
        return;
    }

    // Invertir la lista a partir de la posición dada
    Nodo<T> *siguiente;
    while (actual) {
        siguiente = actual->getSiguiente();
        actual->setSiguiente(anterior);
        anterior = actual;
        actual = siguiente;
    }

    // Si empezamos desde el principio, actualizar inicio
    if (pos == 0) {
        inicio = anterior;
    } else {
        // Conectar el nodo anterior al nodo invertido
        Nodo<T> *nodoAntesDeInvertir = inicio;
        for (int i = 0; i < pos - 1; ++i) {
            nodoAntesDeInvertir = nodoAntesDeInvertir->getSiguiente();
        }
        nodoAntesDeInvertir->setSiguiente(anterior);
    }
}

template<class T>
void Lista<T>::reemplazarFinal(int pos){

    // Obtener el dato en la posición 'pos'
    T dato = getDato(pos);

    // Eliminar el nodo en la posición 'pos'
    remover(pos);

    // Insertar el dato al inicio de la lista
    insertarUltimo(dato);
}

template<class T>
void Lista<T>::removerNum(T dato){
    Nodo<T> *actual = inicio;
    Nodo<T> *anterior = nullptr;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->getDato() == dato) {
            Nodo<T> *aBorrar = actual;
            if (anterior != nullptr) {
                // No estamos al inicio de la lista
                anterior->setSiguiente(actual->getSiguiente());
                actual = actual->getSiguiente();
            } else {
                // Estamos al inicio de la lista
                inicio = actual->getSiguiente();
                actual = inicio;
            }
            delete aBorrar;
            encontrado = true;
        } else {
            // Avanzar al siguiente nodo
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }

    if (!encontrado) {
        cout << "El dato no se encuentra en la lista." << endl;
    }
}

template<class T>
int Lista<T>::buscarPosicion(T dato) {
    Nodo<T> *actual = inicio;
    int pos = 0;

    // Recorrer la lista para encontrar la posición del dato
    while (actual != nullptr && actual->getDato() != dato) {
        actual = actual->getSiguiente();
        pos++;
    }

    // Verificar si se encontró el dato en la lista
    if (actual == nullptr) {
        cerr << "El dato " << dato << " no se encuentra en la lista." << endl;
        return -1; // Devolver -1 si el dato no está en la lista
    }

    return pos;
}


