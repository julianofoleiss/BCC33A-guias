#include <stdio.h>
#include <stdlib.h>
#include "abb.h"


ABB* ABB_Buscar(ABB* A, int chave){
    if(A == NULL)
        return NULL;
    else{
        if(A->chave == chave){
            return A;
        }
        if(chave < A->chave){
            return ABB_Buscar(A->esq, chave);
        }
        else
            return ABB_Buscar(A->dir, chave);
    }
}


ABB* ABB_Criar(int chave, ABB* esq, ABB* dir){
    ABB* nova;

    nova = malloc(sizeof(ABB));
    nova->chave = chave;
    nova->esq = esq;
    nova->dir = dir;
    
    return nova;
}

ABB** ABB_Min(ABB **A){
    if((*A) == NULL)
        return NULL;
    while((*A)->esq != NULL)
        A = &(*A)->esq;
    return A;
}

void ABB_Remover(ABB **A, int chave){
    if(*A == NULL)
        return;
    if(chave < (*A)->chave)
        ABB_Remover(&(*A)->esq, chave);
    else if (chave > (*A)->chave)
        ABB_Remover(&(*A)->dir, chave);
    else{
        ABB *t, **suc;

        if((*A)->esq == NULL){
            t = *A;
            *A = (*A)->dir;
            free(t);
            return;
        }

        if((*A)->dir == NULL){
            t = *A;
            *A = (*A)->esq;
            free(t);
            return;
        }

        t = *A;
        suc = ABB_Min(&t->dir);
        t->chave = (*suc)->chave;
        ABB_Remover(suc, (*suc)->chave);
    }
}

void ABB_Inserir(ABB** A, int chave){
    if(*A == NULL){
        *A = ABB_Criar(chave, NULL, NULL);
        return;
    }

    if(chave <= (*A)->chave ){
        ABB_Inserir(&(*A)->esq, chave);
    }
    else{
        ABB_Inserir(&(*A)->dir, chave);
    }
}

void ABB_Imprimir(ABB *A, int nivel, char lado){
    int i;
    if(A == NULL)
        return;
    for(i = 0 ; i < nivel; i++) printf("\t");
    printf("(%c) %d\n", lado, A->chave);
    ABB_Imprimir(A->esq, nivel+1, 'e');
    ABB_Imprimir(A->dir, nivel+1, 'd');
}

