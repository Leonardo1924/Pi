#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

/**************** Auxiliar *********************/

void swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

void printList(LInt lista) {
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

/***********************************************/

int length (LInt l){
    int size = 0;
    while(l != NULL){
        size++;
        l = l->prox;
    }
    return size;
}

void freeL(LInt l){
    LInt aux = l;
    while (l != NULL){
        aux = l->prox;
        free(l);
        l = aux;
    }
    free(aux);
}

void imprimeL (LInt l){
    while(l != NULL){
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

LInt reverseL(LInt l){
    if(l == NULL || l->prox == NULL) return l;
    LInt anterior = NULL;
    LInt atual = l;
    LInt proximo = l->prox;
   
    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}

void insertOrd (LInt *l, int x){
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if(*l == NULL){
        *l = new;
        return;
    }
    else if(x < (*l)->valor){
        new->prox = *l;
        *l = new;
    } else {
        LInt anterior = *l;
        LInt atual = (*l)->prox;

        while(atual != NULL && x > atual->valor){
            anterior = atual;
            atual = atual->prox;
        }

        anterior->prox = new;
        new->prox = atual;
    }
}

int removeOneOrd(LInt* l , int x){
    if(*l == NULL) return 1;
    else if ((*l)->valor == x) {
        LInt aux = *l;
        *l = (*l)->prox;
        free(aux);
        return 0;
    }
    else {
        LInt anterior = *l;
        LInt atual = (*l)->prox;

        while (atual != NULL && atual->valor != x){
            anterior = atual;
            atual = atual->prox;
        }

        if(atual == NULL) return 1;
        else {
            anterior->prox = atual->prox;
            free(atual);
            return 0;
        }
    }
}

void merge(LInt *r, LInt a, LInt b){
    LInt result = NULL;
    LInt *tail = &result;
    while(a != NULL && b != NULL){
        if(a->valor < b->valor){
            *tail = a;
            a = a->prox;
        } else {
            *tail = b;
            b = b->prox;
        }
        tail = &((*tail)->prox);
    }
    *tail = (a!=NULL) ? a : b;
    *r = result;
}

void splitQS(LInt l, int x, LInt *mx, LInt *Mx){
    *mx = NULL;
    *Mx = NULL;
    LInt *a = NULL, *b = NULL;
    while(l){
        if(l->valor < x){
            if(*mx){
                (*a)->prox = l;
                a = &((*a)->prox);
            } else {
                *mx = l;
                a = mx;
            }
        } else {
            if(*Mx){
                (*b)->prox = l;
                b = &((*b)->prox);
            } else {
                *Mx = l;
                b = Mx;
            }
        }
        l = l->prox;
    }
    if(a) (*a)->prox = NULL;
    if(b) (*b)->prox = NULL;
}

LInt parteAmeio(LInt *l){
    int size = length(*l);
    int meio = size/2;
    LInt aux = *l;
    LInt result = NULL;
    LInt *tail = &result;
    while(meio > 0){
        *tail = aux;
        aux = aux->prox;
        tail = &((*tail)->prox);
        meio--;
    }
    *tail = NULL;
    *l = aux;
    return result;
}

int removeAll(LInt *l , int x){
    int count = 0;
    LInt prev = NULL;
    LInt temp = *l;
    while (temp){
        if(temp->valor == x){
            count++;
            if(prev){
                prev->prox = temp->prox;
                LInt next = temp->prox;
                free(temp);
                temp = next;
            } else {
               LInt next = (*l)->prox;
               free(*l);
                *l = next;
                temp = *l;
            }
        } else {
            prev = temp;
            temp = temp->prox;
        }
    }
    return count;  
}

int removeDups (LInt *l){
    int count = 0;
    while((*l) && (*l)->prox) {
        count += removeAll(&(*l)->prox, (*l)->valor);
        l = &(*l)->prox;
    }
    return count;
}

int removeMaiorL (LInt *l){
    LInt* maior = l;
    LInt* antes = NULL;
    
    if(*l == NULL)
        return 0;
        
    LInt* prev = NULL;
    LInt* temp = l;
    while((*l)) {
        if((*l)->valor > (*maior)->valor) {
            maior = l;
            antes = prev;
        }
        prev = l;
        l = &(*l)->prox;
    }
    
    int res = (*maior)->valor;
    

    if(antes) {
        (*antes)->prox = (*maior)->prox;
    } else {
        l = temp;
        *l = (*l)->prox;
    }
    
    return res;
}

void init (LInt *l){
    if(*l == NULL) return;
    else if((*l)->prox == NULL){
        free(*l);
        *l = NULL;
    } else {
        LInt aux = *l;
        while(aux->prox->prox != NULL){
            aux = aux->prox;
        }
        free(aux->prox);
        aux->prox = NULL;
    }
}

void appendL (LInt *l, int x){
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if(*l == NULL){
        *l = new;
        return;
    }
    else {
        LInt aux = *l;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = new;
    }
}

void concatL (LInt *a, LInt b){
    if(*a == NULL){
        *a = b;
        return;
    }
    else {
        LInt aux = *a;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = b;
    }
}

LInt cloneL (LInt l){
    LInt new = NULL;
    LInt *tail = &new;
    while(l != NULL){
        *tail = malloc(sizeof(struct lligada));
        (*tail)->valor = l->valor;
        (*tail)->prox = NULL;
        tail = &((*tail)->prox);
        l = l->prox;
    }
    return new;
}

LInt cloneRev (LInt l){
    LInt new = NULL;
    LInt *tail = &new;
    while(l != NULL){
        *tail = malloc(sizeof(struct lligada));
        (*tail)->valor = l->valor;
        (*tail)->prox = NULL;
        tail = &((*tail)->prox);
        l = l->prox;
    }
    return reverseL(new);
}

int maximo (LInt l){
    int max = l->valor;
    while(l != NULL){
        if(l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}

int take (int n, LInt *l){
    int count = 0;
    while(*l != NULL && count < n){
        l = &((*l)->prox);
        count++;
    }
    if(*l == NULL) return count;
    else {
        LInt aux = *l;
        while(aux != NULL){
            LInt temp = aux;
            aux = aux->prox;
            free(temp);
        }
        *l = NULL;
        return count;
    }
}

int drop (int n, LInt *l){
    int count = 0;
    while(*l != NULL && count < n){
        LInt aux = *l;
        *l = (*l)->prox;
        free(aux);
        count++;
    }
    return count;
}

LInt NForward (LInt l, int N){
    while(l != NULL && N > 0){
        l = l->prox;
        N--;
    }
    return l;
}

int listToArray(LInt l, int v[], int N){
    int i = 0;
    while(l != NULL && i < N){
        v[i] = l->valor;
        l = l->prox;
        i++;
    }
    return i;
}

LInt arrayToList (int v[], int N){
    LInt new = NULL;
    LInt *tail = &new;
    int i = 0;
    while(i < N){
        *tail = malloc(sizeof(struct lligada));
        (*tail)->valor = v[i];
        (*tail)->prox = NULL;
        tail = &((*tail)->prox);
        i++;
    }
    return new;
}

LInt somasAcL (LInt l){
    int sum = 0;
    LInt new = NULL;
    LInt *tail = &new;
    while(l != NULL){
        sum += l->valor;
        *tail = malloc(sizeof(struct lligada));
        (*tail)->valor = sum;
        (*tail)->prox = NULL;
        tail = &((*tail)->prox);
        l = l->prox;
    }
    return new;
}

void remreps (LInt l){
    while(l != NULL && l->prox != NULL){
        if(l->valor == l->prox->valor){
            LInt aux = l->prox;
            l->prox = l->prox->prox;
            free(aux);
        } else {
            l = l->prox;
        }
    }
}

LInt rotateL (LInt l){
    if(l == NULL || l->prox == NULL) return l;
    LInt aux = l;
    LInt new = l->prox;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = l;
    l->prox = NULL;
    return new;
}

LInt parte(LInt l){
    if(l == NULL || l->prox == NULL) return NULL;

    LInt res[2] = {NULL, NULL};
    LInt temp[2] = {NULL, NULL};
    int index = 0;

    while (l != NULL){
        int j = index % 2;
        if(res[j] == NULL){
            res[j] = l;
            temp[j] = res[j];
        } else {
            temp[j]->prox = l;
            temp[j] = l;
        }
        l = l->prox;
        index++;
    }
    temp[0]->prox = NULL;
    temp[1]->prox = NULL;
    l = res[0];
    return res[1];    
}

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int altura (ABin a){
    if (a == NULL) return 0;
    else {
        int esq = altura(a->esq);
        int dir = altura(a->dir);
        return (esq > dir) ? esq + 1 : dir + 1;
    }
}

ABin cloneAB (ABin a){
    if(a == NULL) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneAB(a->esq);
    new->dir = cloneAB(a->dir);
    return new;
}

void mirror (ABin * a){
    if(*a == NULL) return;
    ABin aux = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = aux;
    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
}

void inorder (ABin a, LInt *l){
    if(a == NULL) return;
    inorder(a->esq, l);
    while(*l != NULL){
        l = &((*l)->prox);
    }
    *l = malloc(sizeof(struct lligada));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
    inorder(a->dir, l);
}

void preorderaux(ABin a, LInt *l) {
    LInt aux;
    if(a) {
        preorderaux(a->dir,l);
        preorderaux(a->esq,l);

        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;
    }
}

void preorder(ABin a, LInt *l){
    *l = NULL;
    preorderaux(a,l);
}

void posorderaux(ABin tree, LInt * list) {
    if(tree) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = tree->valor;
        new->prox = (*list);
        (*list) = new;
        posorderaux(tree->dir,list);
        posorderaux(tree->esq,list);
    }
}

void posorder(ABin tree, LInt * list) {
    *list = NULL;
    posorderaux(tree,list);
}

int depth(ABin a, int x){
    if(a == NULL) return -1;
    else if(a->valor == x) return 1;
    else{
        int esq = depth(a->esq, x);
        int dir = depth(a->dir, x);
        if(esq == -1 && dir == -1) return -1;
        else if(esq == -1) return dir + 1;
        else if(dir == -1) return esq + 1;
        else return (esq < dir) ? esq + 1 : dir + 1;
    }
}

int freeAB (ABin a){
    if(a == NULL) return 0;
    else {
        int esq = freeAB(a->esq);
        int dir = freeAB(a->dir);
        free(a);
        return esq + dir + 1;
    }
}

int pruneAB (ABin *a, int l){
    if(*a == NULL) return 0;
    else if(l == 0){
        int esq = pruneAB(&((*a)->esq), 0);
        int dir = pruneAB(&((*a)->dir), 0);
        free(*a);
        *a = NULL;
        return esq + dir + 1;
    }
    else {
        int esq = pruneAB(&((*a)->esq), l-1);
        int dir = pruneAB(&((*a)->dir), l-1);
        return esq + dir;
    }
}

int iguaisAB (ABin a, ABin b){
    if(a == NULL && b == NULL) return 1;
    else if(a == NULL || b == NULL) return 0;
    else if(a->valor != b->valor) return 0;
    else {
        int esq = iguaisAB(a->esq, b->esq);
        int dir = iguaisAB(a->dir, b->dir);
        return esq && dir;
    }
}

LInt nivelL (ABin a, int n){
    if(a == NULL) return NULL;
    else if(n == 1){
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else {
        LInt esq = nivelL(a->esq, n-1);
        LInt dir = nivelL(a->dir, n-1);
        if(esq == NULL) return dir;
        else if(dir == NULL) return esq;
        else {
            LInt aux = esq;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = dir;
            return esq;
        }
    }
}

int nivelV(ABin a, int n, int v[]){
    if(a == NULL) return 0;
    else if(n == 1){
        v[0] = a->valor;
        return 1;
    }
    else {
        int esq = nivelV(a->esq, n-1, v);
        int dir = nivelV(a->dir, n-1, v+esq);
        return esq + dir;
    }
}

int dumpAbin (ABin a, int v[], int N){
    if(a && N){
        int esq = dumpAbin(a->esq, v, N);
        if (esq < N){
            v[esq] = a->valor;
            int dir = dumpAbin(a->dir, v+esq+1, N-esq-1);
            return esq + dir + 1;
        }
        else return esq;
    }
    else return 0;
}

ABin somasAcA (ABin a){
    if(a == NULL) return NULL;
    else {
        ABin new = malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->esq = somasAcA(a->esq);
        new->dir = somasAcA(a->dir);
        if(new->esq != NULL) new->valor += new->esq->valor;
        if(new->dir != NULL) new->valor += new->dir->valor;
        return new;
    }
}

int contaFolhas(ABin a){
    if(a == NULL) return 0;
    else if(a->esq == NULL && a->dir == NULL) return 1;
    else {
        int esq = contaFolhas(a->esq);
        int dir = contaFolhas(a->dir);
        return esq + dir;
    }
}

ABin cloneMirror (ABin a){
    if(a == NULL) return NULL;
    else {
        ABin new = malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->esq = cloneMirror(a->dir);
        new->dir = cloneMirror(a->esq);
        return new;
    }
}

int addOrd (ABin *a , int x){
    if(*a == NULL){
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
        return 0;
    }
    else if((*a)->valor == x) return 1;
    else if((*a)->valor > x) return addOrd(&((*a)->esq), x);
    else return addOrd(&((*a)->dir), x);
}

int lookupAB (ABin a, int x){
    if(a == NULL) return 0;
    else if(a->valor == x) return 1;
    else if(a->valor > x) return lookupAB(a->esq, x);
    else return lookupAB(a->dir, x);
}

int depthOrd (ABin a, int x) {
    if(a == NULL) return -1;
    else if(a->valor == x) return 1;
    else if(a->valor > x){
        int esq = depthOrd(a->esq, x);
        if(esq == -1) return -1;
        else return esq + 1;
    }
    else {
        int dir = depthOrd(a->dir, x);
        if(dir == -1) return -1;
        else return dir + 1;
    }
}

int maiorAB (ABin a){
    if(a->dir == NULL) return a->valor;
    else return maiorAB(a->dir);
}

void removeMaiorA (ABin *a){
    if((*a)->dir == NULL){
        ABin aux = *a;
        *a = (*a)->esq;
        free(aux);
    }
    else removeMaiorA(&((*a)->dir));
}

int quantosMaiores (ABin a, int x){
    if(a == NULL) return 0;
    else if(a->valor <= x) return quantosMaiores(a->dir, x);
    else {
        int esq = quantosMaiores(a->esq, x);
        int dir = quantosMaiores(a->dir, x);
        return esq + dir + 1;
    }
}

void listToBTree (LInt l, ABin *a){
    if(!l) return;
    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l)/2;
    LInt temp = l,  prev = NULL;
    int i;
    for(i = 0; i < meio; i++){
        prev = temp;
        temp = temp->prox;
    }
    new->valor = temp->valor;
    new->esq = new->dir = NULL;
    if(prev != NULL) prev->prox = NULL;
    
    if(l != temp) listToBTree(l, &(new->esq));
    if(temp->prox != NULL) listToBTree(temp->prox, &(new->dir));
    *a = new;
}

int deProcura(ABin a){
    if(a == NULL) return 1;
    else if(a->esq != NULL && maiorAB(a->esq) > a->valor) return 0;
    else if(a->dir != NULL && maiorAB(a->dir) < a->valor) return 0;
    else {
        int esq = deProcura(a->esq);
        int dir = deProcura(a->dir);
        return esq && dir;
    }
}