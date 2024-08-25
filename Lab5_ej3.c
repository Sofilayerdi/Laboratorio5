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
                int primo = 1;
                for (int j = 2; j <= sqrt(i); j++) {
                    if (i % j == 0) {
                        primo = 0;
                        break;
                    }
                }
                if (primo) {
                    suma += i;
                }
            }
            printf("La suma de los numeros primos hasta %d es %d\n", n, suma);
            
        }

         #pragma omp section
        {
            /* Encontrar valor mas grande demun array */
            int array[] = {3, 45, 7, 23, 87, 12};
            int size = sizeof(array) / sizeof(array[0]);
            int maximo = array[0];
            for (int i = 1; i < size; i++) {
                if (array[i] > maximo) {
                    maximo = array[i];
                }
            }
            printf("El valor maximo en el arreglo es %d\n", maximo);
        }

    

    }

}
