#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* prox;
} Node;
 
void push_front(Node **V,int value){
    Node *novo_no= malloc(sizeof(Node));
    novo_no->val=value;
    novo_no->prox=(*V);
    (*V) = novo_no;
}

void insert(Node *v,int value){
    Node *novo_no= malloc(sizeof(Node));
    novo_no->val=value;
    novo_no->prox=v->prox;
    v->prox=novo_no;
}

void push_back(Node **V,int value){
    Node *novo_no= malloc(sizeof(Node)), *ult=*V;
    novo_no->val=value;
    novo_no->prox=NULL;
    if(*V==NULL){
        *V=novo_no;
        return;
    }

    while(ult->prox!=NULL)
        ult=ult->prox;
    ult->prox=novo_no;
}

void delete_val(Node **V,int value){
    Node *temp=*V, *pre;
    pre=temp;

    while(temp!=NULL && temp->val!=value){
        pre=temp;
        temp=temp->prox;
    }

    pre->prox=temp->prox;
    free(temp);
}

void print(Node *V){
    while(V!=NULL){
        printf("%i ", V->val);
        V=V->prox;
    }
}

void encerra_lista(Node *V){
    if(V!=NULL){
        encerra_lista(V->prox);
        free(V);
    }
}

int main(){
    int n, m, c;
    Node *V=NULL;

    scanf("%i", &n);
 
    while(n--){
        scanf("%i %i", &m, &c);
        if(c==1)
            insert(V->prox,m);
        else if(c==2)
            push_back(&V,m);
        else
            push_front(&V,m);
    }

    delete_val(&V,1);
    print(V);
    printf("\n");
    encerra_lista(V);

    return 0;
}