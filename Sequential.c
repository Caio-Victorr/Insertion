#include <stdio.h>
#include <stdlib.h>

FILE *file;

void ordemSequencial(){

    file = fopen("C:\\Users\\Caio victor\\Desktop\\arquivoteste.txt", "r");

    int A[1000];

    for(int l = 0; l < 1000; l++){
        fscanf(file, "%i ", &A[l]); 
    }
    fclose(file);

    int j, pivo = 0;
    for(int i = 1; i < 1000 ; i++){
        pivo = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > pivo){
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = pivo;
    }

    file = fopen("C:\\Users\\Caio victor\\Desktop\\arquivoteste.txt", "w");

    printf("[");
    for (int k = 0; k < 1000; k++){
        printf("%i", A[k]);
        if(k != 999){
                printf(", ");
            }
        fprintf(file, "%d ", A[k]);
    }
    printf("]");
    fclose(file);
}

int main(int argc, char *argv[]){

    file = fopen("C:\\Users\\Caio victor\\Desktop\\arquivoteste.txt", "w");

    for (int i = 0; i < 1000; i++){
        fprintf(file, "%i ",rand());
    }
    fclose(file);

    ordemSequencial();

    return 0;
}