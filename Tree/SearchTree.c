#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct No{ // Função que representa minha minha arvore binaria de busca
    double val; int id;
    char nome[30];
    struct No *lnext, *rnext;
} no;

no* add(no *tree,char name[],int ids,double valor){ // adciono um no na minha arvore binaria de busca
    no *inter=tree;
    if(inter==NULL){
        inter=malloc(sizeof(no));
        inter->id=ids;
        inter->val=valor;
        inter->lnext=NULL;
        inter->rnext=NULL;
        strcpy(inter->nome,name);
    }
    else if(inter->val>=valor) // se for maior q o atual
       inter->lnext=add((inter->lnext),name,ids,valor);
    else // se for menor q o atual 
        inter->rnext=add((inter->rnext),name,ids,valor);

    return inter;
}

void find(no *tree,int ids,double valor,no **lista){ // procuro os nos que vendem o produto em uma determinada quantia
    if(tree==NULL)
        return ;
    
    find(tree->lnext,ids,valor,lista); // sempre vou pra esquerda que tem preços menores
    if(tree->val<=valor+0.1*valor){ // so vou pra direita se isso é valido
        find(tree->rnext,ids,valor,lista);
        if(tree->id==ids) // se achei uma cara valido eu boto na lista
            (*lista)=push(lista,tree->nome,ids,tree->val);
    }
}

void destroi_tree(no *tree){ // função que da free nas árvores
    if(tree->lnext!=NULL)
        destroi_tree(tree->lnext);
    if(tree->rnext!=NULL)
        destroi_tree(tree->rnext);

    free(tree);
}
