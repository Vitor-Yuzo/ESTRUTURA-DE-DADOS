#include <stdio.h>
#include <stdlib.h>
#include "ARVORE.h"

void somatoria(NoArv *pai, int *soma)
{
    if(pai->dir != NULL)
    {
        somatoria(pai->dir,soma);
    }

    if(pai->esq != NULL)
    {
        somatoria(pai->esq,soma);
    }

    *soma += pai->info;
}

int main()
{
    Arv *arvore1;
    int soma;

    arvore1 = CriaArvore(arvore1);

    insere(arvore1,5);
    insere(arvore1,9);
    insere(arvore1,4);
    insere(arvore1,1);
    insere(arvore1,2);
    insere(arvore1,3);
    insere(arvore1,99);

    somatoria(arvore1->raiz,&soma);

    printf("%d ",soma);

    return 0;
}
