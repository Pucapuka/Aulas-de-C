//importando bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#define limite 100
#define tamanho 100

//contadores em variáveis globais

int i = 0, cdg, cont = 0;

//Criando estrutura de dados heterogênea para os dados do paciente com o nome "cadastro"

typedef struct Cliente{
    char nome[200];
    char CPF[11];
    int dia, mes, ano;
    char endereco[200];
    char telefone[15];
}cadastro;

//1. procedimento para coletar esses os dados do paciente com a struct
cadastro Cadastrador(){
    cadastro cliente/*(cliente é um variável da struct cadastro para dar o retorno)*/;
	printf("Cadastro do Paciente (Não esqueça de salvar!):\n");
	printf("-------------------------\n");
//      Pergunta                        Resposta
	printf("Nome: ");                   fflush(stdin); scanf("%[^\n]s", cliente.nome);
	printf("CPF: ");                    /*fflush(stdin);*/ scanf("%s",cliente.CPF);
	printf("Data de Nascimento:");      scanf("%d/%d/%d", &cliente.dia,&cliente.mes,&cliente.ano);
	printf("Endereço: ");               fflush(stdin); scanf("%[^\n]s",cliente.endereco);
	printf("Telefone(XX)9XXXXXXXX: ");  /*fflush(stdin);*/ scanf("%s",cliente.telefone);
    
    cont ++;
    return cliente;
}

//2. função que lista as strings informadas
void listar(cadastro cad[]){
    printf("Lista de Pacientes:\n");
        for (int j = 0; j < cont; j++){ //um array (j) para contar a lista dentro de outro array (i)
            printf("-----------------PACIENTE %d-------------------", j+1);
            printf("\nNome-------------: %s", cad[j].nome);
            printf("\nCPF--------------: %s", cad[j].CPF);
            printf("\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
            printf("\nEndereço-----------: %s", cad[j].endereco);
            printf("\nTelefone-----------: %s", cad[j].telefone);
            printf("\n-----------------------------------------------\n");
        }
        system ("pause >>NULL");
}

//3. salvando dados em arquivo
void salvar(cadastro cad[]){
    int j;
    FILE *arq;
    arq = fopen("CLIENTES.txt", "w");
    fprintf(arq, "%d\n", 100);
    for (j=0; j<10; j++){
        fprintf(arq,"-----------------PACIENTE %d-------------------", j+1);
        fprintf(arq,"\nNome-------------: %s", cad[j].nome);
        fprintf(arq,"\nCPF--------------: %s", cad[j].CPF);
        fprintf(arq,"\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
        fprintf(arq,"\nEndereço-----------: %s", cad[j].endereco);
        fprintf(arq,"\nTelefone-----------: %s", cad[j].telefone);
        fprintf(arq,"\n-----------------------------------------------\n");
    }
    
    fclose (arq);
    
    printf("Dados salvos com sucesso.");
}

//Abrir arquivo para ler
void abrir(cadastro cad[]){
    //int j;
    FILE *arq;
    arq = fopen("CLIENTES.txt", "r");
    //fscanf(arq, "%d\n", 100);
    if (arq == NULL){
        printf("Arquivo não encontrado");
        system("pause");
        //return 0;
    }
    for (int j=0; j<10; j++){
        fscanf(arq,"-----------------PACIENTE %d-------------------", j+1);
        fscanf(arq,"\nNome-------------: %s", cad[j].nome);
        fscanf(arq,"\nCPF--------------: %s", cad[j].CPF);
        fscanf(arq,"\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
        fscanf(arq,"\nEndereço-----------: %s", cad[j].endereco);
        fscanf(arq,"\nTelefone-----------: %s", cad[j].telefone);
        fscanf(arq,"\n-----------------------------------------------\n");    
    
    }

    for (int j=0; j<10; j++){
        printf(arq,"-----------------PACIENTE %d-------------------", j+1);
        printf(arq,"\nNome-------------: %s", cad[j].nome);
        printf(arq,"\nCPF--------------: %s", cad[j].CPF);
        printf(arq,"\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
        printf(arq,"\nEndereço-----------: %s", cad[j].endereco);
        printf(arq,"\nTelefone-----------: %s", cad[j].telefone);
        printf(arq,"\n-----------------------------------------------\n");
    }
    fclose (arq);
    printf("Arquivo aberto com sucesso.\n");
}

//4. criando algoritmo de busca
// função que faz a pesquisa na lista de strings e retorna o endereço
int pesquisar(struct Cliente lista[100], char item[100], bool escolha){
   int foiEncontrado = -1;
   
   for (int i = 0; i < tamanho; i++){
    if (escolha){
        foiEncontrado = strcmp(lista[i].nome, item);
        if (foiEncontrado == 0)
        return i;
    }else{
        foiEncontrado = strcmp(lista[i].CPF, item);
        if (foiEncontrado == 0)
        return i;
        
    }
   }
   return -1;
}

// função que imprime o resultado da pesquisa na lista de strings
void imprimirResultadoDaBusca(int resultado){
    if (resultado >= 0)
    {
        printf("Item encontrado no endereco:%d\n\n", resultado + 1);
    }
    else
    {
        printf("Item nao encontrado. Reveja o item pesquisado ou cadastre o cliente.\n");
    }
}

//Algoritmo de ordenação
void emOrdem(cadastro cad[], int N){
    int i, j, r;
    struct Cliente aux [100];
    for (i = 0; i <= N -1; i++){
        for (j = i + 1; j <= 100; j++){
            r = strcmp (cad[i].nome, cad[j].nome);
            if (r > 0){
                strcpy (aux, cad[i].nome);
                strcpy (cad[i].nome, cad[j].nome);
                strcpy (cad[j].nome, aux);
            }
        }
    }
    printf("\nNomes ordenados:\n");
    for(i = 0; i < N-1; i ++){
    printf("\nNome-------------: %s\n", cad[i].nome);
    }

}

//Abertura de consulta
/*//seleção do paciente
int paciente(cadastro cad[], int N){
printf("Em qual cliente será o atendimento?\n");
for (int i = 0; i < N; i++){
    printf("%d. %s\n", i+1, cad[i].nome);
}
    scanf("%d", i);
    return i;
}*/

void agendarConsulta(cadastro cad[], int N){
    int agenda;
    for (int i = 0; i < N; i++){
    printf("%d. %s\n", i+1, cad[i].nome);
    }
    printf("Em qual cliente será o atendimento?\n");
    fflush(stdin);
    scanf("Opção: %d", &i);
    i = i-1;
    fflush(stdin);
    printf("Qual o tipo de serviço deseja fazer?\n1. Verificação de pressão arterial;\n2. Glicemia.");
    scanf("%d", &agenda);
    if (agenda==1){
        printf("Paciente %s agendado para uma verificação de pressão arterial.\n", cad[i].nome);
        }else if(agenda==2){
        printf("Paciente %s agendado para um teste de glicemia.\n", cad[i].nome);
        }
        else{
            printf("Opção inválida. tente novamente");
            return -1;
        }
    }


void salvarConsulta(cadastro cad[], int N){
    char dormiu, fumou, bebeu, tomouMedicamento, medicamento, pressure;
    int j;
    pressao(cad, tamanho, j);
    FILE *arq;
    arq = fopen("CONSULTA.txt","w");
    fprintf(arq,"--------------------PRESSÃO ARTERIAL----------------------");
    fprintf(arq,"\nNome-------------: %s", cad[j].nome);
    fprintf(arq,"\nCPF--------------: %s", cad[j].CPF);
    fprintf(arq,"\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
    fprintf(arq,"\nEndereço-----------: %s", cad[j].endereco);
    fprintf(arq,"\nTelefone-----------: %s", cad[j].telefone);
    fprintf(arq,"\nDormiu bem?: %c", &dormiu);
    fprintf(arq,"\nFumou nos últimos 30min?: %c", &fumou);
    fprintf(arq,"\nIngeriu bebida alcoólica ou outro tipo nos últimos 30min?: %c", &bebeu);
    fprintf(arq,"\nTomou medicamento?: %c. Medicamento: %s", &tomouMedicamento, medicamento);
    fprintf(arq,"\nPressão Arterial: %s", pressure);
    fprintf(arq,"\n-----------------------------------------------\n");
    
    fclose (arq);
    
    printf("Dados da consulta salvos com sucesso.");
}
//procedimento de pressão arterial
void pressao(cadastro cad[], int N, int i){
    char dormiu, fumou, bebeu, tomouMedicamento, medicamento, pressure;
    //dados do paciente
    for (int i = 0; i < N; i++){
    printf("%d. %s\n", i+1, cad[i].nome);
    }
    printf("Em qual cliente será o atendimento?\n");
    fflush(stdin);
    scanf("Opção: %d", &i);
    i = i-1;
    fflush(stdin);
    printf("Paciente: %s\n", cad[i].nome);
    printf("CPF: %s\n", cad[i].CPF);
    printf("Endereço: %s\n", cad[i].endereco);

    //questionário do paciente
    printf("Dormiu bem? S/N: ");
    scanf("%c", &dormiu);
    if ((dormiu == "S") || (dormiu =="N")){
        printf("%c", dormiu);
    }else{
        printf("digite uma resposta válida");
    }

    printf("Fumou nos últimos 30min? S/N: ");
    scanf("%c", &fumou);
    if ((fumou == "S") || (fumou =="N")){
        printf("%c", fumou);
    }else{
        printf("digite uma resposta válida");
    }

        printf("Tomou bebida alcoólica ou outra bebida estimulante nos últimos 30min? S/N: ");
        scanf("%c", &bebeu);
    
    if ((bebeu == "S") || (bebeu =="N")){
        printf("%c", bebeu);
    }else{
        printf("digite uma resposta válida");
    }
    
    printf("Tomou algum medicamento hoje? S/N:");
    scanf("%c", &tomouMedicamento);
    if (tomouMedicamento == "S"){
        printf("S. Qual?");
        scanf("%s", medicamento);
    }else if(tomouMedicamento =="N"){
        printf("N.");
    }else
        printf("digite uma resposta válida");
    
    // verificação da pressão:

    printf("Digite o valor da pressão arterial: ex.: 120x80");
    scanf("%s", pressao);
    }


 
int main(){
    
setlocale(LC_ALL,"portuguese");
//system("cls");
int opcao, opcao_busca, endereco, *client;
struct Cliente cad[100];
char item[tamanho][limite];
char itemPesquisa[limite];

printf ("-----------------------------------------\n");
printf ("CONSULTÓRIO FARMACÊUTICO DR. PAULO LIMA\n");
printf ("-----------------------------------------\n");
printf ("	Sua saúde é nossa prioridade\n\n");

while (opcao != 10){
    //system("cls");
    printf ("1. Cadastrar Cliente\n2. Listar Clientes\n3. Salvar dados\n4. Abrir dados salvos \n5. Pesquisar Cliente por Nome \n6. Pesquisar Cliente por CPF\n7. Lista dos clientes em ordem alfabética\n8. Agendar\n9. Consulta\n10. Sair\n");
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
        
        case 3:
            salvar(cad);
            break;
        
        case 4:
            abrir(cad);
            break;

        case 5:
         
            // pedindo um item para pesquisa na lista
            printf("Qual o cliente que você procura?\n");
            fflush(stdin); scanf("%[^\n]s", &itemPesquisa);
            // realizando a pesquisa do item
            endereco = pesquisar (cad, itemPesquisa, true);
            // imprimindo o resultado da busca
            imprimirResultadoDaBusca(endereco);
            break;
            
        case 6:
            // pedindo um item para pesquisa na lista
            printf("Digite o CPF do paciente que você deseja procurar na lista:\n");
            fflush(stdin); scanf("%[^\n]s", &itemPesquisa);
            // realizando a pesquisa do item
           endereco = pesquisar (cad, itemPesquisa, false);
            // imprimindo o resultado da busca
            imprimirResultadoDaBusca(endereco);
            break;
            
        //fflush(stdin);
        case 7:
            emOrdem(cad, tamanho);

        case 8:
            agendarConsulta(cad, tamanho);
            break;
        case 9:
            salvarConsulta(cad, tamanho);
            break;

        };
    
}
printf("SAINDO DO SISTEMA!\nVá na paz!");

return 0;

}
