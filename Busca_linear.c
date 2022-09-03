#include <stdio.h>

//Função elaborada:

int buscaLinear(int v[], int n, int elemento){
    for (int i = 0; i < n; i++){
        if (v[i] == elemento)
            return i;
        }
        return -1;
    }

int main(){
//vetor criado:
    int v[6] = {3, 2, 5, 7, 4, 9};

//imprimindo função:
    printf("%d \n", buscaLinear(v, 6, 2));

    return 0;

}
