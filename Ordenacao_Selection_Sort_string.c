#include <stdio.h>
#include <string.h>
 
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
 
int main(){
   
    nameColection();
   
    emOrdem();
 
    showNames();
   
 
    return 0;
}
