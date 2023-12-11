#include <stdio.h>
#include <stdlib.h>

struct Vetor
{
    int chave;
    float real;
};
typedef struct Vetor estrutura_vetor;

void merge(estrutura_vetor* vetor, int ini, int meio,int fim,int tamanho)
{
    int i = 0;
    int j = 0;
    int k = 0;
    estrutura_vetor *aux;

    aux = (estrutura_vetor*)malloc(tamanho*sizeof(estrutura_vetor));

    i = ini;
    j = meio+1;
    k = ini;

    while(i<=meio && j<=fim)
    {
        if(vetor[i].chave > vetor[j].chave)
        {
            aux[k]=vetor[i];
            i++;
        }
        else
        {
            aux[k] = vetor [j];
            j++;
        }
        k++;
    }

    while(i<=meio)
    {
        aux[k] = vetor[i];
        i++;
        k++;
    }

    while(j<=fim)
    {
        aux[k]=vetor[j];
        j++;
        k++;
    }

    for(i=ini; i<=fim;i++)
    {
        vetor[i]=aux[i];
    }

    free(aux);
}

void merge_sort(estrutura_vetor* vetor, int ini, int fim, int tamanho)
{
    int meio;

    if(ini < fim)
    {
        meio = (ini+fim)/2 ;
        merge_sort(vetor,ini,meio,tamanho);
        merge_sort(vetor,meio+1,fim,tamanho);
        merge(vetor,ini,meio,fim,tamanho);
    }
}

int main ()
{
    estrutura_vetor v[7];
    v[0].chave = 45;
    v[1].chave = 80;
    v[2].chave = 2;
    v[3].chave = 29;
    v[4].chave = 47;
    v[5].chave = 73;
    v[6].chave = 11;

    v[0].real = 0.1;
    v[1].real = 0.2;
    v[2].real = 0.3;
    v[3].real = 0.4;
    v[4].real = 0.5;
    v[5].real = 0.6;
    v[6].real = 0.7;

   merge_sort(v,0,6,7);

    for (int i=0;i<7;i++)
    {
        printf (" Chave: %d \n",v[i].chave);
        printf (" Real: %0.2f \n\n",v[i].real);
    }



    return 0;
}
