#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/****************************STRUCTS**********************************/
typedef struct LInt_nodo {
	int valor;
	struct LInt_nodo *prox;
} *LInt;

typedef struct ABin_nodo {
	int valor;
	struct ABin_nodo *esq, *dir;
} *ABin;

/******************** Funções Auxiliares ****************************/
LInt newLInt (int x, LInt xs){
	LInt r = malloc (sizeof (struct LInt_nodo));
	r->valor = x; r->prox = xs;
	return r;
}

LInt LfromArray(int v[], int N){
	int i;
	LInt r = NULL;
	for (i=N-1; i>=0; i--)
		r = newLInt (v[i],r);
	return r;
}

void dumpL (LInt l){
	while (l!= NULL) {
		printf ("%d ", l->valor);
		l = l->prox;
	}
	putchar ('\n');
}

void freeLInt (LInt l) {
	LInt aux;
	while (l!=NULL) {
		aux = l; l=l->prox;free (aux);
	}
}

ABin newABin (int r, ABin e, ABin d){
	ABin x = malloc (sizeof(struct ABin_nodo));
	x->valor = r;
	x->esq = e; x->dir = d; 
	return x;
}

ABin AfromArray(int v[], int N){
	ABin r;
	int m;
	if (N<=0) r = NULL;
	else {
		m = N/2;
		r = newABin (v[m],AfromArray (v,m),
			              AfromArray (v+m+1,N-m-1));
	}
	return r;
}
void freeABin (ABin a){
	if (a!= NULL) {
		freeABin (a->esq);freeABin (a->dir); free (a);
	}
}

void swap (int v[], int i, int j){
	int t=v[i];
	v[i] = v[j];
	v[j]=t;
}

void dumpA(int q1[]){
    printf("Array Ordenado: {");
    for(int i = 0; i < 20; i++){
        printf("%d",q1[i]);
        if(i != 19){
            printf(",");
        }
    }
    printf("}");
}

/********************************************************************/

void bubbleSort(int a[], int N){
    int i,j;
    for(i = 0; i < N-1 ; i++){
        for(j = 0; j < N-i-1; j++){
            if(a[j] > a [j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int nesimo(int a[], int N, int i){
    bubbleSort(a,N);
    int result = 0;
    for(int j = 0; j != i ; j++) result = a[j];
    return result;
}


LInt removeMaiores(LInt l, int x){
    LInt result = NULL;
    LInt current = NULL;
    while(l != NULL){
        if(l->valor <= x){
            if(result == NULL){
                result = malloc(sizeof(struct LInt_nodo));
                result->valor = l->valor;
                result->prox = NULL;
                current = result;
            } else {
                current->prox = malloc(sizeof(struct LInt_nodo));
                current = current->prox;
                current->valor = l->valor;
                current->prox = NULL;
            }
        }
        l = l->prox;
    }
    return result;
}

LInt removeMaioresV2(LInt l, int x){
    LInt pt = l, ant = NULL;
    while(pt != NULL && pt->valor <= x){
        ant = pt;
        pt = pt->prox;
    }

    if(ant == NULL) l = NULL;
    else ant->prox = NULL;

    while(pt != NULL){
        ant = pt; pt = pt->prox; free(ant);
    }

    return l;
}


LInt caminho(ABin a, int x){
    LInt l = NULL;
    if(!a) return NULL;
    else{
        if(a->valor == x){
            l = malloc(sizeof(struct LInt_nodo));
            l->valor = x;
            l->prox = NULL;
        }
        else{
            if(a->valor > x ) l = caminho(a->esq, x);
            else l = caminho(a->dir,x);
            if(l != NULL) l = newLInt(a->valor, l);
        }
    }
    return l;
}

void inc(char s[]) {
	int l = strlen(s), i;

	for (i = l-1; i>=0 && s[i] == '9'; s[i--]='0');
	// caso particular: a string aumenta de tamanho
	if (i==-1) { s[0] = '1'; s[l] = '0'; s[l+1]='\0';}
    else s[i]++;
}


int ensacarAux_sol(int p[], int N, int k, int i, int pesos[]) {
    if (i == N)
        return 1;

    for (int j = 0; j < k; j++) {
        if (p[i] <= pesos[j]) {
            pesos[j] -= p[i];
            if (ensacarAux_sol(p, N, k, i + 1, pesos))
                return 1;
            pesos[j] += p[i];
        }
    }

    return 0;
}

int ensacar_sol(int p[], int N, int C, int k) {
    int pesos[k];
    for (int i = 0; i < k; i++)
        pesos[i] = C;

    return ensacarAux_sol(p, N, k, 0, pesos);
}

int sacos(int p[], int N, int C) {
    int k = 1;
    while (!ensacar_sol(p, N, C, k))
        k++;
    return k;
}