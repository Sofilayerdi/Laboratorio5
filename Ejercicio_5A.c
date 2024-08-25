/*
 * Archivo: Ejercicio_5A.c
 * Descripción: Este programa cuenta cuántas veces aparece un valor específico 
 * ('key') en un arreglo de números aleatorios.
 * 
 * Funcionalidad:
 * - Genera un arreglo de tamaño N con valores aleatorios.
 * - Inserta manualmente el valor 'key' en tres posiciones específicas del arreglo.
 * - Cuenta cuántas veces aparece 'key' en el arreglo usando una función llamada count_key().
 * - Imprime el número de apariciones de 'key' en el arreglo.
 * 
 * Referencia:
 * Chandra, . R. et al. Parallel Programming in OpenMP
 *
 * Fecha modificación: 08-16-2024
 */
 
#include <stdio.h>
#include <stdlib.h>

#define N 131072
#define MIN_SIZE 1024

long count_key_recursive(long *a, long start, long end, long key) {
    long count = 0;

    if (end - start <= MIN_SIZE) {
        for (long i = start; i < end; i++) {
            if (a[i] == key) count++;
        }
    } else {
        long mid = (start + end) / 2;
        long count1 = 0, count2 = 0;

        #pragma omp task shared(count1) if (end - start > MIN_SIZE)
        count1 = count_key_recursive(a, start, mid, key);

        #pragma omp task shared(count2) if (end - start > MIN_SIZE)
        count2 = count_key_recursive(a, mid, end, key);

        #pragma omp taskwait 
        count = count1 + count2;
    }

    return count;
}

int main() {
    long a[N], key = 42, nkey = 0;
    for (long i = 0; i < N; i++) a[i] = rand() % N;
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;
    
    #pragma omp parallel
    {
        #pragma omp single
        nkey = count_key_recursive(a, 0, N, key);
    }

    printf("Numero de veces que 'key' aparece secuencialmente: %ld\n", nkey);

    return 0;
}
