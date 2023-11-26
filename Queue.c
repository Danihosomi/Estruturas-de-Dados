#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Structs utilizadas:
no -> serve para fazer a lista ligada para implementarmos a fila(queue)
queue - > estrutura que representa a fila com nós de inicio e fim
*/
typedef struct No{ 
    char nome[30], opera[30], type[30];
    int qtd;
    struct No *prox;
} no;

typedef struct Queue{
    int sz; // tamanho
    no *ini, *fim;
} queue;

/*
Funções de Push:
push_back : é o push de uma fila, o elemento vai para ultimo lugar de uma fila 
*/
void push_back(queue *fila,char na[],char op[],char ty[],int qt){
    no *novo_no = malloc(sizeof(no));
    novo_no->qtd=qt;
    strcpy(novo_no->nome,na);
    strcpy(novo_no->opera,op);
    strcpy(novo_no->type,ty);
    novo_no->prox=NULL;
    if(fila->ini==NULL){ // se a fila ta vazia iniciamos ela
        fila->ini=novo_no;
        fila->fim=novo_no;
        fila->sz=1;
        return ;
    }
    fila->fim->prox=novo_no;
    fila->fim=novo_no; //colocamos o elemento no fim
    fila->sz++;
}

/*
Funções de pop:
pop_queue : é o pop de uma fila, o elemento removido é o primeiro da fila que é o mais antigo 
*/

void pop_queue(queue *fila){
    no *first=fila->ini;
    fila->ini=first->prox;
    fila->sz--;
    free(first);
}

