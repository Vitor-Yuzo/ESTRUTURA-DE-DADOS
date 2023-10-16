#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

// STRUCTS DE �RVORE

struct NoArvore
{
    int info;
    struct NoArvore *esq;
    struct NoArvore *dir;
};
typedef struct NoArvore NoArv;

struct Arvore
{
    NoArv *raiz;
};
typedef struct Arvore Arv;


// FUN��ES PRINCIPAIS


// CRIANDO UMA �RVORE
Arv* CriaArvore(Arv *arvore)
{
    arvore = (Arv*)malloc(sizeof(Arv));
    arvore->raiz = NULL;

    return arvore;
}

// VERIFICANDO SE EST� VAZIA
int Arvore_Vazia(Arv *arvore)
{
    if(arvore->raiz == NULL)
    {
        // A arvore est� vazia
        return 1;
    }
    else
    {
        // A arvore nao est� vazia
        return 0;
    }
}

// INSERINDO NA �RVORE
NoArv* aux_insere(NoArv *no,int num)
{
    int flag;
    NoArv *pai;
    NoArv *novo;

    novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = num;
    novo->dir = NULL;
    novo->esq = NULL;

    if(no == NULL) // Significa que o no � o primeiro elemento da �rvore, ou seja, a raiz
    {
        return novo;
    }
    else
    {
        pai = no; // o no recebido � a raiz, usamos como referencia (pai)
        flag = 0;

        while(flag == 0)
        {
            if(pai->info < num) // o numero � maior que o pai?
            {
               if(pai->dir == NULL) // a direita do pai est� vazia?
               {
                   pai->dir = novo; // ent�o pai aponta pra novo pela direita
                   flag = 1;
               }
               else // a direita do pai tem gente !!
               {
                   pai = pai->dir; // ent�o o novo pai vira o elemento da direita
               }
            }
            else // o numero nao � maior que o pai !!
            {
                if(pai->info > num) // apenas garantindo que o valor n�o � igual ao pai
                {
                    if(pai->esq == NULL) // minha esquerda est� vazia?
                    {
                        pai->esq = novo;
                        flag = 1;
                    }
                    else // minha esquerda tem gente !!
                    {
                        pai = pai->esq; // Ent�o o pai vira o elemento da esquerda
                    }
                }
            }
        }
    }

    return no;
}

void insere(Arv *arvore,int num)
{
    arvore->raiz = aux_insere(arvore->raiz,num);
}






















#endif // Biblioteca_H_INCLUDED
