#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 10

typedef struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

void SinitStack (SStack s){
    s->sp = 0;
} 

int SisEmpty (SStack s){
    return (s->sp == 0);
}

int Spush (SStack s, int x){
    int r = 0;
    if (s->sp == Max) r = 1;
    else {
        s->values[s->sp] = x;
        s->sp++;
    }
    return r;
}

int Spop (SStack s, int *x){
    int r = 0;
    if (SisEmpty(s)) r = 1;
    else {
        s->sp--;
        *x = s->values[s->sp];
    }
    return r;
}

int Stop (SStack s, int *x){
    int r = 0;
    if (SisEmpty(s)) r = 1;
    else *x = s->values[s->sp-1];
    return r;
}

typedef struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

void SinitQueue (SQueue q){
    q->front = 0;
    q->length = 0;
}

int SisEmptyQ (SQueue q){
    return (q->length == 0);
}

int Senqueue (SQueue q, int x){
    int r = 0;
    if (q->length == Max) r = 1;
    else {
        q->values[(q->front + q->length) % Max] = x;
        q->length++;
    }
    return r;
}

int Sdequeue (SQueue q, int *x){
    int r = 0;
    if (SisEmptyQ(q)) r = 1;
    else {
        *x = q->values[q->front];
        q->front = (q->front + 1) % Max;
        q->length--;
    }
    return r;
}

int Sfront (SQueue q, int *x){
    int r = 0;
    if (SisEmptyQ(q)) r = 1;
    else *x = q->values[q->front];
    return r;
}

typedef struct dinStack {
    int size;
    int sp;
    int *values;
} *DStack;

void DinitStack (DStack s){
    s->size = 0;
    s->sp = 0;
    s->values = NULL;
}

int DisEmpty (DStack s){
    return (s->sp == 0);
}

int Dpush (DStack s, int x){
    int r = 0;
    if (s->sp == s->size){
        s->size += 1;
        s->values = realloc(s->values, s->size * sizeof(int));
    }
    s->values[s->sp] = x;
    s->sp++;
    return r;
}

int Dpop (DStack s, int *x){
    int r = 0;
    if (DisEmpty(s)) r = 1;
    else {
        s->sp--;
        *x = s->values[s->sp];
    }
    return r;
}

int Dtop (DStack s, int *x){
    int r = 0;
    if (DisEmpty(s)) r = 1;
    else *x = s->values[s->sp-1];
    return r;
}

typedef struct dinQueue {
    int size;
    int front;
    int length;
    int *values;
} *DQueue;

void DinitQueue (DQueue q){
    q->size = 0;
    q->front = 0;
    q->length = 0;
    q->values = NULL;
}

int DisEmptyQ (DQueue q){
    return (q->length == 0);
}

int Denqueue (DQueue q, int x){
    int r = 0;
    if (q->length == q->size){
        q->size += 1;
        q->values = realloc(q->values, q->size * sizeof(int));
    }
    q->values[(q->front + q->length) % q->size] = x;
    q->length++;
    return r;
}

int Ddequeue (DQueue q, int *x){
    int r = 0;
    if (DisEmptyQ(q)) r = 1;
    else {
        *x = q->values[q->front];
        q->front = (q->front + 1) % q->size;
        q->length--;
    }
    return r;
}

int Dfront (DQueue q, int *x){
    int r = 0;
    if (DisEmptyQ(q)) r = 1;
    else *x = q->values[q->front];
    return r;
}



