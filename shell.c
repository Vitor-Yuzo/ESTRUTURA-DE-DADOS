#include <stdio.h>
#include <stdlib.h>

struct Vetor
{
    int chave;
    float real;
};
typedef struct Vetor estrutura_vetor;


// ordenar um vetor usando o ShellSort
void shellsort(estrutura_vetor *vetor, int tamanho)
{
    int i = 0;
    int j = 0;
    int h = 0;
    estrutura_vetor aux;

    for (h = 1; h < tamanho; h = 3 * h + 1)
    {
        int tempH = h; // Armazena o valor original de h

        while (tempH > 0)
        {
            tempH = (tempH - 1) / 3;

            for (i = tempH; i < tamanho; i++)
            {
                aux = vetor[i];
                j = i;

                while ( vetor[j - tempH].chave < aux.chave)
                {
                    vetor[j] = vetor[j - tempH];
                    j -= tempH;

                    if(j<tempH) break;
                }

                vetor[j] = aux;
            }
        }
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

   shellsort(v,7);

    for (int i=0;i<7;i++)
    {
        printf (" Chave: %d \n",v[i].chave);
        printf (" Real: %0.2f \n\n",v[i].real);
    }



    return 0;
}
