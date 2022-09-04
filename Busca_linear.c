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
    int n;
//perguntando a busca:
    printf ("Qual elemento esta procurando?\n");
    scanf("%d", &n);

//imprimindo função:
    if (buscaLinear(v,6,n)==-1){
        printf("O elemento que voce busca nao foi encontrado.");
    }
    printf("O que voce busca esta na posicao %d \n", buscaLinear(v, 6, n));

    return 0;

}
