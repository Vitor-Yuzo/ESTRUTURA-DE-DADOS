#include <stdio.h>
#include <stdlib.h>

struct Vetor
{
    int chave;
    float real;
};
typedef struct Vetor estrutura_vetor;

void quicksort(estrutura_vetor *vetor, int LI, int LS)
{
   int e, d;
   estrutura_vetor pivo, aux;

   e = LI;
   d = LS;
   pivo = vetor[(LI + LS) / 2];

   do
   {
      while(vetor[e].chave > pivo.chave)
        e++;

      while(vetor[d].chave < pivo.chave)
        d--;

      if(e <= d)
      {
         aux = vetor[e];
         vetor[e] = vetor[d];
         vetor[d] = aux;
         e++;
         d--;
      }
   }while(e <= d);

   if(LI < d)
      quicksort(vetor, LI, d);
   if(e < LS)
      quicksort(vetor, e, LS);
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

   quicksort(v,0,6);

    for (int i=0;i<7;i++)
    {
        printf (" Chave: %d \n",v[i].chave);
        printf (" Real: %0.2f \n\n",v[i].real);
    }



    return 0;
}
