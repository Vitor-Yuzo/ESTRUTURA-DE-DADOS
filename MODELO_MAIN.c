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
        printf ("\n\nCHECK 1: A ARVORE ESTA VAZIA\n\n");
    }

    printf ("Digite um numero para inserir na arvore: ");
    scanf  ("%d",&num);

    insere(arvore1,num);
    insere(arvore1,5);
    insere(arvore1,6);
    insere(arvore1,7);
    insere(arvore1,8);
    insere(arvore1,9);

    if(Arvore_Vazia(arvore1))
    {
        printf ("\n\n A ARVORE ESTA VAZIA\n\n");
    }
    else
    {
        printf ("\n\n -----PRE ORDER------ \n\n");
        PreOrder(arvore1->raiz);

        printf ("\n\n -----POS ORDER----- \n\n");
        PosOrder(arvore1->raiz);

        printf ("\n\n -----IN ORDER-----\n\n");
        InOrder(arvore1->raiz);
    }

    LiberaArvore(arvore1->raiz);

    free(arvore1);
    arvore1 = NULL;

    return 0;
}
