#include <stdio.h>
#include <stdlib.h>

struct Vetor
{
    int chave;
    float real;
};
typedef struct Vetor estrutura_vetor;

void combsort (estrutura_vetor *vetor, int tamanho)
{
    int i,j;
    int intervalo, trocado = 1;
    estrutura_vetor aux;

    intervalo = tamanho;

    while (intervalo > 1 || trocado == 1)
    {
        intervalo = intervalo * 10 / 13;

        if(intervalo == 9 || intervalo == 10)
            intervalo = 11;

        if (intervalo < 1)
            intervalo = 1;

        trocado = 0;

        for (i = 0, j = intervalo; j < tamanho; i++, j++)
		{
			if (vetor[i].chave < vetor[j].chave)
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
				trocado = 1;
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

   combsort(v,7);

    for (int i=0;i<7;i++)
    {
        printf (" Chave: %d \n",v[i].chave);
        printf (" Real: %0.2f \n\n",v[i].real);
    }



    return 0;
}
