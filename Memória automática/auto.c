#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int one(){
    int max = 0;
    while (1)
    {
        int num;
        scanf("%d", &num);
        if(num == 0)
            break;
        if (num > max)
            max = num;
    }
    return max;
}

int two(){
    int mean = 0;
    int count = 0;
    while (1){
        int num;
        scanf("%d", &num);
        if(num == 0)
            break;
        mean += num;
        count++;
    }
    return mean/count;
}

int three(){
    int max = 0;
    int max2 = 0;
    while (1){
        int num;
        scanf("%d", &num);
        if(num == 0)
            break;
        if (num > max){
            max2 = max;
            max = num;
        }
    }
    return max2;
}

int bitsUm(unsigned int n){
    int count = 0;
    while (n != 0){
        if (n % 2 == 1)
            count++;
        n = n / 2;
    }
    return count;
}

int trailingZ(unsigned int n){
    int count = 0;
    while (n % 2 == 0){
        count++;
        n = n / 2;
    }
    return count;
}

int qDig(unsigned int n){
    int count = 0;
    while (n != 0){
        count++;
        n = n / 10;
    }
    return count;
}

char *strcatByLeo(char s1[], char s2[]){
    int i = 0;
    int j = 0;
    while (s1[i] != '\0'){
        i++;
    }
    while (s2[j] != '\0'){
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return s1;
}




int main(){
    char x[] = "Hello";
    char y[] = "World";
    printf("%s\n", strcatByLeo(x, y));
    return 0;
}