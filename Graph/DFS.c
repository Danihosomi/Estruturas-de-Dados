#include <stdio.h>
#include <stdlib.h>

typedef struct Cela{ // Estruct que representa uma cela, tem nome, atributos e id
    char name[105];
    int atrib[10], id;
} celas;

typedef struct No{ // Estruct que representa o nó de um grafo
    celas C;
    struct No *next;
} no;

typedef struct Graph{ // Estruct que representa o grafo como uma lista de adjacência
    no **adj;
} graph;

void add(graph *G,int v,celas u){ // Função que coloca um novo no u na lista de adjacência v G[v]->u
    no *new_node=malloc(sizeof(no));
    new_node->C=u;
    new_node->next=G->adj[v];
    G->adj[v]=new_node;
}

void dfs(graph G,int v,int *visited,int num){ // DFS (Depth-first search) First-in\Last-out é responsável por percorrer o grafo
    visited[v]=1; // setamos que já vimos esse nó
    if(num==2) // não passamos de 3 rodadas
        return ;

    for(no *u=G.adj[v];u!=NULL;u=u->next) // percorro a lista de adjacência 
        dfs(G,u->C.id,visited,num+1);
}

