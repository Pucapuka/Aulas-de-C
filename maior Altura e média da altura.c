#include <stdio.h>

int homens[]={168, 192, 170, 153, 152, 145};

int mulheres[]={140, 150, 170, 152, 143, 148};

//procedimento para ordenar e selecionar a maior altura

void maior(){
    int i, j, aux, maiorH, maiorM;
    for (i = 0; i < 5; i++){
        for (j = i + 1; j < 6; j++){
            if (homens[j]<homens[i]){
                aux = homens[i];
                homens[i] = homens[j];
                homens[j] = aux;
            }
            maiorH = homens[j];
        
            if (mulheres[j]<mulheres[i]){
                aux = mulheres[i];
                mulheres[i] = mulheres[j];
                mulheres[j] = aux;
            }
            maiorM = mulheres[j];
        }
    }
    printf("A maior altura dos homens é %dcm\n", maiorH);
    printf("A maior altura das mulheres é %dcm\n", maiorM);
}

//procedimento para calcular a média

void media(){
    int i; 
    float mHomens, mMulheres;
    mHomens = homens[i];
    mMulheres = mulheres[i];
    for (i = 0 ; i < 6; i++){
        mHomens+=homens[i];
        mMulheres+=mulheres[i];
    }
    printf("A média da altura dos homens é %.2fcm.\n", mHomens/6);
    printf("A média da altura das mulheres é %.2fcm.", mMulheres/6);
}

//função principal

int main()
{
//chamando os procedimentos
    maior();
    media();
}
