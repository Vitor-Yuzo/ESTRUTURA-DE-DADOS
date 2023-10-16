#include <stdio.h>
#include <stdlib.h>
#include "ARVORE.h"

int main()
{
    int i,num;
    Arv *arvore1 = NULL;

    arvore1 = CriaArvore(arvore1);

    if(Arvore_Vazia(arvore1))
    {
        printf ("\n\n A ARVORE ESTA VAZIA\n\n");
    }

    printf ("Digite um numero para inserir na arvore: ");
    scanf  ("%d",&num);

    insere(arvore1,num);

    if(Arvore_Vazia(arvore1))
    {
        printf ("\n\n A ARVORE ESTA VAZIA\n\n");
    }

    return 0;
}
