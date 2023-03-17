#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quadrado(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("#");
        }
        printf("\n");
    }
}

void xadrez(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if ((i + j) % 2 == 0){
                printf("#");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
}

void circulo(int n){
    int radius = n;
    int x , y;
    for(y = -radius; y <= radius; y++){
        for(x = -radius; x <= radius; x++){
            if(x*x + y*y <= radius*radius){
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]){
    char str1[] = "quadrado";
    if (strcmp(argv[1], str1) == 0){
        quadrado(atoi(argv[2]));
    }
    char str2[] = "xadrez";
    if (strcmp(argv[1], str2) == 0){
        xadrez(atoi(argv[2]));
    }
    char str3[] = "circulo";
    if (strcmp(argv[1], str3) == 0){
        circulo(atoi(argv[2]));
    }
}