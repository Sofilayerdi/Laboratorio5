#include <stdio.h>
#include <omp.h>

int main() {
    int variable1 = 0;  
    int variable2 = 0; 

    #pragma omp parallel for shared(variable1)
        for (int i=0; i<10; i++) {
            variable1 += 1;
            printf("Hilo %d: Variable 1= %d\n", omp_get_thread_num(), variable1);
        }
    

    #pragma omp parallel for private(variable2)
    
        for (int i=0; i<10; i++){
            variable2 = 0;
            variable2 += 1;
            printf("Hilo %d: Variable 2= %d\n", omp_get_thread_num(), variable2);
        }
    

    return 0;

}