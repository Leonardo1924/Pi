#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void triangulo(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            printf("#");
        }
        printf("\n");
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            printf("#");
        }
        printf("\n");
    }
}
