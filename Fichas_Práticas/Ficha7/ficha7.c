#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct celula{
    char *palavra;
    int ocorr;
    struct celula * prox;
}* Palavras;

void libertaLista(Palavras l){
    Palavras aux;
    while(l != NULL){
        aux = l;
        l = l->prox;
        free(aux->palavra);
        free(aux);
    }
}

int quantasP(Palavras l){
    int r = 0;
    while(l != NULL){
        r++;
        l = l->prox;
    }
}

void listaPal(Palavras l){
    while(l != NULL){
        printf("%s %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

char * ultima(Palavras l){
    char * r = NULL;
    if(l != NULL){
        while(l->prox != NULL){
            l = l->prox;
        }
        r = strdup(l->palavra);
    }
    return r;
}

Palavras acrescentaInicio(Palavras l, char *p){
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = l;
    return new;
}

Palavras acrecentaFim (Palavras l, char *p){
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = NULL;
    if(l == NULL){
        return new;
    }
    Palavras aux = l;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = new;
    return l;
}

Palavras acrescenta (Palavras l, char *p){
    Palavras aux = l;
    while(aux != NULL && strcmp(aux->palavra, p) != 0){
        aux = aux->prox;
    }
    if(aux == NULL){
        return acrecentaFim(l, p);
    }
    else{
        aux->ocorr++;
        return l;
    }
}

struct celula * maisFreq(Palavras l){
    Palavras aux = l;
    Palavras r = NULL;
    int max = 0;
    while(aux != NULL){
        if(aux->ocorr > max){
            max = aux->ocorr;
            r = aux;
        }
    }
    return r;
}