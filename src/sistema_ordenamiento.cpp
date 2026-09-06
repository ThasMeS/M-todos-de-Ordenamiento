#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// ================== GENERADOR PSEUDOALEATORIO PROPIO ==================
// Reemplaza a rand()/srand() de <cstdlib> con un LCG (Linear Congruential
// Generator) sencillo, sembrado con time(nullptr) de <ctime>.

unsigned long semillaGlobal;

void inicializarSemilla()
{
    semillaGlobal = (unsigned long)time(nullptr);
}

int siguienteAleatorio(int minR, int maxR)
{
    semillaGlobal = semillaGlobal * 1103515245UL + 12345UL;
    unsigned long valor = (semillaGlobal / 65536UL) % 32768UL;
    return minR + (int)(valor % (unsigned long)(maxR - minR + 1));
}

// ================== UTILIDADES DE IMPRESION ==================
// Reemplazan a setw/fixed/setprecision de <iomanip>.

void imprimirPad(const string &texto, int ancho)
{
    cout << texto;

    for (int i = (int)texto.size(); i < ancho; i++)
        cout << " ";
}

void imprimirDecimal(double valor, int decimales)
{
    if (valor < 0)
    {
        cout << "-";
        valor = -valor;
    }

    long long parteEntera = (long long)valor;
    double parteFraccional = valor - (double)parteEntera;

    cout << parteEntera << ".";

    for (int i = 0; i < decimales; i++)
    {
        parteFraccional *= 10;
        int digito = (int)parteFraccional;
        cout << digito;
        parteFraccional -= digito;
    }
}

void copiarArreglo(int *destino, int *origen, int n)
{
    for (int i = 0; i < n; i++)
        destino[i] = origen[i];
}

void mostrar(int *A, int n)
{
    if (n <= 0)
    {
        cout << "(no hay numeros generados)" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

// ================== ALGORITMOS DE ORDENAMIENTO ==================

void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
}

void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int clave = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > clave)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = clave;
    }
}

void selectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[menor])
                menor = j;
        }

        int aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
    }
}

void merge(int A[], int inicio, int medio, int fin)
{
    int i = inicio;
    int j = medio + 1;
    int k = 0;
    int tamano = fin - inicio + 1;

    int *temp = new int[tamano];

    while (i <= medio && j <= fin)
    {
        if (A[i] < A[j])
        {
            temp[k] = A[i];
            i++;
        }
        else
        {
            temp[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= medio)
    {
        temp[k] = A[i];
        i++;
        k++;
    }

    while (j <= fin)
    {
        temp[k] = A[j];
        j++;
        k++;
    }

    for (i = inicio, k = 0; i <= fin; i++, k++)
        A[i] = temp[k];

    delete[] temp;
}

void mergeSort(int A[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int medio = (inicio + fin) / 2;
        mergeSort(A, inicio, medio);
        mergeSort(A, medio + 1, fin);
        merge(A, inicio, medio, fin);
    }
}

int particion(int A[], int inicio, int fin)
{
    int pivote = A[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++)
    {
        if (A[j] < pivote)
        {
            i++;
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }

    int aux = A[i + 1];
    A[i + 1] = A[fin];
    A[fin] = aux;

    return i + 1;
}

void quickSort(int A[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int posicion = particion(A, inicio, fin);
        quickSort(A, inicio, posicion - 1);
        quickSort(A, posicion + 1, fin);
    }
}

void countingSort(int A[], int n)
{
    if (n <= 0) return;

    int maxVal = A[0];
    int minVal = A[0];

    for (int i = 1; i < n; i++)
    {
        if (A[i] > maxVal) maxVal = A[i];
        if (A[i] < minVal) minVal = A[i];
    }

    int rango = maxVal - minVal + 1;
    int *conteo = new int[rango];
    for (int i = 0; i < rango; i++)
        conteo[i] = 0;

    for (int i = 0; i < n; i++)
        conteo[A[i] - minVal]++;

    int idx = 0;
    for (int i = 0; i < rango; i++)
    {
        while (conteo[i] > 0)
        {
            A[idx] = i + minVal;
            idx++;
            conteo[i]--;
        }
    }

    delete[] conteo;
}

// ================== MEDICION DE TIEMPO ==================
// clock() de <ctime> mide tiempo de CPU consumido por el proceso.

double medirTiempoBubble(int *A, int n)      { clock_t t0 = clock(); bubbleSort(A, n); return (double)(clock() - t0) * 1000.0 / CLOCKS_PER_SEC; }
double medirTiempoInsertion(int *A, int n)   { clock_t t0 = clock(); insertionSort(A, n); return (double)(clock() - t0) * 1000.0 / CLOCKS_PER_SEC; }
double medirTiempoSelection(int *A, int n)   { clock_t t0 = clock(); selectionSort(A, n); return (double)(clock() - t0) * 1000.0 / CLOCKS_PER_SEC; }
double medirTiempoMerge(int *A, int n)       { clock_t t0 = clock(); if (n > 0) mergeSort(A, 0, n - 1); return (double)(clock() - t0) * 1000.0 / CLOCKS_PER_SEC; }
double medirTiempoQuick(int *A, int n)       { clock_t t0 = clock(); if (n > 0) quickSort(A, 0, n - 1); return (double)(clock() - t0) * 1000.0 / CLOCKS_PER_SEC; }
double medirTiempoCounting(int *A, int n)    { clock_t t0 = clock(); countingSort(A, n); return (double)(clock() - t0) * 1000.0 / CLOCKS_PER_SEC; }

// ================== MENUS ==================

string NOMBRES[6] = {
    "Bubble Sort", "Insertion Sort", "Selection Sort",
    "Merge Sort", "Quick Sort", "Counting Sort"};

void ejecutarMetodo(int indice, int *numeros, int n, int *resultados[6], double tiempos[6], bool ejecutado[6])
{
    copiarArreglo(resultados[indice], numeros, n);

    switch (indice)
    {
        case 0: tiempos[indice] = medirTiempoBubble(resultados[indice], n); break;
        case 1: tiempos[indice] = medirTiempoInsertion(resultados[indice], n); break;
        case 2: tiempos[indice] = medirTiempoSelection(resultados[indice], n); break;
        case 3: tiempos[indice] = medirTiempoMerge(resultados[indice], n); break;
        case 4: tiempos[indice] = medirTiempoQuick(resultados[indice], n); break;
        case 5: tiempos[indice] = medirTiempoCounting(resultados[indice], n); break;
    }

    ejecutado[indice] = true;

    cout << NOMBRES[indice] << " (";
    imprimirDecimal(tiempos[indice], 4);
    cout << " ms): ";
    mostrar(resultados[indice], n);
}

void submenuOrdenar(int *numeros, int n, int *resultados[6], double tiempos[6], bool ejecutado[6])
{
    int opcion;

    do
    {
        cout << "\n======================================== \n";
        cout << " METODOS DE ORDENAMIENTO \n";
        cout << "======================================== \n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Counting Sort\n";
        cout << "7. Todos los metodos\n";
        cout << "8. Regresar\n";
        cout << "Selecciona un metodo: ";
        cin >> opcion;

        if (n <= 0 && opcion != 8)
        {
            cout << "Primero genera numeros aleatorios (opcion 1 del menu principal).\n";
            continue;
        }

        if (opcion >= 1 && opcion <= 6)
        {
            ejecutarMetodo(opcion - 1, numeros, n, resultados, tiempos, ejecutado);
        }
        else if (opcion == 7)
        {
            for (int i = 0; i < 6; i++)
                ejecutarMetodo(i, numeros, n, resultados, tiempos, ejecutado);
        }
        else if (opcion == 8)
        {
            // regresar al menu principal
        }
        else
        {
            cout << "Opcion no valida.\n";
        }

    } while (opcion != 8);
}

void mostrarResultados(double tiempos[6], bool ejecutado[6])
{
    bool hayResultados = false;
    for (int i = 0; i < 6; i++)
        if (ejecutado[i]) hayResultados = true;

    if (!hayResultados)
    {
        cout << "\nAun no se ha ejecutado ningun metodo.\n";
        return;
    }

    cout << "\n======================================== \n";
    cout << " RESULTADOS (tiempo de ejecucion) \n";
    cout << "======================================== \n";
    imprimirPad("Algoritmo", 20);
    cout << "Tiempo (ms)\n";
    cout << "----------------------------------------\n";

    int mejor = -1;
    for (int i = 0; i < 6; i++)
    {
        if (!ejecutado[i]) continue;

        imprimirPad(NOMBRES[i], 20);
        imprimirDecimal(tiempos[i], 4);
        cout << "\n";

        if (mejor == -1 || tiempos[i] < tiempos[mejor])
            mejor = i;
    }

    if (mejor != -1)
    {
        cout << "----------------------------------------\n";
        cout << "Mas rapido: " << NOMBRES[mejor] << "\n";
    }
}

// ================== MAIN ==================

int main()
{
    inicializarSemilla();

    int *numeros = nullptr;
    int cantidadNumeros = 0;

    int *resultados[6] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    double tiempos[6] = {0, 0, 0, 0, 0, 0};
    bool ejecutado[6] = {false, false, false, false, false, false};

    int opcion;

    do
    {
        cout << "\n----- Menu Principal -----\n";
        cout << "1. Generar numeros aleatorios\n";
        cout << "2. Mostrar numeros generados\n";
        cout << "3. Ordenar con un metodo\n";
        cout << "4. Comparar todos los metodos\n";
        cout << "5. Mostrar resultados\n";
        cout << "6. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            int cantidad, minR, maxR;

            cout << "Cantidad de numeros a generar: ";
            cin >> cantidad;
            cout << "Valor minimo: ";
            cin >> minR;
            cout << "Valor maximo: ";
            cin >> maxR;

            if (cantidad <= 0 || minR > maxR)
            {
                cout << "Datos invalidos.\n";
                continue;
            }

            delete[] numeros;
            for (int i = 0; i < 6; i++)
            {
                delete[] resultados[i];
                resultados[i] = nullptr;
                ejecutado[i] = false;
            }

            numeros = new int[cantidad];
            cantidadNumeros = cantidad;

            for (int i = 0; i < cantidad; i++)
                numeros[i] = siguienteAleatorio(minR, maxR);

            for (int i = 0; i < 6; i++)
                resultados[i] = new int[cantidad];

            cout << "Numeros generados correctamente.\n";
        }
        else if (opcion == 2)
        {
            cout << "Numeros generados: ";
            mostrar(numeros, cantidadNumeros);
        }
        else if (opcion == 3)
        {
            submenuOrdenar(numeros, cantidadNumeros, resultados, tiempos, ejecutado);
        }
        else if (opcion == 4)
        {
            if (cantidadNumeros <= 0)
            {
                cout << "Primero genera numeros aleatorios.\n";
                continue;
            }

            cout << "\nComparando todos los metodos...\n";

            for (int i = 0; i < 6; i++)
            {
                copiarArreglo(resultados[i], numeros, cantidadNumeros);

                switch (i)
                {
                    case 0: tiempos[i] = medirTiempoBubble(resultados[i], cantidadNumeros); break;
                    case 1: tiempos[i] = medirTiempoInsertion(resultados[i], cantidadNumeros); break;
                    case 2: tiempos[i] = medirTiempoSelection(resultados[i], cantidadNumeros); break;
                    case 3: tiempos[i] = medirTiempoMerge(resultados[i], cantidadNumeros); break;
                    case 4: tiempos[i] = medirTiempoQuick(resultados[i], cantidadNumeros); break;
                    case 5: tiempos[i] = medirTiempoCounting(resultados[i], cantidadNumeros); break;
                }

                ejecutado[i] = true;

                cout << NOMBRES[i] << " -> ";
                imprimirDecimal(tiempos[i], 4);
                cout << " ms\n";
            }

            mostrarResultados(tiempos, ejecutado);
        }
        else if (opcion == 5)
        {
            mostrarResultados(tiempos, ejecutado);
        }
        else if (opcion == 6)
        {
            cout << "Saliendo del programa...\n";
        }
        else
        {
            cout << "Opcion no valida.\n";
        }

    } while (opcion != 6);

    delete[] numeros;
    for (int i = 0; i < 6; i++)
        delete[] resultados[i];

    return 0;
}
