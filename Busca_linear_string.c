#include <stdio.h>
#include <string.h>

int buscaLinear(char vetor[], int tamanho, char chave){
    for (int i = 0; i < tamanho; i++){
        if (vetor[i]== chave){
            return i;
        }
    }
    return -1;
}


int main(){
    
    char nome[100];
    char chave;
    int posicao;
    printf("Digite um nome:");
    scanf ("%s", nome);
    getchar();
    printf("Escolha um caractere:");
    scanf("%c", &chave);
    getchar();
    posicao = buscaLinear(nome, strlen(nome), chave);

    if (posicao == -1){
        printf("'%c' nao foi encontrado.", chave);
    }else{
        printf("Caractere encontrado na linha %c.", posicao);
    }
    return 0;

}
