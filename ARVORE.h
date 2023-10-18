#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

// STRUCTS DE ÁRVORE

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


// FUNÇÕES PRINCIPAIS


// CRIANDO UMA ÁRVORE
Arv* CriaArvore(Arv *arvore)
{
    arvore = (Arv*)malloc(sizeof(Arv));
    arvore->raiz = NULL;

    return arvore;
}

// VERIFICANDO SE ESTÁ VAZIA
int Arvore_Vazia(Arv *arvore)
{
    if(arvore->raiz == NULL)
    {
        // A arvore está vazia
        return 1;
    }
    else
    {
        // A arvore nao está vazia
        return 0;
    }
}

// INSERINDO NA ÁRVORE
NoArv* aux_insere(NoArv *no,int num)
{
    int flag;
    NoArv *pai;
    NoArv *novo;

    novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = num;
    novo->dir = NULL;
    novo->esq = NULL;

    if(no == NULL) // Significa que o no é o primeiro elemento da árvore, ou seja, a raiz
    {
        return novo;
    }
    else
    {
        pai = no; // o no recebido é a raiz, usamos como referencia (pai)
        flag = 0;

        while(flag == 0)
        {
            if(pai->info < num) // o numero é maior que o pai?
            {
               if(pai->dir == NULL) // a direita do pai está vazia?
               {
                   pai->dir = novo; // então pai aponta pra novo pela direita
                   flag = 1;
               }
               else // a direita do pai tem gente !!
               {
                   pai = pai->dir; // então o novo pai vira o elemento da direita
               }
            }
            else // o numero nao é maior que o pai !!
            {
                if(pai->info > num) // apenas garantindo que o valor não é igual ao pai
                {
                    if(pai->esq == NULL) // minha esquerda está vazia?
                    {
                        pai->esq = novo;
                        flag = 1;
                    }
                    else // minha esquerda tem gente !!
                    {
                        pai = pai->esq; // Então o pai vira o elemento da esquerda
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

// FUNÇÕES PARA IMPRESSÃO

void PreOrder(NoArv *pai)
{
    printf ("%d -> ",pai->info);

    if(pai->dir != NULL)
    {
        PreOrder(pai->dir);
    }

    if(pai->esq != NULL)
    {
        PreOrder(pai->esq);
    }
}

void PosOrder(NoArv *pai)
{
    if(pai->dir != NULL)
    {
        PosOrder(pai->dir);
    }

    if(pai->esq != NULL)
    {
        PosOrder(pai->esq);
    }

    printf("%d -> ",pai->info);
}

void InOrder(NoArv *pai)
{
    if(pai->dir != NULL)
    {
        InOrder(pai->dir);
    }

    printf("%d -> ",pai->info);

    if(pai->esq != NULL)
    {
        InOrder(pai->esq);
    }
}

// FUNÇÃO PARA LIBERAR A ÁRVORE

void LiberaArvore(NoArv *pai)
{
    if(pai->dir != NULL)
    {
        LiberaArvore(pai->dir);
    }

    if(pai->esq != NULL)
    {
        LiberaArvore(pai->esq);
    }

    free(pai);
}



#endif // Biblioteca_H_INCLUDED
