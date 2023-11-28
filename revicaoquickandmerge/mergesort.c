#include <stdio.h>
#include <limits.h>
#define TAMANHO 8

void intercala (int inicio, int meio, int fim, int v[]);
void mergesort (int inicio, int fim, int v[]);

int main () {
  
  int vetor[TAMANHO] = {7,5,9,12,0,10,15,-12};

  for (int i = 0; i < TAMANHO; i++) {
    printf ("%2d ", vetor[i]);
  }
  printf ("\n\n");
  
  mergesort (0, TAMANHO - 1, vetor);
  
  for (int i = 0; i < TAMANHO; i++) {
    printf ("%2d ", vetor[i]);
  } 
  
  return 0;
}


void mergesort (int inicio, int fim, int v[]) {
  if (inicio < fim) {
    int meio = (inicio + fim)/2;
    mergesort (inicio, meio, v);
    mergesort (meio+1, fim, v);
    intercala (inicio, meio, fim, v);
  }
}

void intercala (int inicio, int meio, int fim, int v[]) {
  int primeirada = inicio, secundada = meio+1, poslivre=0, aux[TAMANHO];
  while (primeirada <= meio && secundada <= fim) {
    if (v[primeirada] <= v[secundada])  
      aux[poslivre++] = v[primeirada++];
    else  
      aux[poslivre++] = v[secundada++];
  }
  //se existirem núm. em v[primeirada] que não foram intercalados 
  while (primeirada <= meio)  
    aux[poslivre++] = v[primeirada++];
  //se existirem núm. em v[secundada] que não foram intercalados
  while (secundada <= fim)  
    aux[poslivre++] = v[secundada++];
  //retorna os valores do vetor aux para o vetor v   
  for (primeirada = inicio; primeirada <= fim; primeirada++)  
    v[primeirada] = aux[primeirada-inicio];
}