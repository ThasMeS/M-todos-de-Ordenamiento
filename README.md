# Sistema de Ordenamiento y Comparación de Algoritmos

Sistema en **C++** que genera números aleatorios y permite ordenarlos utilizando distintos algoritmos de ordenamiento, midiendo y comparando el tiempo de ejecución de cada uno.

## 📋 Descripción

El programa permite:
- Generar una cantidad determinada de números aleatorios dentro de un rango definido por el usuario.
- Ordenarlos usando un método específico o todos a la vez.
- Medir el tiempo de ejecución (en milisegundos) de cada algoritmo.
- Comparar los resultados y determinar cuál algoritmo fue más rápido.

## ⚙️ Algoritmos implementados

| # | Algoritmo       |
|---|-----------------|
| 1 | Bubble Sort     |
| 2 | Insertion Sort  |
| 3 | Selection Sort  |
| 4 | Merge Sort      |
| 5 | Quick Sort      |
| 6 | Counting Sort   |

## 🖥️ Menú principal

```
----- Menu Principal -----
1. Generar numeros aleatorios
2. Mostrar numeros generados
3. Ordenar con un metodo
4. Comparar todos los metodos
5. Mostrar resultados
6. Salir
```

## 🔽 Submenú de ordenamiento (opción 3)

```
========================================
 METODOS DE ORDENAMIENTO
========================================
1. Bubble Sort
2. Insertion Sort
3. Selection Sort
4. Merge Sort
5. Quick Sort
6. Counting Sort
7. Todos los metodos
8. Regresar
```

## 📂 Estructura del repositorio

```
proyecto-ordenamiento/
│
├── src/
│   └── sistema_ordenamiento.cpp   # Código fuente principal
│
├── capturas/                      # Capturas de pantalla de ejecución
│
└── README.md                      # Este archivo
```

## 🚀 Compilación y ejecución

Requiere un compilador de C++ (g++ recomendado).

```bash
g++ -o sistema_ordenamiento src/sistema_ordenamiento.cpp
./sistema_ordenamiento
```

En Windows (con MinGW):

```bash
g++ -o sistema_ordenamiento.exe src/sistema_ordenamiento.cpp
sistema_ordenamiento.exe
```

## 📊 Ejemplo de salida

```
Comparando todos los metodos...
Bubble Sort -> 0.0020 ms
Insertion Sort -> 0.0010 ms
Selection Sort -> 0.0010 ms
Merge Sort -> 0.0030 ms
Quick Sort -> 0.0000 ms
Counting Sort -> 0.0020 ms

========================================
 RESULTADOS (tiempo de ejecucion)
========================================
Algoritmo           Tiempo (ms)
----------------------------------------
Bubble Sort         0.0020
Insertion Sort      0.0010
Selection Sort      0.0010
Merge Sort          0.0030
Quick Sort          0.0000
Counting Sort       0.0020
----------------------------------------
Mas rapido: Quick Sort
```

## 🧠 Detalles técnicos

- El generador de números aleatorios es una implementación propia de un **LCG (Linear Congruential Generator)**, sembrado con `time(nullptr)`, sin usar `rand()`/`srand()`.
- El formato de impresión (alineado y con decimales) está implementado manualmente, sin usar `<iomanip>`.
- La medición de tiempo se realiza con `clock()` de `<ctime>`.

## 👤 Autor

- Tu nombre aquí

## 📄 Licencia

Este proyecto es de uso académico.
