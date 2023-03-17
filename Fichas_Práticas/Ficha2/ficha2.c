#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float multInt1(int n, float m){
    float r = 0;
    for (int i = 1 ; i <= n ; i++){
        r += m;
    }
    return r;
}

float multInt2(int n, float m){
    float r = 0;
    while (n > 0){
        if (n % 2 == 1){
            r += m;
        }
        n = n / 2;
        m = 2 * m;
    }
    return r;
}

int min(int a, int b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}

int mdc1(int a, int b){
    int r , temp;
    for (int i = 1; i <= min(a,b) ; i++){
        if (a % i == 0 && b % i == 0){
            r = i;
        }
    }
    return r;
}

int mdc2(int a , int b){
    if (a > b){
        mdc2(a - b, b);
    }
    else if (a < b){
        mdc2(a, b - a);
    }
    else{
        return a;
    }
}

int mdc2v2(int a, int b){
    while(a != 0 && b != 0){
        if (a > b) a -= b;
        else if (b > a) b -= a;
        else return a;
    }
    if (a == 0) return b;
    else return a;    
}

int mdc3(int a, int b){
    while(a != 0 && b != 0){
        if (a > b) a %= b;
        else if (b > a) b %= a;
        else return a;
    }
    if (a == 0) return b;
    else return a;  
}

int fib1(int n){
    if (n < 2){
        return 1;
    }
    else{
        return fib1(n - 1) + fib1(n - 2);
    }
}

int fib2(int n){
    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(int argc, char *argv[]){
    char str1[] = "mult1";
    if (strcmp(argv[1], str1) == 0){
        float result = multInt1(atoi(argv[2]), atoi(argv[3]));
        printf("%.2f\n", result);
    }
    char str2[] = "mult2";
    if (strcmp(argv[1], str2) == 0){
        float result = multInt2(atoi(argv[2]), atoi(argv[3]));
        printf("%.2f\n", result);
    }
    char str3[] = "mdc1";
    if (strcmp(argv[1], str3) == 0){
        int result = mdc1(atoi(argv[2]), atoi(argv[3]));
        printf("%d\n", result);
    }
    char str4[] = "mdc2";
    if (strcmp(argv[1], str4) == 0){
        int result = mdc2(atoi(argv[2]), atoi(argv[3]));
        printf("%d\n", result);
    }
    char str5[] = "mdc2v2";
    if (strcmp(argv[1], str4) == 0){
        int result = mdc2v2(atoi(argv[2]), atoi(argv[3]));
        printf("%d\n", result);
    }
    char str6[] = "mdc3";
    if (strcmp(argv[1], str6) == 0){
        int result = mdc3(atoi(argv[2]), atoi(argv[3]));
        printf("%d\n", result);
    }
    char str7[] = "fib1";
    if (strcmp(argv[1], str7) == 0){
        int result = fib1(atoi(argv[2]));
        printf("%d\n", result);
    }
    char str8[] = "fib2";
    if (strcmp(argv[1], str8) == 0){
        int result = fib2(atoi(argv[2]));
        printf("%d\n", result);
    }
    return 0;
}