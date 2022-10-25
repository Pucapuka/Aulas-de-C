#include <stdio.h>
#include <stdlib.h>

//Criando estrutura para os dados do paciente
struct typedef{
char registro[5];
char nome[50];
char CPF[11];
int dia, mes, ano;
char endereco[200];
char telefone[10];
}Cliente; //tentando criar um vetor para um número de clientes (alterar para a forma correta posteriormente)

//procedimento para coletar esses os dados do paciente
void Cadastrador(Cliente)/*alterar para a forma correta posteriormente*/{
	printf("Cadastro do Paciente:\n");
	printf("-------------------------");
	printf("Número de Registro: "); scanf("%s", registro);
	printf("Nome: "); scanf("%s", nome);
	printf("CPF: "); scanf("%s", CPF);
	printf("Data de Nascimento:"); scanf("%d/%d/%d", &dia,&mes,&ano);
	printf("Endereço: "); scanf("%s", endereco);
	printf("Telefone(XX)9XXXXXXXX: "); scanf("%s", telefone);
}

int main(){
	
int Cliente[], i;

printf ("-----------------------------------------");
printf ("CONSULTÓRIO FARMACÊUTICO DR. PAULO LIMA");
printf ("-----------------------------------------");
printf ("		Sua saúde é nossa prioridade\n");

	for (i = 0; i<100, i++){
		
		Cadastrar(Cliente[])
		
	}
	
	return 0;
}
