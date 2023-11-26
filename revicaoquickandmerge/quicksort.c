#include <stdio.h>
#include <stdlib.h>
#define TAM 9
/* O algoritmo é baseado no paradigma "dividir para conquistar" e segue as seguintes etapas:
Escolha do Pivô:
    O algoritmo escolhe um elemento do array como pivô. A escolha do pivô é crucial para o desempenho do Quicksort.
    Idealmente, o pivô é escolhido de forma que divida o array em duas partes aproximadamente iguais.
Particionamento:
        Os elementos do array são rearranjados de forma que todos os elementos menores que o pivô fiquem à esquerda, e todos os elementos maiores fiquem à direita.
        O pivô ocupa a posição final correta no array após essa etapa.
Recursão:
        O Quicksort é então aplicado recursivamente às duas partições resultantes (à esquerda e à direita do pivô).
        O processo é repetido até que cada subconjunto contenha apenas um elemento, o que, por definição, é ordenado.
Combinação: Não é necessário um passo de combinação específico, pois a ordenação é realizada durante o processo de particionamento e recursão.
A eficiência do Quicksort reside em sua capacidade de ordenar subconjuntos grandes de dados de forma bastante rápida. No entanto, a escolha do pivô pode afetar significativamente o desempenho. Se o pivô for escolhido de forma que uma das partições seja significativamente maior do que a outra, o desempenho pode degradar para O(n^2) em vez do desempenho médio esperado de O(n log n). Para mitigar isso, estratégias como a escolha aleatória do pivô ou a escolha do pivô do meio são frequentemente empregadas.
A complexidade de tempo médio do Quicksort é O(n log n), o que o torna eficiente para grandes conjuntos de dados. No entanto, a complexidade de tempo pior caso é O(n^2), mas isso é raro na prática quando as estratégias de escolha de pivô mencionadas são implementadas. O Quicksort também tem a vantagem de ordenar in-place, o que significa que não requer espaço adicional para armazenar dados temporários.*/
void quicksort(int v[], int inicio, int fim);
void troca(int v[], int i, int j);
int particao(int v[],int inicio, int fim);
int particao_aleatoria(int v[], int inicio, int fim);
int main(){
    int vet[]={76,11,34,2,9,608,1,4,3};
    printf("vetor de entrada:\n");
    int i,j;
    for(i=0;i<TAM;i++)
        printf("%d ",vet[i]);   
    quicksort(vet,0,TAM-1);
    printf("\n Vetor ordenado:\n");
    for(i=0;i<TAM;i++)
        printf("%d ",vet[i]);
    return 0;
}
void quicksort(int v[], int inicio, int fim){
    if (inicio<fim){
        int indice=particao_aleatoria(v,inicio,fim);
        quicksort(v,inicio, indice-1);
        quicksort(v,indice+1,fim);
    }
}/*A função quicksort é a função principal que implementa o algoritmo QuickSort.
 Ela recebe um array v, um índice de início e um índice de fim.
 Se o índice de início for menor que o índice de fim, o algoritmo é aplicado recursivamente às partições menores.*/
int particao(int v[],int inicio,int fim){
    int pivot, indice;
    pivot = v[inicio];
    indice=fim;
    for(int i = fim; i>inicio;i--){
        if(v[i]>=pivot){
            troca(v,i,indice);
            indice--;
        }
    }
        troca(v,inicio,indice);
        return indice;
}/*A função particao recebe um array v e os índices de início e fim. 
Ela escolhe um pivô (o primeiro elemento do array neste caso) 
e rearranja os elementos do array de modo que os elementos menores que o pivô fiquem à esquerda, e os elementos maiores fiquem à direita. 
Retorna o índice final do pivô após o rearranjo.*/
void troca(int v[], int i, int j){
    int aux=v[i];
    v[i]=v[j];
    v[j]=aux;
}/*A função troca recebe um array v e dois índices i e j, trocando os elementos nos índices i e j.*/
int particao_aleatoria(int v[],int inicio, int fim){
    int indice = (rand()%(fim-inicio+1))+inicio;
    troca(v,indice, inicio);
    return particao(v,inicio,fim);
}/*
A função particao_aleatoria seleciona aleatoriamente um pivô dentro da faixa de índices 
fornecida e troca esse elemento com o elemento no índice de início. 
Em seguida, chama a função particao para continuar com o processo de particionamento.*/