#include <stdio.h>
#include <omp.h>

int main() {
    const int N=1000000;
    long suma = 0;
    int i;
    double start_time, end_time;

    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:suma) 
    for (i = 1; i <= N; i++) {
        suma += i;
    }


    end_time = omp_get_wtime();

    double sum = end_time - start_time;

    printf("La suma es %d\n ", suma);
    printf("El tiempo fue de %f", end_time - start_time);

    return 0;

}