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
	printf("Cadastro do Paciente (Nao esqueca de salvar!):\n");
	printf("-------------------------\n");
//      Pergunta                        Resposta
	printf("Nome: ");                   fflush(stdin); scanf("%[^\n]s", cliente.nome);
	printf("CPF: ");                    scanf("%s",cliente.CPF);
	printf("Data de Nascimento:");      scanf("%d/%d/%d", &cliente.dia,&cliente.mes,&cliente.ano);
	printf("Endereco: ");               fflush(stdin); scanf("%[^\n]s",cliente.endereco);
	printf("Telefone(XX)9XXXXXXXX: ");  scanf("%s",cliente.telefone);
    
    cont ++;
    return cliente;
}

//2. função que lista as strings informadas
void listar(cadastro cad[limite]){
    printf("Lista de Pacientes:\n");
        for (int j = 0; j < limite; j++){ //um array (j) para contar a lista dentro de outro array (i)
            printf("-----------------PACIENTE %d-------------------", j+1);
            printf("\nNome-------------: %s", cad[j].nome);
            printf("\nCPF--------------: %s", cad[j].CPF);
            printf("\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
            printf("\nEndereco-----------: %s", cad[j].endereco);
            printf("\nTelefone-----------: %s", cad[j].telefone);
            printf("\n-----------------------------------------------\n");
        }
        system ("pause >>NULL");
}

//3. salvando dados em arquivo
void salvar(cadastro cad[limite]){
    int j;
    FILE *arq;
    arq = fopen("CLIENTES.txt", "w");
    fprintf(arq, "%d\n", 100);
    for (j=0; j<limite; j++){
        fprintf(arq,"-----------------PACIENTE %d-------------------", j+1);
        fprintf(arq,"\nNome-------------: %s", cad[j].nome);
        fprintf(arq,"\nCPF--------------: %s", cad[j].CPF);
        fprintf(arq,"\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
        fprintf(arq,"\nEndereço-----------: %s", cad[j].endereco);
        fprintf(arq,"\nTelefone-----------: %s", cad[j].telefone);
        fprintf(arq,"\n-----------------------------------------------\n");
    }
    
    fclose (arq);
    
    printf("Dados salvos com sucesso.\n");
}

//Abrir arquivo para ler
void abrir(cadastro cad[limite]){
    FILE *arq;
    arq = fopen("CLIENTES.txt", "r");
    if (arq == NULL){
        printf("Arquivo nao encontrado");
        system("pause");
    }
    for (int j=0; j<limite; j++){
        fscanf(arq,"-----------------PACIENTE %d-------------------", j+1);
        fscanf(arq,"\nNome-------------: %s", cad[j].nome);
        fscanf(arq,"\nCPF--------------: %s", cad[j].CPF);
        fscanf(arq,"\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
        fscanf(arq,"\nEndereco-----------: %s", cad[j].endereco);
        fscanf(arq,"\nTelefone-----------: %s", cad[j].telefone);
        fscanf(arq,"\n-----------------------------------------------\n");    
    
    }

    for (int j=0; j<limite; j++){
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
int pesquisar(struct Cliente lista[limite], char item[tamanho], bool escolha){
   int foiEncontrado = -1;
   
   for (int i = 0; i < limite; i++){
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

//7. Algoritmo de ordenação
void emOrdem(cadastro cad[limite], int N){
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


//8.Agendamento de consulta
void agendarConsulta(cadastro cad[], int N, char servico[], char data[], char hora[] ){
    int agenda;
    for (int i = 0; i < N; i++){
    printf("%d. %s\n", i+1, cad[i].nome);
    }
    printf("Em qual cliente sera o atendimento?\n");
    fflush(stdin);
    scanf("Opcao: %d", &i);
    i = i-1;
    fflush(stdin);
    printf("Qual o tipo de servico deseja fazer?\n1. Verificacao de pressao arterial;\n2. Glicemia.\n");
    scanf("%d", &agenda);
    while ((agenda<1)&&(agenda>2)){
    if (agenda==1){
        servico = "Pressao"; 
        }else if(agenda==2){
        servico = "Glicemia";
        }
        else{
            printf("Opcao invalida. tente novamente");
        }
    }
    printf("Para qual data (DD/MM/AAAA)?\n");
    scanf("%s", data);
    printf("Que horas?\n");
    scanf("%s", hora);
    printf("Paciente %s agendado para uma verificacao de %s.\n", cad[i].nome, servico);
    
    agendamento(cad, i, servico, data, hora);
}

//procedimento para salvar o agendamento da consulta em arquivo
void agendamento(cadastro cad[], int N, char s[], char d[], char h[]){
    FILE *arq;
    arq = fopen("AGENDA.txt", "w");
    fprintf(arq, "\nAGENDAMENTO DE PACIENTES: \n");
    fprintf(arq, "-----------------------------\n");
    fprintf(arq, "Nome: %s\n", cad[N].nome);
    fprintf(arq, "Endereco: %s\n", cad[N].endereco);
    fprintf(arq, "Telefone: %s\n", cad[N].telefone);
    fprintf(arq, "Servico agendado: verificacao de %s\n", s);
    fprintf(arq, "Data: %s\n", d);
    fprintf(arq, "Horario: %s\n", h);
    fprintf(arq, "-----------------------------\n");
    
    fclose (arq);
}

void salvarConsultaPressao(cadastro cad[limite], int i, char d, char f, char b, char tM, char m[20], char p[10])
{
    FILE *arq;
    arq = fopen("PRESSAO.txt","w");
    fprintf(arq,"--------------------PRESSAO ARTERIAL----------------------");
    fprintf(arq,"\nNome-------------: %s", cad[i].nome);
    fprintf(arq,"\nCPF--------------: %s", cad[i].CPF);
    fprintf(arq,"\nData de Nascimento-: %d/%d/%d", cad[i].dia, cad[i].mes, cad[i].ano);
    fprintf(arq,"\nEndereco-----------: %s", cad[i].endereco);
    fprintf(arq,"\nTelefone-----------: %s", cad[i].telefone);
    fprintf(arq,"\nDormiu bem?: %c", &d);
    fprintf(arq,"\nFumou nos ultimos 30min?: %c", &f);
    fprintf(arq,"\nIngeriu bebida alcoolica ou outro tipo nos ultimos 30min?: %c", &b);
    fprintf(arq,"\nTomou medicamento?: %c.    Medicamento: %s", tM, m);
    fprintf(arq,"\nPressao Arterial: %s mmHg", p);
    fprintf(arq,"\n-----------------------------------------------\n");
    
    fclose (arq);
    
    printf("Dados da consulta salvos com sucesso.");
}
//9.1. procedimento de pressão arterial
void consultaPressao(cadastro cad[limite], int N){
    char dormiu, fumou, bebeu, tomouMedicamento, medicamento[50], pressure[7];
    //dados do paciente
    for (int i = 0; i < N; i++){
    printf("%d. %s\n", i+1, cad[i].nome);
    }

    printf("Em qual cliente sera o atendimento?\n");
    fflush(stdin);
    scanf("Opcao: %d", &i);
    i = i-1;
    fflush(stdin);
    printf("Paciente: %s\n", cad[i].nome);
    printf("CPF: %s\n", cad[i].CPF);
    printf("Endereco: %s\n", cad[i].endereco);

    //questionário do paciente
    printf("Dormiu bem? S/N:\n ");
    scanf("%c", &dormiu);
    fflush(stdin);
    printf("Fumou nos ultimos 30min? S/N: \n");
    scanf("%c", &fumou);
    fflush(stdin);
    printf("Tomou bebida alcoolica ou outra bebida estimulante nos ultimos 30min? S/N:\n ");
    scanf("%c", &bebeu);
    fflush(stdin);
    printf("Tomou algum medicamento hoje? S/N: ");
    scanf("%c", &tomouMedicamento);
    if (tomouMedicamento == "S"){
        printf("S. Qual?");
        scanf("%s", medicamento);
        }

    // verificação da pressão:
    fflush(stdin);
    printf("Digite o valor da pressao arterial: ex.: 120x80\n");
    scanf("%s", pressure);
    
    salvarConsultaPressao(cad, i, dormiu, fumou, bebeu, tomouMedicamento, medicamento, pressure);
    }

//procedimento para salvar em arquivo a consulta de glicemia
void salvarConsultaGlicemia(cadastro cad[limite], int i, char j, char uR[20], char tM, char m[30], char g[10])
{
    FILE *arq;
    arq = fopen("GLICEMIA.txt","w");
    fprintf(arq,"--------------------GLICEMIA----------------------");
    fprintf(arq,"\nNome-------------: %s", cad[i].nome);
    fprintf(arq,"\nCPF--------------: %s", cad[i].CPF);
    fprintf(arq,"\nData de Nascimento-: %d/%d/%d", cad[i].dia, cad[i].mes, cad[i].ano);
    fprintf(arq,"\nEndereco-----------: %s", cad[i].endereco);
    fprintf(arq,"\nTelefone-----------: %s", cad[i].telefone);
    fprintf(arq,"\nJejum?: %c", &j);
    fprintf(arq,"\nUltima Refeicao: %s", uR);
    fprintf(arq,"\nTomou medicamento? %c.    Medicamento: %s", tM, m);
    fprintf(arq,"\nGlicemia: %s mg/dL", g);
    fprintf(arq,"\n-----------------------------------------------\n");
    
    fclose (arq);
    
}

//9.2. procedimento para a consulta de glicemia 
void consultaGlicemia(cadastro cad[limite], int N){
    char jejum, ultimaRefeicao[30], tomouMedicamento, medicamento[50], glucemia[4];
    //dados do paciente
    for (int i = 0; i < N; i++){
    printf("%d. %s\n", i+1, cad[i].nome);
    }
    
    printf("Em qual cliente sera o atendimento?\n");
    fflush(stdin);
    scanf("%d", &i);
    fflush(stdin);
    i = i-1;
    printf("Paciente: %s\n", cad[i].nome);
    printf("CPF: %s\n", cad[i].CPF);
    printf("Endereco: %s\n", cad[i].endereco);

    //questionário do paciente
    printf("Esta de jejum? S/N: ");
    scanf("%c", &jejum);
    fflush(stdin);
    printf("Qual a sua ultima refeicao?\n");
    scanf("%s", ultimaRefeicao);
    
    fflush(stdin);
    printf("Tomou algum medicamento hoje? S/N:\n");
    scanf("%c", &tomouMedicamento);
        if (tomouMedicamento == "S"){
            printf("Qual?");
            scanf("%s", medicamento);
        }

    // verificação da pressão:
    fflush(stdin);
    printf("Digite o valor da glicemia: ex.: 100\n");
    scanf("%s", glucemia);
    
    salvarConsultaGlicemia(cad, i, jejum, ultimaRefeicao, tomouMedicamento, medicamento, glucemia);
    }

 
int main(){
    
setlocale(LC_ALL,"portuguese");
int opcao, opcao_busca, opcao_consulta, endereco, *client;
struct Cliente cad[100];
char item[tamanho][limite];
char itemPesquisa[limite], servico[16], data[10], hora[5];

printf ("-----------------------------------------\n");
printf ("CONSULTORIO FARMACEUTICO DR. PAULO LIMA\n");
printf ("-----------------------------------------\n");
printf ("	Sua saude e nossa prioridade\n\n");

while (opcao != 10){
    printf ("1. Cadastrar Cliente\n2. Listar Clientes\n3. Salvar dados\n4. Abrir dados salvos \n5. Pesquisar Cliente por Nome \n6. Pesquisar Cliente por CPF\n7. Lista dos clientes em ordem alfabetica\n8. Agendar\n9. Consulta\n10. Sair\n");
    printf ("Escolha uma das opcoes:\n");
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
            printf("Qual o cliente que voce procura?\n");
            fflush(stdin); scanf("%[^\n]s", &itemPesquisa);
            // realizando a pesquisa do item
            endereco = pesquisar (cad, itemPesquisa, true);
            // imprimindo o resultado da busca
            imprimirResultadoDaBusca(endereco);
            break;
            
        case 6:
            // pedindo um item para pesquisa na lista
            printf("Digite o CPF do paciente que voce deseja procurar na lista:\n");
            fflush(stdin); scanf("%[^\n]s", &itemPesquisa);
            // realizando a pesquisa do item
           endereco = pesquisar (cad, itemPesquisa, false);
            // imprimindo o resultado da busca
            imprimirResultadoDaBusca(endereco);
            break;
            
        case 7:
            emOrdem(cad, tamanho);
            break;
        case 8:
            agendarConsulta(cad, tamanho, servico, data, hora);
            break;
        case 9:
            system("cls");
            printf("Qual a consulta que deseja realizar?\n1.Pressao Arterial\n2.Glicemia\n\n");
            scanf("%d", &opcao_consulta);
            switch (opcao_consulta){
                case 1:
                consultaPressao(cad, tamanho);            
                break;

                case 2:
                consultaGlicemia(cad, tamanho);
                break;
            }
            break;
            
        };
    
}
printf("SAINDO DO SISTEMA!\nVa na paz!");

return 0;

}
