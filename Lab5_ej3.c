#include <stdio.h>
#include <omp.h>
#include <math.h>

int main(int argc, char* argv[]) {
    #pragma omp parallel sections
    {

        #pragma omp section
        {
            /* calcular factorial de un numero */
            int num = 8;
            int factorial = 1;
            for (int i = 1; i <= num; i++) {
                factorial *= i;
            }

            printf("El factorial del numero %d es %d\n", num, factorial);
        }

        #pragma omp section
        {
            /* Suma los los numeros primos en N */
            int n = 30;
            int suma = 0;
            for (int i = 2; i <= n; i++) {
                int es_primo = 1;
                for (int j = 2; j <= sqrt(i); j++) {
                    es_primo = es_primo && (i % j != 0);
                }
            if (es_primo) {
                suma += i;
            }
            
    

        #pragma omp section
        {
            void encontrar_maximo(int arr[], int size) {
            int maximo = arr[0];
            for (int i = 1; i < size; i++) {
                if (arr[i] > maximo) {
                    maximo = arr[i];
                }
            }
            printf("El valor máximo en el arreglo es %d\n", maximo);
            }

    

        }

    }
}

    }
}
