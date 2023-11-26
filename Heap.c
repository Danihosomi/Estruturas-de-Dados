#include <stdio.h>
#include <stdlib.h>
#define pai(x) ((x-1)>>1)
#define L(x) ((x<<1)+1) // filho esquerdo
#define R(x) ((x<<1)+2) // filho direito

typedef struct Item{ //struct que armazena um pacote
    int id, prio, inc;
} item;

typedef struct Pq{ // struct que representa minha priority_queue (MAX HEAP)
    item *v;
    int size, max_size;
} PQ;

void swap(item* a,item *b){ // estrutura responsável por dar swap nos itens
    item temp = (*b);
    (*b)=(*a);
    (*a)=temp;
}

void up_heap(PQ* pq,int k){ // subo o heap arrumando ele
    if(k>0 && pq->v[pai(k)].prio<pq->v[k].prio){
        swap(&pq->v[k],&pq->v[pai(k)]);
        up_heap(pq,pai(k));
    }
}

void down_heap(PQ* pq,int k){ // desço o heap arrumando ele
    int max;
    if(L(k)<pq->size){
        max=L(k);
        if(R(k)<pq->size && pq->v[L(k)].prio<pq->v[R(k)].prio)
            max=R(k);
        if(pq->v[k].prio<pq->v[max].prio){
            swap(&pq->v[k],&pq->v[max]);
            down_heap(pq,max);
        }
    }
}

item pop(PQ* pq){ // tiro um elemento do heap, tamanho do heap diminui e eu retorno o item retirado
    item top=pq->v[0];
    swap(&pq->v[0],&pq->v[pq->size-1]);
    pq->size--;
    down_heap(pq,0);
    return top;
}

void push(PQ* pq,item novo){ // coloco um novo elemento no heap, tamanho do heap aumenta e não possui retorno
    pq->v[pq->size]=novo;
    pq->size++;
    up_heap(pq,pq->size-1);
}

void update(PQ* pq,int k){ // dou update em um elemento específico do heap, tamanho fica inalterado
    pq->v[k].prio+=pq->v[k].inc;
    up_heap(pq,k);
}
