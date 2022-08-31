#include <stdio.h>
#define TAM  9

int vetor[TAM] = {9,8,6,7,5,3,4,1,2};

void list (int v[], int tamanho){
    int i;
    printf("Lista de valores: \n");
    for (i = 0; i<tamanho; i++){
        printf("%d", v[i]);
    }
    printf("\n");
}

int selectionSort (int v[], int tamanho){
    int i, j, temp;
    for (i=0; i < tamanho - 1; i++){
        for (j= i + 1; j < tamanho; j++){
            if(v[j]<v[i]){
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }

    }

}

int main(){

    list (vetor, TAM);
    selectionSort(vetor, TAM);
    list (vetor, TAM);
    return 0;
} 
