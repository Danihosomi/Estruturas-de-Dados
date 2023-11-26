#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Cidade{ // Estruct que representa uma cidade, tem nome, população e id
    char name[55];
    double popu;
    int id;
} cidade;

typedef struct Graph{ // Estruct que representa o grafo como uma lista de adjacência
    double **adj_dist;
    int size;
} graph;

double min(double A,double B){
    if(A>B)
        return B;
    return A;
}

void add(graph *G,cidade *cidades,char cidade1[],char cidade2[],double distancia){ // Função responsável por adcionar arestas no grafo cidade1<->cidade2
    int i, j;
    for(i=0;i<G->size;i++)
        if(!strcmp(cidades[i].name,cidade1))
            break;   
    for(j=0;j<G->size;j++)
        if(!strcmp(cidades[j].name,cidade2))
            break; 

    if(G->adj_dist[i][j]==-1) // -1 Simboliza que aresta não existe ainda
        G->adj_dist[i][j]=G->adj_dist[j][i]=distancia;
    else
        G->adj_dist[i][j]=G->adj_dist[j][i]=min(distancia,G->adj_dist[i][j]);
}

void floyd_warshall(graph *G){
    for(int k=0;k<G->size;k++)
        for(int i=0;i<G->size;i++)
            for(int j=0;j<G->size;j++)
                if(G->adj_dist[i][k]!=-1 && G->adj_dist[k][j]!=-1){
                    if(G->adj_dist[i][j]==-1) // -1 Simboliza que aresta não existe ainda
                        G->adj_dist[i][j]=G->adj_dist[i][k]+G->adj_dist[k][j];
                    else
                        G->adj_dist[i][j]=min(G->adj_dist[i][j],G->adj_dist[i][k]+G->adj_dist[k][j]);
                }
}       
