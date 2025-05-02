class Pila:
    def __init__(self):
        self.elementos = []

    def push(self, elemento):
        self.elementos.append(elemento)
        print(f'"{elemento}" agregado a la pila.')

    def pop(self):
        if self.esta_vacia():
            print("La pila está vacía. No se puede hacer pop.")
        else:
            elemento = self.elementos.pop()
            print(f'"{elemento}" eliminado de la pila.')

    def contar(self):
        return len(self.elementos)

    def mostrar(self):
        if self.esta_vacia():
            print("La pila está vacía.")
        else:
            print("\n--- Pila ---")
            for elemento in reversed(self.elementos):
                print(f"| {elemento} |")
            print("------------")

    def esta_vacia(self):
        return len(self.elementos) == 0


def menu():
    pila = Pila()
    while True:
        print("\n--- Menú ---")
        print("1. Push (Agregar elemento)")
        print("2. Pop (Eliminar tope)")
        print("3. Contar elementos")
        print("4. Mostrar pila")
        print("5. Salir")

        opcion = input("Selecciona una opción: ")

        if opcion == "1":
            cadena = input("Ingresa la cadena a agregar: ")
            pila.push(cadena)
        elif opcion == "2":
            pila.pop()
        elif opcion == "3":
            print(f"La pila tiene {pila.contar()} elemento(s).")
        elif opcion == "4":
            pila.mostrar()
        elif opcion == "5":
            print("¡Hasta luego!")
            break
        else:
            print("Opción no válida. Intenta de nuevo.")


# Ejecutar el menú
menu()
