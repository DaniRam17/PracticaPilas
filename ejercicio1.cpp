/*  
Integrantes: Douglas Daniel Ramirez Canales  Cuenta: 32151049
             Josue Eliezer Castillo Soto     Cuenta: 32151059
             

Ejercicio 1 Utilizando como base la clase pila proporcionada en la sesión presencial del día
jueves 24 de abril y compartida en el Aula Virtual, desarrolle en un programa en el
lenguaje de su preferencia en el que se desarrollen las siguientes opciones:
a. Determinar si la pila contiene elementos.
b. Sacar una cantidad de elementos (dada por el usuario) de la pila.
c. Ver cuál es el último elemento que ha sido ingresado en la pila numérica. No
se debe sacar el elemento de la pila.
d. Determinar el tamaño de la pila numérica.
e. Incluya en la entrega de esta tarea, un archivo de Word con la impresión de
pantalla probando las diferentes opciones */ 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pila {
private:
    vector<string> elementos;

public:
    
    //Plantilla Base
    //Referencia https://cplusplus.com/reference/vector/vector/push_back/
    void push(const string& elemento) {
        elementos.push_back(elemento);
        cout << "\"" << elemento << "\" agregado a la pila." << endl;
    }

    //Plantilla Base
    //referencia https://cplusplus.com/reference/vector/vector/pop_back/
    void pop() {
        if (estaVacia()) {
            cout << "La pila está vacía. No se puede hacer pop." << endl;
        } else {
            string elemento = elementos.back();
            elementos.pop_back();
            cout << "\"" << elemento << "\" eliminado de la pila." << endl;
        }
    }

    // (inciso b)
    // Elimina 'n' elementos de la pila, uno por uno
    void popVarios(int varioselementos) {
        for (int i = 0; i < varioselementos; i++) {
            if (estaVacia()) {
                cout << "La pila ya está vacía. No se pueden eliminar más elementos." << endl;
                break;
            }
            pop();
        }
    }

    // (inciso c)
    // Devuelve el último elemento sin eliminarlo
    string ultimoElemento() const {
        if (estaVacia()) {
            return "La pila está vacía. No hay ningún elemento en la pila.";
        } else {
            return elementos.back();
        }
    }

    // (inciso d)  //Plantilla Base
    int contar() const {
        return elementos.size();
    }

    //Plantilla Base
    // Referencia  https://cplusplus.com/reference/vector/vector/rbegin/ y https://cplusplus.com/reference/vector/vector/rend/
    void mostrar() const {
        if (estaVacia()) {
            cout << "No se encuentran elementos en la pila ." << endl;
        } else {
            cout << "\n--- Pila ---" << endl;
            for (auto it = elementos.rbegin(); it != elementos.rend(); ++it) {
                cout << "| " << *it << " |" << endl;
            }
            cout << "------------" << endl;
        }
    }

    // inciso a
    bool estaVacia() const {
        return elementos.empty();
    }
};

// Menú
void menu() {
    Pila pila;
    string opcion;

    while (true) {
        cout << "\n---- Menú ----" << endl;
        cout << "1. Push (Agregar elemento)" << endl; //Plantilla Base
        cout << "2. Pop (Eliminar tope)" << endl;  //Plantilla Base
        cout << "3. Pop N elementos" << endl;               // Inciso b
        cout << "4. Ver último elemento o tope de pila" << endl; // Inciso c
        cout << "5. Contar elementos" << endl;     // Inciso d
        cout << "6. Confirmar si  la pila tiene elementos" << endl;  // Inciso a
        cout << "7. Mostrar pila" << endl;  //Plantilla Base
        cout << "8. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore(); 

        if (opcion == "1") {
            string cadena;
            cout << "Ingresa la cadena a agregar: ";
            getline(cin, cadena);
            pila.push(cadena);

        } else if (opcion == "2") {
            pila.pop();

        } else if (opcion == "3") {
            int cantidad;
            cout << "¿Cuántos elementos desea eliminar?: ";
            cin >> cantidad;
            cin.ignore();
            pila.popVarios(cantidad);

        } else if (opcion == "4") {
            cout << "Elemento que se encuentra en el tope: " << pila.ultimoElemento() << endl;

        } else if (opcion == "5") {
            cout << "La pila tiene " << pila.contar() << " elemento(s)." << endl;

        } else if (opcion == "6") {
            if (pila.estaVacia())
                cout << "No, la pila está vacía." << endl;
            else
                cout << "Sí, la pila contiene elementos." << endl;

        } else if (opcion == "7") {
            pila.mostrar();

        } else if (opcion == "8") {
            cout << "¡Gracias por utilizar el programa Hasta luego!" << endl;
            break;

        } else {
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}