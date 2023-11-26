#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Structs utilizadas:
stack -> estrutura que é a base de uma pilha guardando dado, tamanho da pilha e um ponteiro
*/

typedef struct Pilha{
    char item[30]; // conteudo
    int tam; //tamanho
    struct Pilha *next;
} stack;

/*
Funções de Push:
push_front: é o push de uma pilha, o elemento vem em primeiro lugar na pilha 
*/

void push_front(stack **pilha,char prod[]){
    stack *novo_no = malloc(sizeof(stack));
    strcpy(novo_no->item,prod);
    if((*pilha)==NULL){ // se a pilha ta vazia inciamos ela
        novo_no->tam=1;
        novo_no->next=NULL;
        (*pilha)=novo_no;
        return ;
    }
    novo_no->tam=(*pilha)->tam+1; 
    novo_no->next=(*pilha);
    (*pilha)=novo_no; //colocamos o elemento na frente
}

/*
Funções de pop:
pop_stack: é o pop de uma pilha, o elemento mais novo é removido, isso é, o do topo da pilha
*/

void pop_stack(stack **pilha){
    stack *first=(*pilha);
    (*pilha)=first->next;
    free(first);
}

