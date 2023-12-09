#include <iostream>
#include <string>
#include "Nodo.h"
#include "Pila.h"

using namespace std;

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Cola {
private:
    Nodo<T> *tope, *fondo;
    int contadorPrioridad = 0;
public:
    Cola();

    ~Cola();

    void encolar(T dato);

    T desencolar();

    bool esVacia();

    T peek();

    bool colasIguales(Cola<T> cola2);

    T getTamanio();

    void encolarConPrioridad(T dato, int prioridad);

    int getCantidadPrioridad() const {
        return contadorPrioridad;
    }

    void ParesImpares();

    int sumaCola(Cola<T> cola2);

    void imprimir();

    void intercambiarColas(Cola<T>& cola2);

    void insertarDespuesEnesimaOcurrencia(T dato, int n);
};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template<class T>
Cola<T>::Cola() {
    tope = nullptr;
    fondo = nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template<class T>
Cola<T>::~Cola() {
    while (!esVacia()) {
        desencolar();
    }
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Cola<T>::encolar(T dato) {
    Nodo<T> *nuevo = new Nodo<T>;

    nuevo->setDato(dato);
    nuevo->setSiguiente(nullptr);

    if (esVacia()) {
        tope = nuevo;
        fondo = nuevo;
    } else {
        fondo->setSiguiente(nuevo);
        fondo = nuevo;
    }
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Cola<T>::desencolar() {
    if (esVacia()) {
        throw 404;
    }
    T dato = tope->getDato();
    Nodo<T> *aBorrar = tope;
    tope = tope->getSiguiente();

    if (tope == nullptr) {
        fondo = nullptr;
    }

    delete aBorrar;
    return dato;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Cola<T>::esVacia() {
    return tope == nullptr;
}

/**
 * Muestra el dato que contiene el tope
 * @tparam T
 * @return
 */
template<class T>
T Cola<T>::peek() {
    if (esVacia()) {
        throw 404;
    }
    return tope->getDato();
}

template<class T>
T Cola<T>::getTamanio() {
    Nodo<T> *aux = tope;
    int tam = 0;

    while (aux != nullptr) {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}


template<class T>
bool Cola<T>::colasIguales(Cola<T> cola2) {
    if (getTamanio() != cola2.getTamanio()) {
        return false; // Si las colas tienen tamaños diferentes, no son iguales
    }

    Nodo<T> *aux1 = tope;
    Nodo<T> *aux2 = cola2.tope;

    while (aux1 != nullptr) {
        if (aux1->getDato() != aux2->getDato()) {
            return false; // Si encuentra elementos diferentes, las colas no son iguales
        }
        aux1 = aux1->getSiguiente();
        aux2 = aux2->getSiguiente();
    }

    return true; // Si no se encontraron diferencias, las colas son iguales
}

bool esPalindromo(string cadena) {

    Pila<char> pila;
    Cola<char> cola;

    for (char c: cadena) {
        pila.push(c);
        cola.encolar(c);
    }

    while (!pila.esVacia() && !cola.esVacia()) {
        if (pila.pop() != cola.desencolar()) {
            return false;
        }
    }

    return pila.esVacia() && cola.esVacia();
}

template<class T>
void Cola<T>::encolarConPrioridad(T dato, int prioridad) {
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    if (esVacia() || prioridad == 0) {
        nuevo->setSiguiente(tope);
        tope = nuevo;
        if (fondo == nullptr) {
            fondo = nuevo;
        }
        if (prioridad == 0) {
            contadorPrioridad++;
        }
    } else {
        Nodo<T> *actual = tope;
        Nodo<T> *anterior = nullptr;

        while (actual != nullptr && actual->getPrioridad() <= prioridad) {
            anterior = actual;
            actual = actual->getSiguiente();
        }

        nuevo->setSiguiente(actual);
        if (anterior != nullptr) {
            anterior->setSiguiente(nuevo);
        } else {
            tope = nuevo;
        }

        if (actual == nullptr) {
            fondo = nuevo;
        }
    }
}

template<class T>
void Cola<T>::ParesImpares() {
    Pila<int> pila;
    Cola<int> cola;

    //Cree dos punteros. A la pila se le pasa como tope al Primer elemento,
    // ya que va a ser el de la posicion 0 que lo utilizaremos con 1.
    //El puntero numero 2, encolamos en el tope al siguiente dato que le sigue.

    Nodo<T> *cola1;
    Nodo<T> *pila1;
    while (pila1 == esVacia() && cola1 != esVacia()) {
        Nodo<T> *aux1 = pila.push(tope);
        Nodo<T> *aux2 = cola.encolar(tope->setSiguiente());

    }

}

template<class T>
int Cola<T>::sumaCola(Cola<T> cola2) {
    Cola<int>resultado;
    while (!esVacia() && !cola2.esVacia()) {
        int suma = peek() + cola2.peek();
        resultado.encolar(suma);
        desencolar();
        cola2.desencolar();
    }

    // Si alguna de las colas originales aún tiene elementos, agregarlos a la cola de resultado
    while (!esVacia()) {
        resultado.encolar(peek());
        desencolar();
    }

    while (!cola2.esVacia()) {
        resultado.encolar(cola2.peek());
        cola2.desencolar();
    }

    resultado.imprimir();
}

template <class T>
void Cola<T>::imprimir(){
    Nodo<T>* actual = tope;

    while (actual != nullptr)
    {
        cout << actual->getDato() << " ";
        actual = actual->getSiguiente();
    }
    cout << endl;

}

template <class T>
void Cola<T>::intercambiarColas(Cola<T>& cola2) {
    Cola<T> auxC1, auxC2;

    while (!esVacia()) {
        auxC1.encolar(desencolar());
    }

    while (!cola2.esVacia()) {
        auxC2.encolar(cola2.desencolar());
    }

    while (!auxC1.esVacia()) {
        encolar(auxC1.desencolar());
    }

    while (!auxC2.esVacia()) {
        cola2.encolar(auxC2.desencolar());
    }
}

template<class T>
void Cola<T>::insertarDespuesEnesimaOcurrencia(T dato, int n) {
    if (n <= 0) {
        throw std::invalid_argument("El valor de n debe ser mayor que 0.");
    }

    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    Nodo<T> *actual = tope;
    int contador = 0;

    while (actual != nullptr) {
        if (actual->getDato() == dato) {
            contador++;
            if (contador == n) {
                nuevo->setSiguiente(actual->getSiguiente());
                actual->setSiguiente(nuevo);

                // Actualizar el puntero 'fondo' solo si se inserta después de la última ocurrencia
                if (nuevo->getSiguiente() == nullptr) {
                    fondo = nuevo;
                }

                return;
            }
        }
        actual = actual->getSiguiente();
    }

    // Si no se encontraron n ocurrencias, encolar al fondo
    encolar(dato);
}




