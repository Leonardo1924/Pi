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
}