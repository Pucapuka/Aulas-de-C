/*MANZANO, cap. 3. exercício r:
Uma eleição sindical concorrem para cargo de presidente 3 candidatos: A,B e C
Apuração de votos: computados votos nulo, em branco e votos válidos para cada candidato.
O programa deve ler (em estrutura de dados composta):
1. Quantidade de votos válidos para cada candidato;
2. Quantidade de votos nulos e brancos;
Deve apresentar:
1. Número total de eleitores;
2. Percentual de votos válidos de A em relação à quantidade de eleitores;
3. Percentual de votos válidos de B em relação à quantidade de eleitores;
4. Percentual de votos válidos de C em relação à quantidade de eleitores;
5. Percentual de votos nulos em relação à quantidade de eleitores;
6. Percentual de votos em branco em relação à quantidade de eleitores;
*/

#include <stdio.h>

int main()
{
struct candidatos{      //criando a estrutura (enumeração de votos)
    char cand_A[20];
    float A;
    char cand_B[20];
    float B;
    char cand_C[20];
    float C;
    float brancos;
    float nulos;
};//para variar, declararei o nome da variável mais a frente. 

struct percentual{ //criando outra estrutura (cálculo percentual dos votos)
    float voto_cand_A, voto_cand_B, voto_cand_C, voto_brancos, voto_nulos;
}porcento; //aqui, declarei logo o nome da variável

//Declarando as variáveis]
struct candidatos voto;  //declarando a variável (mencionei antes) que usará a estrutura
int eleitores;
float percentual;

printf("-----------Apuração de votos---------------\n");
printf("-------------------------------------------\n");
printf("1º candidato: ");
scanf("%s", voto.cand_A);
printf("quantidade de votos: ");
scanf("%f", &voto.A);
printf("2º candidato:");
scanf("%s", voto.cand_B);
printf("quantidade de votos: ");
scanf("%f", &voto.B);
printf("3º candidato:");
scanf("%s", voto.cand_C);
printf("quantidade de votos: ");
scanf("%f", &voto.C);
printf("Votos em branco: ");
scanf("%f", &voto.brancos);
printf("Votos nulos: ");
scanf("%f", &voto.nulos);

//calculo dos votos totais e percentuais de voto
eleitores = voto.A + voto.B + voto.C + voto.nulos + voto.brancos;
porcento.voto_cand_A = (voto.A / eleitores) * 100;
porcento.voto_cand_B = (voto.B / eleitores) * 100;
porcento.voto_cand_C = (voto.C / eleitores) * 100;
porcento.voto_nulos = (voto.nulos / eleitores) * 100;
porcento.voto_brancos = (voto.brancos / eleitores) * 100;


printf("------------Resultado final----------------\n");
printf("-------------------------------------------\n");

printf("Total de eleitores: %d \n", eleitores);
printf("Total de votos do candidato %s: %.1f \n", voto.cand_A, voto.A);
printf("Total de votos do candidato %s: %.1f \n", voto.cand_B, voto.B);
printf("Total de votos do candidato %s: %.1f \n", voto.cand_C, voto.C);
printf("Total de votos em branco: %.1f \n", voto.brancos);
printf("Total de votos nulos: %.1f \n", voto.nulos);
printf("O percentual de votos para o candidato %s: %.2f porcento. \n", voto.cand_A, porcento.voto_cand_A);
printf("O percentual de votos para o candidato %s: %.2f porcento. \n", voto.cand_B, porcento.voto_cand_B);
printf("O percentual de votos para o candidato %s: %.2f porcento. \n", voto.cand_C, porcento.voto_cand_C);
printf("O percentual de votos nulos: %2.f porcento. \n", porcento.voto_nulos);
printf("O percentual de votos em branco: %2.f porcento. \n", porcento.voto_brancos);

return 0;
}


