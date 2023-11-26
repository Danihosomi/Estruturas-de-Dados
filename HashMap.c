#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

typedef struct Dado{ // Estrutura que guarda dados que vamos printar.
    char name[55];
    int qt;
} dado;

typedef struct No{ // Estrutura que guarda nó que vamos utilizar na lista do Hash-Map.
    char pala[55];
    int qtd;
    struct No* next;
} no;

typedef struct Hash{ // Estrutura que representa o Hash.
    no **V;
} hash;

hash criar_map(int n){ // Criamos o Hash-Map.
    hash mapa;
    mapa.V=malloc((n+2)*sizeof(no*));
    for(int i=0;i<n;i++)
        mapa.V[i]=NULL;
    return mapa;
}

no* push(no *lista,char pal[]){ // Dou um push em um nó de uma das listas da Hash-Map.
    no *new_node=malloc(sizeof(no));
    new_node->qtd=1;
    strcpy(new_node->pala,pal);
    new_node->next=lista;
    lista=new_node;

    return lista;
}

int search(no *lista,char pal[]){ // Procuro se um Nó específico esta na lista de uma das Hash-Map. Retorna 1 se encontrou 0 se não.
    no *inter=lista;
    while(inter!=NULL){
        if(!strcmp(inter->pala,pal))
            return 1;
        inter=inter->next;
    }
    return 0;
}

int get_hash(char pal[],int n){ // Função que calcula a função hash de uma string. Retorna o valor hash.
    int ans=0;
    for(int i=0;i<strlen(pal);i++)
        ans=(256*ans+(int)(pal[i]))%n;
    return ans;
}

void inserir(hash t,char pal[],int n){ // Função que insere uma palavra no Hash-Map.
    int h_val=get_hash(pal,n);
    t.V[h_val]=push(t.V[h_val],pal);
}

int find(hash t,char pal[],int n){ // Função que procura se existe uma palavra no Hash-Map. Retorna 1 se existe 0 se não.
    int h_val=get_hash(pal,n);
    return search(t.V[h_val],pal);
}

void update(hash t,char pal[],int n){ // Função que aumenta a frênquencia de uma palavra de um Hash-Map.
    int h_val=get_hash(pal,n);
    no *inter=t.V[h_val];
    while(inter!=NULL){
        if(!strcmp(inter->pala,pal)){
            inter->qtd++;
            break;
        }
        inter=inter->next;
    }
}

void deleta(no *lista){ // Função que deleta as listas do Hash-Map.
    if(lista==NULL)
        return ;
    deleta(lista->next);
    free(lista);
}
