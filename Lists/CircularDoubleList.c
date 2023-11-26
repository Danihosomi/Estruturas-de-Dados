#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int alt;
    struct No *lnext, *rnext;
} no;

void push(no *circ,int num){
    no *nova_pessoa=malloc(sizeof(no)), *inter=circ;
    nova_pessoa->alt=num;
    nova_pessoa->rnext=circ;
    circ->lnext=nova_pessoa;

    while(inter->rnext!=circ) // acho o ultimo da lista
        inter=inter->rnext;

    inter->rnext=nova_pessoa;
    nova_pessoa->lnext=inter;
}

void print(no* time){ //printo a lista ligada
    no *temp=time;
    printf("%i ", time->alt);
    time=time->rnext;
    while(time!=temp){
        printf("%i ", time->alt);
        time=time->rnext;
    }
    printf("\n");
}

void deleta(no* time){ // encerro a lista ligada
    no *temp=time, *prox;
    temp=temp->rnext;
    while(time!=temp){
        prox=temp->rnext;
        free(temp);
        temp=prox;
    }
    free(time);
}
