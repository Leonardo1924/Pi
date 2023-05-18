#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

LInt newLint(int x, LInt xs){
    LInt r = malloc(sizeof(struct slist));
    if (r!=NULL){
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

typedef LInt Stack;

typedef struct queue {
    LInt inicio, fim;
} Queue;

void initStack(Stack *s){
    *s = NULL;
}

int SisEmpty(Stack s){
    return s==NULL;
}

int push(Stack *s, int x){
    int r = 0;
    LInt aux = newLint(x,*s);
    if (aux!=NULL){
        *s = aux;
        r = 1;
    }
    return r;
}

int pop(Stack *s, int *x){
    if(SisEmpty(*s)) return 0;
    *x = (*s)->valor;
    LInt aux = *s;
    *s = (*s)->prox;
    free(aux);
    return 1;   
}

int top(Stack s, int *x){
    if(SisEmpty(s)) return 0;
    *x = s->valor;
    return 1;
}

void initQueue(Queue *q){
    q->inicio = q->fim = NULL;
}

int QisEmpty(Queue q){
    return q.inicio == NULL;
}

int enqueue(Queue *q, int x){
    int r = 0;
    LInt aux = newLint(x,NULL);
    if (aux!=NULL){
        if(QisEmpty(*q)){
            q->inicio = q->fim = aux;
        } else {
            q->fim->prox = aux;
            q->fim = aux;
        }
    }
}

int dequeue(Queue *q, int *x){
    if(QisEmpty(*q)) return 0;
    *x = q->inicio->valor;
    LInt aux = q->inicio;
    q->inicio = q->inicio->prox;
    free(aux);
    if(q->inicio == NULL) q->fim = NULL;
    return 1;
}

int front(Queue q, int *x){
    if(QisEmpty(q)) return 0;
    *x = q.inicio->valor;
    return 1;
}

/************************* Exercicio 3 ************************************ */
// Pedir ao ChatGpt para explicar os exercicio 3 e 4
typedef LInt QueueC;

void initQueueC(QueueC *q){
    *q = NULL;
}

int QisEmptyC(QueueC q){
    return q==NULL;
}

int enqueueC(QueueC *q, int x){
    LInt aux = newLint(x,*q);
    if (aux!=NULL){
        if(QisEmptyC(*q)){
            aux->prox = aux;
        } else {
            aux->prox = (*q)->prox;
            (*q)->prox = aux;
        }
        *q = aux;
    }
    return 1;
}

int dequeueC(QueueC *q, int *x){
    if(QisEmptyC(*q)) return 0;
    *x = (*q)->prox->valor;
    LInt aux = (*q)->prox;
    if(*q == (*q)->prox) *q = NULL;
    else (*q)->prox = (*q)->prox->prox;
    free(aux);
    return 1;
}

int frontC(QueueC q, int *x){
    if(QisEmptyC(q)) return 0;
    *x = q->prox->valor;
    return 1;
}


/************************** Exercicio 4 ************************************/

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;


typedef struct {
    DList back, front;
} Deque;

void initDeque(Deque *q){
    q->back = q->front = NULL;
}

int DisEmpty(Deque q){
    return q.back == NULL;
}

int pushBack(Deque *q, int x){
    int r = 0;
    DList aux = malloc(sizeof(struct dlist));
    if(aux!=NULL){
        aux->valor = x;
        aux->prox = NULL;
        if(DisEmpty(*q)){
            aux->ant = NULL;
            q->back = q->front = aux;
        } else {
            aux->ant = q->back;
            q->back->prox = aux;
            q->back = aux;
        }
    }
}

int pushFront(Deque *q, int x){
    int r = 0;
    DList aux = malloc(sizeof(struct dlist));
    if(aux!=NULL){
        aux->valor = x;
        aux->ant = NULL;
        if(DisEmpty(*q)){
            aux->prox = NULL;
            q->back = q->front = aux;
        } else {
            aux->prox = q->front;
            q->front->ant = aux;
            q->front = aux;
        }
    }
}

int popBack(Deque *q, int *x){
    if(DisEmpty(*q)) return 0;
    *x = q->back->valor;
    DList aux = q->back;
    q->back = q->back->ant;
    free(aux);
    if(q->back == NULL) q->front = NULL;
    return 1;
}

int popFront(Deque *q, int *x){
    if(DisEmpty(*q)) return 0;
    *x = q->front->valor;
    DList aux = q->front;
    q->front = q->front->prox;
    free(aux);
    if(q->front == NULL) q->back = NULL;
    return 1;
}

int popMax(Deque *q, int *x){
    if(DisEmpty(*q)) return 0;
    *x = q->front->valor;
    DList aux = q->front;
    q->front = q->front->prox;
    free(aux);
    if(q->front == NULL) q->back = NULL;
    return 1;
}

int back(Deque q, int *x){
    if(DisEmpty(q)) return 0;
    *x = q.back->valor;
    return 1;
}

int front(Deque q, int *x){
    if(DisEmpty(q)) return 0;
    *x = q.front->valor;
    return 1;
}

