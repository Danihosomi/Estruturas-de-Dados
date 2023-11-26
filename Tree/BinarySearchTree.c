#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Struct que representa nossa left leaning red-black tree
strings: domi_name e dns_name - > representam arvores que guardam dominios e dns
strings: ip_name -> representa arvores que guardam os ips de consulta
qtd-> quantidade de consulta
*/
typedef struct No{
    char domi_name[105], dns_name[105], ip_name[105];
    int color, qtd;
    struct No *lnext, *rnext;
} no;

//verifica se um nó é vermelho
int is_r(no* tree){
    if(tree==NULL)
        return 0;
    return tree->color==1;
}

//verifica se um nó é preto
int is_b(no* tree){
    if(tree==NULL)
        return 1;
    return tree->color==0;
}

//faz uma rotação esquerda
no* left_rot(no* tree){
    no* x = tree->rnext;
    tree->rnext=x->lnext;
    x->lnext=tree;
    x->color=tree->color;
    tree->color=1;
    return x;
}

//faz uma rotação direita
no* right_rot(no* tree){
    no* x = tree->lnext;
    tree->lnext=x->rnext;
    x->rnext=tree;
    x->color=tree->color;
    tree->color=1;
    return x;
}

//joga a cor vermelha para o nó de cima
void up_color(no* tree){
    tree->color=1;
    tree->lnext->color=0;
    tree->rnext->color=0;
}

/*
Função que adciona um nó a arvore
ok: 1-> trata da arvore de DNS, 0-> trata da arvore de IP's
*/
no* push(no* tree,char domi[],char dns[],char ip[],int ok){
    no* new_no;
    if(tree==NULL){
        new_no=malloc(sizeof(no));
        new_no->lnext=new_no->rnext=NULL;
        strcpy(new_no->dns_name,dns);
        strcpy(new_no->ip_name,ip);
        strcpy(new_no->domi_name,domi);
        new_no->qtd=1;
        new_no->color=1;
        return new_no;
    }

    if(ok){
        if(strcmp(tree->domi_name,domi)>0)
            tree->lnext=push(tree->lnext,domi,dns,ip,ok);
        else
            tree->rnext=push(tree->rnext,domi,dns,ip,ok);
    }
    else{
        if(strcmp(tree->ip_name,ip)>0)
            tree->lnext=push(tree->lnext,domi,dns,ip,ok);
        else
            tree->rnext=push(tree->rnext,domi,dns,ip,ok);
    }
    if(is_r(tree->rnext) && is_b(tree->lnext))
        tree=left_rot(tree);
    if(is_r(tree->lnext) && is_r(tree->lnext->lnext))
        tree=right_rot(tree);
    if(is_r(tree->lnext) && is_r(tree->rnext))
        up_color(tree);

    return tree;
}

/*
Função que busca se um nó existe na arvore e, se existir, retorna esse nó
ok: 1->se falamos da árvore de DNS, 0-> se falamos da árvore de IP
*/
no* find(no* tree,char ip[],int ok){
    if((tree==NULL) || (ok && !strcmp(tree->domi_name,ip)) || (!ok && !strcmp(tree->ip_name,ip)))
        return tree;
    
    no* ans=NULL;
    if(ok){
        if(strcmp(tree->domi_name,ip)>0)
            ans=find(tree->lnext,ip,ok);
        else
            ans=find(tree->rnext,ip,ok);
    }
    else{
        if(strcmp(tree->ip_name,ip)>0)
            ans=find(tree->lnext,ip,ok);
        else
            ans=find(tree->rnext,ip,ok);
    }

    return ans;
}

//da free nas árvores 
void deleta(no* tree){
    if(tree==NULL)
        return ;
    deleta(tree->lnext);
    deleta(tree->rnext);
    free(tree);
}
