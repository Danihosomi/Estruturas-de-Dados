#include<stdio.h>
#include<string.h>
#define MAX_ALU 105

// Da pra melhorar usando merge sort O(nlogn)
void ssort(int n,char nomes[][35]){
    /*
    Função que recebe a quantidade de nomes e um vetor de strings e retorna
    o vetor de string ordenado lexograficamente.
    Selection Sort O(N^2)
    */
    for(int i=0;i<n;i++){
        int id=i;
        char auxiliar[35];
        for(int j=i;j<n;j++)
            if(strcmp(nomes[id],nomes[j])>0)
                id=j;
        
        strcpy(auxiliar,nomes[i]);
        strcpy(nomes[i],nomes[id]);
        strcpy(nomes[id],auxiliar);
    }
}
