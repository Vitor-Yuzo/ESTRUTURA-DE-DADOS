#include <stdio.h>
#include <stdlib.h>

struct Vetor
{
    int chave;
    float real;
};
typedef struct Vetor estrutura_vetor;

// FUNÇÃO QUICK PARTE 2
int particao_inicio(estrutura_vetor *v,int LI, int LS)
{
    int e = LI;
    int d = LS;
    estrutura_vetor pivo = v[LI];
    estrutura_vetor aux;

    while (e < d)
    {
        while((v[e].chave >= pivo.chave) && (e < LS))
        {
            e++;
        }

        while((v[d].chave < pivo.chave) && (d > LI))
        {
            d--;
        }

        if(e < d)
        {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
        aux = v[LI];
        v[LI] = v[d];
        v[d] = aux;

    return d;
}

// FUNÇÃO QUICK PARTE 1
void quicksort_inicio(estrutura_vetor *v, int LI, int LS)
{
    if(LI < LS)
    {
        int p,i;

        p = particao_inicio(v,LI,LS);

        quicksort_inicio(v,LI,p-1);
        quicksort_inicio(v,p+1,LS);
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

   quicksort_inicio(v,0,6);

    for (int i=0;i<7;i++)
    {
        printf (" Chave: %d \n",v[i].chave);
        printf (" Real: %0.2f \n\n",v[i].real);
    }



    return 0;
}
