/* Integrantes: Douglas Daniel Ramirez Canales  Cuenta: 32151049
             Josue Eliezer Castillo Soto     Cuenta: 32151059


    Utilizando como base la pila indicada en el ejercicio anterior, desarrolle un programa
que simule una pila de caracteres, para reconstruir palabras a partir de una cadena
especial que mezcla letras y asteriscos (*), considerando lo siguiente:
a. El programa tendrá un arreglo de mínimo 3 palabras conocidas (pueden ser
predefinidas o ingresadas por el usuario).
b. El programa leerá una cadena formada por letras y asteriscos.
c. Cada letra representa que esa letra debe ser agregada (push) a la pila.
d. Cada asterisco representa que se debe sacar (pop) una letra de la pila y
agregarla a la palabra final.
e. La palabra reconstruida (resultado de los pops) debe ser comparada
exactamente contra las palabras del arreglo. Si no coincide exactamente,
se indicará que no fue correcta, y se imprimirá la palabra formada.
f. Al finalizar el programa, deberá indicar cuántas letras se ingresaron en total,
cuántos pops se hicieron, y si hubo más asteriscos que letra.
g. Incluya en la entrega un archivo de Word con la impresión de pantalla de su
programa con datos diferentes.

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pila {
private:
    vector<char> elementos;

public:
    void push(char elemento) {
        elementos.push_back(elemento);
    }

    char pop() {
        if (estaVacia()) return '\0';
        char elemento = elementos.back();
        elementos.pop_back();
        return elemento;
    }

    bool estaVacia() const {
        return elementos.empty();
    }

    int contar() const {
        return elementos.size();
    }
};

bool esNumeroValido(string str) {
    for (char c : str) {
        if (c < '0' || c > '9') return false;
    }
    return !str.empty();
}

void instruccionesIngreso() {
    cout << "\n--- Instrucciones para ingresar la cadena ---" << endl;
    cout << "Para formar una palabra conocida usando  el simulador de pila, debes escribir la cadena de \n"
         << "manera que cada letra sea seguida de un asterisco (*), indicando que esa letra \n"
         << "será agregada y luego extraída de la pila. \n" << endl;
    cout << "Ejemplo: Para formar la palabra 'Hola', la cadena debe ser: a*l*o*l*H*" << endl;
    cout << "Esto genera: push 'a', pop (agrega 'a' al resultado), push 'l', pop (agrega 'l'), etc.\n";
    cout << "El resultado final se construye desde la pila usando LIFO (último en entrar, primero en salir).\n" << endl;
}

void reconstruccionPalabras() {
    vector<string> palabras_conocidas;
    string entrada;
    int num_palabras = 0;

    // VALIDAR NÚMERO DE PALABRAS
    do {
        cout << "\nIngrese el número de palabras conocidas (mínimo 3): ";
        getline(cin, entrada);
        if (esNumeroValido(entrada)) {
            num_palabras = stoi(entrada);
            if (num_palabras < 3)
                cout << "Debe ingresar al menos 3 palabras.\n";
        } else {
            cout << "Entrada inválida. Ingrese un número válido.\n";
        }
    } while (num_palabras < 3);

    // INGRESAR PALABRAS
    for (int i = 0; i < num_palabras; ++i) {
        string palabra;
        cout << "Ingrese la palabra conocida #" << (i + 1) << ": ";
        getline(cin, palabra);
        palabras_conocidas.push_back(palabra);
    }

    // INGRESAR CADENA DE OPERACIONES
    string cadena;
    cout << "\nIngrese una cadena de letras y asteriscos (*): ";
    getline(cin, cadena);

    // Reconstrucción de la palabra
    Pila pila;
    string resultado = "";
    int letras = 0, pops = 0;
    size_t i = 0;

    while (i < cadena.length()) {
        char c = cadena[i];
        if (c == '*') {
            pops++;
            char extraido = pila.pop();
            if (extraido != '\0')
                resultado = extraido + resultado;
        } else {
            pila.push(c);
            letras++;
        }
        i++;
    }

    // Comparar resultado con palabras conocidas
    bool coincide = false;
    for (const string& palabra : palabras_conocidas) {
        if (palabra == resultado) {
            coincide = true;
            break;
        }
    }

    // RESULTADO
    cout << "\nResultado:\n";
    if (coincide)
        cout << "La palabra reconstruida es CORRECTA.\n";
    else
        cout << "La palabra reconstruida NO es correcta. Se formó: " << resultado << endl;

    cout << "\nEstadísticas:\n";
    cout << "- Letras ingresadas: " << letras << endl;
    cout << "- Pops realizados: " << pops << endl;
    cout << "- ¿Más asteriscos que letras?: " << (pops > letras ? "Sí" : "No") << endl;
}

void menuPrincipal() {
    string opcion;
    while (true) {
        cout << "\n=== MENÚ PRINCIPAL ===" << endl;
        cout << "1. Reconstruir palabra" << endl;
        cout << "2. Ver instrucciones de como Reconstruir las palabras ingresadas" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == "1") {
            reconstruccionPalabras();
        } else if (opcion == "2") {
            instruccionesIngreso();
        } else if (opcion == "3") {
            cout << "Saliendo del programa..." << endl;
            break;
        } else {
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    }
}

int main() {
    menuPrincipal();
    return 0;
}
