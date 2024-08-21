#include <stdio.h>
#include <omp.h>

int main() {
    const int N=1000000;
    double suma = 0.0;
    double array[N];
    int i;

  
    for (i=0; i<N; i++)
    {
        array[i]= i*2;
    }

    #pragma omp parallel for reduction(+:suma) 
    {
        for (i=0; i < N; i++){
            suma += array[i];
        }
    }

    printf("La suma es suma\n");
    printf("El tiempo fue de ", omp_get_wtime());

}