
#include <stdio.h>

int fatorial(int info)
{
    
    if (info==0){
        return 1;
    }else
    {
        while(info>0)
        {
        return info*fatorial(info - 1);
        }
    }
    
}

int main()
{
    int valor;
    
    printf("FATORIAL: Escolha o valor\n");
    scanf("%d", & valor);
    printf("Fatorial de %d é %d.",valor, fatorial(valor));
    return 0;
}
