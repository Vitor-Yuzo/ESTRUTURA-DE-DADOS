#include <stdio.h>
#include <stdlib.h>
#include "ARVORE.h"


int nos_internos(NoArv *pai,int quantidade)
{
    quantidade += 1;

    if(pai->dir != NULL)
    {
        quantidade = nos_internos(pai->dir,quantidade);
    }

    if(pai->esq != NULL)
    {
        quantidade = nos_internos(pai->esq,quantidade);
    }

    if(pai->esq == NULL && pai->dir == NULL)
    {
        return quantidade -= 1;
    }
    else
    {
        return quantidade;
    }
}










int main()
{
    int i,num;
    Arv *arvore1 = NULL;
    int flag;
    int quantidade;

    arvore1 = CriaArvore(arvore1);

    if(Arvore_Vazia(arvore1))
    {
        printf ("\n\nCHECK 1: A ARVORE ESTA VAZIA\n\n");
    }

    //printf ("Digite um numero para inserir na arvore: ");
    //scanf  ("%d",&num);

    //insere(arvore1,num);
    insere(arvore1,50);
    insere(arvore1,40);
    insere(arvore1,45);
    insere(arvore1,30);
    insere(arvore1,60);
    insere(arvore1,55);
    insere(arvore1,70);
    insere(arvore1,80);
    insere(arvore1,90);
    insere(arvore1,100);

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

    // BUSCAR

    printf ("\n\n");

    flag = 0;
    flag = busca(arvore1->raiz,71);

    if(flag == 0)
    {
        printf ("O valor existe na arvore");
    }
    else
    {
        if(flag == 1)
        {
            printf ("O valor nao existe na arvore");
        }
        else
        {
            printf ("erro na busca !!");
        }
    }

    // QUANTIDADE DE NOS INTERNOS

    quantidade = -1;
    quantidade = nos_internos(arvore1->raiz,quantidade);

    printf ("\n\n%d ",quantidade);

    LiberaArvore(arvore1->raiz);

    free(arvore1);
    arvore1 = NULL;

    return 0;
}
