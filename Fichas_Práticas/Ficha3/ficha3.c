#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int ex1a(){
    int x [15] = {1, 2, 3, 4, 5,6, 7, 8, 9,10,11,12,13,14,15};
    int *y, *z, i;
    y = x;
    z = x+3;
    for (i=0; i<5; i++) {
        printf ("%d %d %d\n",x[i], *y, *z);
        y = y+1; z = z+2;
    }
}

int ex1b(){
    int i, j, *a, *b;
    i=3; j=5;
    a = &i; b = &j;
    i++;
    j = i + *b;
    b = a;
    j = j + *b;
    printf ("%d\n", j);
    return 0;
}

void swapM(int *x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int v[], int i, int j){
    int *pV = v;
    int *pVi = v + i;
    int *pVj = v + j;
    swapM(pVi,pVj); 
}

int soma (int v[], int N){
    int *pV = v;
    int soma = 0;
    for(int  i = 0 ; i < N; i++){
        soma += *(pV + i);
    }
    return soma;
}

void inverteArray(int v[], int N){
    int *pV = v;
    int *pVf = v + N - 1;
    for(int i = 0; i < N/2; i++){
        swapM(pV + i, pVf - i);
    }
}

int maximum(int v[],int N, int *m){
    *m = 0;
    int* pV = v;
    int value = 0;
    for(int i = 0 ; i < N ; i++){
        value = *(pV + i);
        if (value > *m )
            *m = value;
    }
    return 0;
}

void quadrados(int q[], int N){
    int* pQ = q;
    for(int i = 0 ; i < N ; i++){
        *(pQ + i) = pow(q[i],2);
    }
}

void pascal(int v[], int N){
    int* pV = v;
    if(N == 1) *pV = 1;
    else{
        int linhaAnterior[N-1];
        pascal(linhaAnterior, N-1);
        *pV = 1;
        *(pV + N - 1) = 1;
        for(int i = 1; i < N -1;i++){
            *(pV + i) = *(linhaAnterior + i - 1) + *(linhaAnterior + i);
        }
    } 
}




// MAIN //

int main(int argc, char *argv[]){
    char str1[] = "ex1a";
    if (strcmp(argv[1], str1) == 0){
        ex1a(); 
        // x[0]= 1 ; Y = 1 ; Z = 4
        // x[1]= 2 ; Y = 2 ; Z = 6
        // x[2]= 3 ; Y = 3 ; Z = 8
        // x[3]= 4 ; Y = 4 ; Z = 10
        // x[4]= 5 ; Y = 5 ; Z = 12
    }
    char str2[] = "ex1b";
    if (strcmp(argv[1], str2) == 0){
        ex1b();
        // 13
    }
    char str3[] = "ex2";
    if (strcmp(argv[1], str3) == 0){
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);
        swapM(&x, &y);
        printf("%d %d\n", x, y);
    }
    char str4[] = "ex3";
    if(strcmp(argv[1], str4) == 0){
        int v[10] = {1,2,3,4,5,6,7,8,9,10};
        int indice1 = atoi(argv[2]);
        int indice2 = atoi(argv[3]);
        swap(v, indice1 , indice2);
        for(int i = 0; i < 10; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    char str5[] = "ex4";
    if(strcmp(argv[1], str5) == 0){
        int v[10] = {2,2,2,2,2,2,2,2,2,2};
        printf("%d\n", soma(v, 10));
    }
    char str6[] = "ex5";
    if(strcmp(argv[1], str6) == 0){
        int v[11] = {1,2,3,4,5,6,7,8,9,10,11};
        inverteArray(v, 11);
        for(int i = 0; i < 11; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    char str7[] = "ex6";
    if(strcmp(argv[1], str7) == 0){
        int v[10] = {10,20,30,40,45,64,74,84,130,101};
        int m;
        maximum(v, 10, &m);
        printf("Máximo: %d\n", m);
    }
    char str8[] = "ex7";
    if(strcmp(argv[1], str8) == 0){
        int v[10] = {1,2,3,4,5,6,7,8,9,10};
        quadrados(v, 10);
        for(int i = 0; i < 10; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    char str9[] = "pascal";
    if(strcmp(argv[1], str9) == 0){
        int v[100];
        int N = atoi(argv[2]);
        pascal(v, N);
        for(int i = 0; i < N; i++){
                printf("%d ", v[i]);
            }
            printf("\n");
    }
    char str10[] = "fullpascal";
    if(strcmp(argv[1], str10) == 0){
        int N = atoi(argv[2]);
        for(int i = 1; i <= N; i++){
            int v[i];
            pascal(v, i);
            for(int j = 0; j < N - i; j++){
                printf(" ");
            }
            for(int j = 0; j < i; j++){
                printf("%d ", v[j]);
            }
            printf("\n");
        }
    }
}
