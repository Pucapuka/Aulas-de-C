//importando bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

//contadores em variáveis globais

int i = 0, cdg, cont = 0;

//Criando estrutura de dados heterogênea para os dados do paciente com o nome "cadastro"

typedef struct Cliente{
    char nome[50];
    char CPF[11];
    int dia, mes, ano;
    char endereco[200];
    char telefone[15];
}cadastro;

//1. procedimento para coletar esses os dados do paciente com a struct
cadastro Cadastrador(){
    cadastro cliente/*(cliente é um variável da struct cadastro para dar o retorno)*/;
	printf("Cadastro do Paciente:\n");
	printf("-------------------------\n");
//      Pergunta                        Resposta
	printf("Nome: ");                   fflush(stdin); scanf("%s", cliente.nome);
	printf("CPF: ");                    fflush(stdin); scanf("%s",cliente.CPF);
	printf("Data de Nascimento:");      scanf("%d/%d/%d", &cliente.dia,&cliente.mes,&cliente.ano);
	printf("Endereço: ");               fflush(stdin); scanf("%s",cliente.endereco);
	printf("Telefone(XX)9XXXXXXXX: ");  fflush(stdin); scanf("%s",cliente.telefone);
    
    cont ++;
    return cliente;
}

//2. função que lista as strings informadas
listar(cadastro cad[]){
    printf("Lista de Pacientes:\n");
        for (int j = 0; j < cont; j++){ //um array (j) para contar a lista dentro de outro array (i)
            printf("\nNome-------------: %s", cad[j].nome);
            printf("\nCPF--------------: %s", cad[j].CPF);
            printf("\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
            printf("\nEndereço-----------: %s", cad[j].endereco);
            printf("\nTelefone-----------: %s", cad[j].telefone);
        }
        system ("pause >>NULL");
}

//criando algoritmo de busca
/*
void busca(){
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


int algoritmoBusca(int tamanho, int endereco){
    // declarando variáveis
    tamanho = 5; 
    limite = 100;
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
}

}

//função que ordena os clientes alfabeticamente
void Ordenador(){
    char nome[10][80];
 
void emOrdem(){
    int i, j, r;
    char aux [80];
    for (i = 0; i <= 10 -1; i++){
        for (j = i + 1; j <= 10; j++){
            r = strcmp (nome[i], nome[j]);
            if (r > 0){
                strcpy (aux, nome[i]);
                strcpy (nome[i], nome[j]);
                strcpy (nome[j], aux);
            }
        }
    }
}
 
void nameColection (){
    int i;
    printf("Digite 10 nomes:\n");
    for(i = 0; i < 10 ; i ++){
        gets(nome[i]);
    }
}
 
 
void showNames(){
    int i;
    printf("\nNomes ordenados:\n");
    for(i = 0; i < 10; i ++){
    puts(nome[i]);
    }
}
 //para chamar no int main  
    nameColection();
   
    emOrdem();
 
    showNames();
   
 
    return 0;
}
}
*/
int main(){
    
setlocale(LC_ALL,"portuguese");
system("cls");
int opcao;
cadastro cad[100];

printf ("-----------------------------------------");
printf ("CONSULTÓRIO FARMACÊUTICO DR. PAULO LIMA");
printf ("-----------------------------------------");
printf ("	Sua saúde é nossa prioridade\n\n");

while (opcao != 7){
    system("cls");
    printf ("1. Cadastrar Cliente\n2. Listar Clientes\n3. Pesquisar Cliente\n4. Ordenar Clientes\n5. Agendar Consulta\n6. Realizar Consulta\n7. Sair\n");
    printf ("Escolha uma das opções:\n");
    scanf("%d", &opcao);
    system("cls");
    switch (opcao){
        case 1:
            cad[i] = Cadastrador();
            i++;
            break;
        case 2:
            listar(cad);
            break;
        /*  case 3:
            busca();
            break;
        case 4:
            Ordenador();
            break;
        case 5:
            agendar(); //falta essa função
            break;
        case 6:
            consulta(); //falta essa função
            break;*/

        };
}

printf("SAINDO DO SISTEMA!\nVá na paz!");

return 0;
}
