# Sistema de Ordenamiento y Comparación de Algoritmos

Programa en C++ para la materia, hecho para generar números aleatorios y ordenarlos con distintos algoritmos, comparando cuánto tarda cada uno.

## Qué hace

- Genera una cantidad de números aleatorios que el usuario define (con un rango mínimo y máximo).
- Los ordena con el método que elijas, o con todos a la vez.
- Mide el tiempo que tarda cada algoritmo en ordenar (en milisegundos).
- Al final muestra una tabla comparando los tiempos y dice cuál fue el más rápido.

## Algoritmos que implementé

1. Bubble Sort
2. Insertion Sort
3. Selection Sort
4. Merge Sort
5. Quick Sort
6. Counting Sort

## Menú principal

```
----- Menu Principal -----
1. Generar numeros aleatorios
2. Mostrar numeros generados
3. Ordenar con un metodo
4. Comparar todos los metodos
5. Mostrar resultados
6. Salir
```

## Submenú (opción 3)

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

## Estructura de carpetas

```
proyecto-ordenamiento/
├── src/
│   └── sistema_ordenamiento.cpp
├── capturas/
└── README.md
```

## Cómo compilar y correrlo

Con g++:

```
g++ -o sistema_ordenamiento src/sistema_ordenamiento.cpp
./sistema_ordenamiento
```

En Windows con MinGW es lo mismo pero el ejecutable termina en .exe:

```
g++ -o sistema_ordenamiento.exe src/sistema_ordenamiento.cpp
sistema_ordenamiento.exe
```

## Ejemplo de salida

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

## Algunas cosas que hice distinto

No usé rand()/srand() para los números aleatorios, hice mi propio generador con un LCG (Linear Congruential Generator) que se siembra con time(nullptr).

Tampoco usé iomanip para alinear el texto y mostrar los decimales, esa parte la hice a mano con funciones propias (imprimirPad e imprimirDecimal).

El tiempo lo mido con clock() de ctime.

## Autor

Joel Sander Pele Mamani Llanos
