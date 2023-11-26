#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Complexidade: O(nlogn)

typedef struct Cidade{ // Estruct que representa uma cidade, tem nome, população e id
    char name[55];
    double popu;
    int id;
} cidade;

void heapify(cidade *vetor,int size,int i){ // Função que Ordena o Vetor que guarda as palavras mais frequentes. É um Heap-Sort
    int menor=i, l=2*i+1, r=2*i+2;

    if(l<size && (vetor[l].popu>vetor[menor].popu || (vetor[l].popu==vetor[menor].popu && strcmp(vetor[l].name,vetor[menor].name)>0)))
        menor=l;
    if(r<size && (vetor[r].popu>vetor[menor].popu || (vetor[r].popu==vetor[menor].popu && strcmp(vetor[r].name,vetor[menor].name)>0)))
        menor=r;
    if(menor!=i){
        cidade inter;
        inter=vetor[i];
        vetor[i]=vetor[menor];
        vetor[menor]=inter;
        
        heapify(vetor,size,menor);
    }
}

void sort(cidade *resposta,int n){ // Faço um Heap-Sort
    for(int i=n/2-1;i>=0;i--)
        heapify(resposta,n,i);

    for(int i=n-1;i>0;i--){
        cidade inter;
        inter=resposta[i];
        resposta[i]=resposta[0];
        resposta[0]=inter;
        heapify(resposta,i,0);
    }
}
