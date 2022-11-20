//importando bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#define MAX 100

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
	printf("CPF: ");                    fflush(stdin); scanf("%s",cliente.CPF);
	printf("Data de Nascimento:");      scanf("%d/%d/%d", &cliente.dia,&cliente.mes,&cliente.ano);
	printf("Endereço: ");               fflush(stdin); scanf("%[^\n]s",cliente.endereco);
	printf("Telefone(XX)9XXXXXXXX: ");  fflush(stdin); scanf("%s",cliente.telefone);
    
    cont ++;
    return cliente;
}

//2. função que lista as strings informadas
listar(cadastro cad[]){
    printf("Lista de Pacientes:\n");
        for (int j = 0; j < cont; j++){ //um array (j) para contar a lista dentro de outro array (i)
            printf("-----------------PACIENTE %d-------------------", j+1);
            printf("\nNome-------------: %s", cad[j].nome);
            printf("\nCPF--------------: %s", cad[j].CPF);
            printf("\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
            printf("\nEndereço-----------: %s", cad[j].endereco);
            printf("\nTelefone-----------: %s", cad[j].telefone);
            printf("-----------------------------------------------");
        }
        system ("pause >>NULL");
}

//3. salvando dados em arquivo
void salvar(cadastro cad[]){
    int j;
    FILE *arq;
    arq = fopen("CLIENTES.txt", "w");
    fprintf(arq, "%d\n", 100);
    for (j=0; j<100; j++){
        fprintf("-----------------PACIENTE %d-------------------", j+1);
        fprintf(arq,"\nNome-------------: %s", cad[j].nome);
        fprintf(arq,"\nCPF--------------: %s", cad[j].CPF);
        fprintf(arq,"\nData de Nascimento-: %d/%d/%d", cad[j].dia, cad[j].mes, cad[j].ano);
        fprintf(arq,"\nEndereço-----------: %s", cad[j].endereco);
        fprintf(arq,"\nTelefone-----------: %s", cad[j].telefone);
        fprintf(arq,"-----------------------------------------------");
    }
    printf("Dados salvos com sucesso.");
}

//4. criando algoritmo de busca
/*int buscaLinearNome (struct Cliente *V, int N, char *elem){
    int i;
    for (i = 0; i < N; i++){
        if (strcmp(elem, V[i].nome)==0){
            return i; //elemento encontrado
        }
        return -1; //elemento nao encontrado
    }
}
*/
// função que faz a pesquisa na lista de strings e retorna o endereço
int pesquisar(int tamanho, int limite, char lista[tamanho][limite], char item[limite]){
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

// função que imprime o resultado da pesquisa na lista de strings
void imprimirResultadoDaBusca(resultado){
    if (resultado >= 0)
    {
        printf("Item encontrado no endereco:%d\n\n", resultado + 1);
    }
    else
    {
        printf("Item nao encontrado. Reveja o item pesquisado ou cadastre o cliente.\n");
    }
}

/*

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
int opcao, opcao_busca, tamanho = 5, limite = 100, endereco;
struct Cliente cad[100];
char item[tamanho][limite];
char itemPesquisa[limite];

printf ("-----------------------------------------\n");
printf ("CONSULTÓRIO FARMACÊUTICO DR. PAULO LIMA\n");
printf ("-----------------------------------------\n");
printf ("	Sua saúde é nossa prioridade\n\n");

while (opcao != 8){
    //system("cls");
    printf ("1. Cadastrar Cliente\n2. Listar Clientes\n3. Salvar dados \n4. Pesquisar Cliente por Nome \n5. Pesquisar Cliente por CPF\n7. Agendar Consulta\n8. Sair\n");
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
         /*   printf("Por qual informação você quer buscar o paciente?\n1.Nome \t\t2.CPF \n");
            scanf("%d", opcao_busca);

            switch (opcao_busca){
                case 1:*/
            // pedindo um item para pesquisa na lista
            printf("Qual o cliente que você procura?\n");
            fflush(stdin); scanf("%[^\n]s", &itemPesquisa);
            // realizando a pesquisa do item
            endereco = pesquisar(tamanho, limite, cad[i].nome, itemPesquisa);
            // imprimindo o resultado da busca
            imprimirResultadoDaBusca(endereco);
            break;
            
        case 5:
            // pedindo um item para pesquisa na lista
            printf("Digite o CPF do paciente que você deseja procurar na lista:\n");
            fflush(stdin); scanf("%[^\n]s", &itemPesquisa);
            // realizando a pesquisa do item
            endereco = pesquisar(tamanho, limite, cad[i].CPF, itemPesquisa);
            // imprimindo o resultado da busca
            imprimirResultadoDaBusca(endereco);
            break;
            }
        
            
        //fflush(stdin);
      /*
        case 4:
            Ordenador();
            break;
        case 5:
            agendar(); //falta essa função
            break;
        case 6:
            consulta(); //falta essa função
            break;*/

        //};
    
}
printf("SAINDO DO SISTEMA!\nVá na paz!");

return 0;

}
