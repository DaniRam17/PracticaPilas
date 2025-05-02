# Práctica de Pilas - Estructura de Datos

## Integrantes
- Douglas Daniel Ramirez Canales — Cuenta: 32151049  
- Josue Eliezer Castillo Soto — Cuenta: 32151059

---

## Ejercicio 1 — Operaciones básicas con pilas

Se implementó un programa en C++ que utiliza una clase `Pila` basada en `vector<char>` para simular el comportamiento de una pila numérica. El programa permite realizar las siguientes operaciones:

- **a. Determinar si la pila contiene elementos:**  
  Usando la función `estaVacia()` que retorna `true` si no hay elementos en la pila.

- **b. Sacar una cantidad de elementos (dada por el usuario):**  
  Usando la función `popVarios(n)`, que hace `pop` tantas veces como lo indique el usuario.

- **c. Ver el último elemento ingresado (sin eliminarlo):**  
  Usando la función `ultimoElemento()` que devuelve el tope sin modificar la pila.

- **d. Determinar el tamaño de la pila:**  
  Con la función `contar()`, que devuelve la cantidad de elementos almacenados.

- **e. Evidencia:**  
  Se incluye un documento Word con capturas de cada opción probada desde el menú.

---

## Ejercicio 2 — Reconstrucción de palabras usando pila

Se desarrolló un segundo programa que utiliza la clase `Pila` para reconstruir palabras a partir de una cadena que mezcla letras y asteriscos (`*`). Cada letra es agregada a la pila (`push`) y cada asterisco representa un `pop` que se agrega a la palabra resultado.

### Funcionalidades desarrolladas:

- **a. Arreglo de palabras conocidas:**  
  El usuario ingresa al menos 3 palabras válidas.

- **b. Lectura de cadena:**  
  Se solicita una cadena de entrada con letras y asteriscos.

- **c. Push por cada letra:**  
  Cada carácter alfabético es agregado a la pila.

- **d. Pop por cada asterisco:**  
  El carácter en el tope se elimina de la pila y se agrega al inicio del resultado.

- **e. Comparación de palabra final:**  
  Se compara la palabra reconstruida con el arreglo de palabras ingresadas por el usuario.

- **f. Estadísticas finales:**  
  Se muestra la cantidad de letras ingresadas, cantidad de `pop` realizados, y si hubo más asteriscos que letras.

- **g. Evidencia:**  
  Se adjunta documento Word con diferentes pruebas en ejecución.

---

## Ejercicio 3 — Conversión de notación infija a postfija (manual)

Este ejercicio no se resolvió con código, sino como desarrollo teórico basado en el algoritmo de conversión infija a postfija usando pilas. Se seleccionó una de las expresiones proporcionadas y se documentó el proceso paso a paso.

- **Expresiones sugeridas:**
  - ((7 + B) * (C ^ 2)) / (E - 5)
  - G ^ ((4 + I) / (J - 1))
  - ((3 * M) + (N ^ 2)) - (P / 6)
  - (R + (8 / T)) * (U - V ^ 2)
  - ((4 ^ Y) - (Z + 9)) / (B * C)

- **Herramienta usada:** Word/Excel/PDF
- **Contenido:** Desarrollo paso a paso mostrando cómo la pila cambia con cada símbolo leído.

---

### Curso: 1168 — Estructura de Datos  
Año: 2025
