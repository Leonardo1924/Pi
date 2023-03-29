#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct aluno{
    int numero;
    char nome[100];
    int miniT[6];
    float teste;
} Aluno;

int nota (Aluno a){
    int i;
    float soma = 0.0;
    for(i = 0; i < 6; i++)
        soma += a.miniT[i];
    
    soma /= 6;
    
    soma = (soma * 20) / 2;
    
    if(soma < 5) return 0;
    
    soma *= 0.2;
    
    soma += a.teste * 0.80;
    
    soma = round(soma);
    if(soma < 10) return 0;
    else return soma;

}

int procuraNum(int num, Aluno t[], int N){
    int i;
    for(i = 0; i < N; i++)
        if(t[i].numero == num) return i;
    return -1;
}

int procuraNumV2(int num, Aluno t[], int N){
    int left, right;
    left = 0;
    right = N - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(t[mid].numero == num) return mid;
        else if(t[mid].numero < num) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void ordenaPorNum(Aluno t[], int N){
    int i,j;
    Aluno aux;
    for(i = 0; i < N; i++)
        for(j = i + 1; j < N; j++)
            if(t[i].numero > t[j].numero){
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
}

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
}
void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

int main() {
    Aluno Turma1 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;
    int indNome [7], indNum [7];
    int i;
    
    printf ("\n-------------- Testes --------------\n");
    ordenaPorNum (Turma1, 7);
    for (i=0; i<7; imprimeAluno (Turma1 + i++));


}