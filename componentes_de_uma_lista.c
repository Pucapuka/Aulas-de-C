#include <stdio.h>
int main()
{
    char nome [50][50];
    int  i, len;
    
    printf ("Quantas pessoas compõem a lista: ");
    scanf("%d", &len);
    
    for (i=0; i<len; i++){
        printf("Digite o %do nome: ", (i+1));
        scanf ("%s", nome[i]);
    }
    
    for (i=0; i<len; i++){
    printf("%s, ", nome[i]);
}
    return 0;
}
