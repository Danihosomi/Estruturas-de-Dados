#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No{ // Estrutura que representa uma Árvore Binária
    int nivel;
    double val;
    char nome[25];
    struct No *lnext, *rnext, *last;
} no;

typedef struct Fila{ // Estrutura que representa um Fila
    no ind;
    struct Fila *next;
} queue;

void pop(queue **fila){ // Função que retira o elemento do começo da fila
    queue *temp=(*fila);
    (*fila)=temp->next;
    free(temp);
}

void push(queue *fila,no *pessoa){ // Função que coloca um elemento na fila (no final da fila)
    queue *new_node=malloc(sizeof(queue)), *temp=fila;
    new_node->ind=(*pessoa);
    new_node->next=NULL;

    while(temp->next!=NULL) // chega no final da fila
        temp=temp->next;
    
    temp->next=new_node;
}

no* find(no *tree,char name[]){ // Função que acha o nó da árvore com o nome==name
    if(tree==NULL || !strcmp(tree->nome,name))
        return tree;
    
    no *l, *r;
    l=find(tree->lnext,name);
    r=find(tree->rnext,name);

    if(l!=NULL) return l; // se for o da esquerda devolve
    return r;
}

void link(no **boss,char name[],double valor,int id){ // Função que conecta um novo nó até ao boss dele
    no *new_no = malloc(sizeof(no));
    
    strcpy(new_no->nome,name);
    new_no->val=(1.1)*valor;
    new_no->lnext=NULL;
    new_no->rnext=NULL;
    new_no->last=(*boss);
    new_no->nivel=1+(*boss)->nivel;
    (*boss)->val-=0.1*valor;

    if(id){
        (*boss)->rnext=new_no;

        (*boss)->val+=0.06*(new_no->val);
        (*boss)->val+=0.06*((*boss)->lnext->val);
        (*boss)->lnext->val*=0.94;
        new_no->val*=0.94;
        
        return ;
    }

    (*boss)->lnext=new_no;
}

void deleta_arvore(no **tree){ // função que da free nas árvores
    if((*tree)->lnext!=NULL)
        deleta_arvore(&(*tree)->lnext);
    if((*tree)->rnext!=NULL)
        deleta_arvore(&(*tree)->rnext);

    free((*tree));
}
