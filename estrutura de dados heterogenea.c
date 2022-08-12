#include <stdio.h>

int main()
{

struct{         //criando uma estrutura
    
    char nome[50];
    char data_nasc[10];
    int idade;            
    float salario;
}dados_cliente;  //declarando uma variável que representará essa estrutura.

printf("Digite o nome do cliente: ");
scanf("%s", &dados_cliente.nome);  //se referencia à estrutura declarada e busca o nome nela (<estrutura.dado>)
printf("Digite a data de nascimento o cliente: ");
scanf("%s", &dados_cliente.data_nasc);
printf("Quantos anos o paciente tem?");
scanf("%d", &dados_cliente.idade);
printf("Digite o salário do cliente: ");
scanf("%f", &dados_cliente.salario);

printf("O nome do cliente é: %s \n", dados_cliente.nome);
printf("A data de nascimento do cliente é %s\n", dados_cliente.data_nasc);
printf("A idade do cliente é %d anos.\n", dados_cliente.idade);
printf("O salário do cliente é %.2f reais. \n", dados_cliente.salario);

 
    return 0;
}
