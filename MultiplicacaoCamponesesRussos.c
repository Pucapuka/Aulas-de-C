#include <stdio.h>
#include <stdlib.h>

// Função que divide por 2
int divide(int valor) {
    return valor / 2;
}

// Função que multiplica por 2
int multiplica(int valor) {
    return valor * 2;
}

// Função que realiza a multiplicação dos camponeses russos
int camponesRusso(int multiplicando, int multiplicador) {
    int soma = 0;

    // Laço de repetição que continua enquanto o multiplicando for maior que 0
    while (multiplicando > 0) {
        // Se o multiplicando for ímpar, adiciona o multiplicador à soma
        if (multiplicando % 2 != 0) {
            soma += multiplicador;
        }
        // Divide o multiplicando por 2
        multiplicando = divide(multiplicando);
        // Multiplica o multiplicador por 2
        multiplicador = multiplica(multiplicador);
    }

    return soma;
}

int main(int argc, char *argv[]) {
    // Chama a função camponesRusso com os valores 36 e 15
    int multiplicacaoCamponesRusso = camponesRusso(14, 25);
    int multiplicacaoConvencional = 14 * 25;

    printf("\n===========================================================");
    printf("\nResuldado de uma multiplicação convencional: %d", multiplicacaoCamponesRusso);
    printf("\n===========================================================\n");    
    // Imprime o resultado da multiplicação dos camponeses russos
    printf("\n============================================================");
    printf("\nResultado da multiplicação dos camponeses russos: %d", multiplicacaoCamponesRusso);
    printf("\n============================================================\n");

    return 0;
}
