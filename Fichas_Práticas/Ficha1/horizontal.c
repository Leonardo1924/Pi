#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void triangulo(int n){
    int rows = n;
    int spaces = n-1;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < spaces-i; j++){
            printf(" ");
        }
        for (int j = 0; j < 2*i+1; j++){
            printf("#");
        }
        printf("\n");
    }
}