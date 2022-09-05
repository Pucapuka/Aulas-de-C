// programa que pede strings, faz uma lista, pede um item para pesquisa, e procura na lista se o item está presente retornando seu endereço
// incluindo as bibliotecas nescessárias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// função que imprime o resultado da pesquisa na lista de strings
void imprimirResultadoDaBusca(resultado)
{
    if (resultado >= 0)
    {
        printf("Item encontrado no endereco:%d\n\n", resultado + 1);
    }
    else
    {
        printf("Item nao encontrado.\n");
    }
}

// função que faz a pesquisa na lista de strings e retorna o endereço
int pesquisar(int tamanho, int limite, char lista[tamanho][limite], char item[limite])
{
    int i, comparador;
    for (i = 0; i < tamanho; i++)
    {
        comparador = strcmp(item, lista[i]);
        if (comparador == 0)
        {
            return i;
        }
    }
    if (comparador != 0)
    {
        return -1;
    }
}

// função que lista as strings informadas
void listar(int tamanho, int limite, char lista[tamanho][limite])
{
    printf("Sua lista:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d.%s\n", i + 1, lista[i]);
    }
    printf("\n");
}

int main()
{
    // declarando variaveis
    int tamanho = 5, limite = 100;
    int endereco;
    char item[tamanho][limite];
    char itemPesquisa[limite];

    // recebendo as strings e montando a lista
    printf("Vamos montar sua lista:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite seu item %d:", i + 1);
        scanf("%s", &item[i]);
    }
    printf("\n");

    // mostrando a lista
    listar(tamanho, limite, item);

    // pedindo um item para pesquisa na lista
    printf("Digite um item para buscar na lista: ");
    scanf("%s", &itemPesquisa);
    printf("\n");

    // realizando a pesquisa do item
    endereco = pesquisar(tamanho, limite, item, itemPesquisa);

    // imprimindo o resultado da busca
    imprimirResultadoDaBusca(endereco);
    return 0;
}
