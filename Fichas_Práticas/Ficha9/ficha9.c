#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin(int r, ABin e, ABin d){
    ABin a = malloc(sizeof(struct nodo));
    if(a!=NULL){
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

// 1

int altura(ABin a){
    if (a == NULL) return 0;
    int e = altura(a->esq);
    int d = altura(a->dir);
    return (e > d) ? e+1 : d+1;
}

int nFolhas(ABin a){
    if(a == NULL) return 0;
    else if(a->esq == NULL && a->dir == NULL) return 1;
    else {
        int esq = nFolhas(a->esq);
        int dir = nFolhas(a->dir);
        return esq + dir;
    }
}

ABin maisEsquerda(ABin a){
    if (a == NULL || a->esq == NULL) return a;
    else return maisEsquerda(a->esq);
}

void imprimeNivel(ABin a, int l){
    if (a == NULL) return;
    if (l == 1) printf("%d ", a->valor);
    else {
        imprimeNivel(a->esq, l-1);
        imprimeNivel(a->dir, l-1);
    }
}

int procuraE(ABin a, int x){
    if(a == NULL) return 0;
    else if(a->valor == x) return 1;
    else {
        int esq = procuraE(a->esq, x);
        int dir = procuraE(a->dir, x);
        return esq || dir;
    }
}

//2 

struct nodo *procura (ABin a, int x){
    if (a == NULL) return NULL;
    else if (a->valor == x) return a;
    else if (a->valor > x) return procura(a->esq, x);
    else return procura(a->dir, x);
}

int nivel(ABin a, int x){
    if (a == NULL) return -1;
    else if (a->valor == x) return 1;
    else if (a->valor > x){
        int esq = nivel(a->esq, x);
        if (esq == -1) return -1;
        else return esq + 1;
    }
    else {
        int dir = nivel(a->dir, x);
        if (dir == -1) return -1;
        else return dir + 1;
    }
}

void imprimeAte(ABin a, int x){
    if(a == NULL) return;
    if(a->valor == x) printf("%d ", a->valor);
    else if(a->valor > x) imprimeAte(a->esq, x);
    else {
        imprimeAte(a->esq, x);
        printf("%d ", a->valor);
        imprimeAte(a->dir, x);
    }
}