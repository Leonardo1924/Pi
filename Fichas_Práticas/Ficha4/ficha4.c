#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isvogal(char c){
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

int contaVogais(char *s){
    int i, count = 0;
    for(i = 0; s[i] != '\0'; i++){
        if(isvogal(s[i])) count++;
    }
    return count;
}

int retiraVogaisRep(char *s){
    int n = strlen(s);
    int count = 0;
    int i = 0;
    int j = 0;
    for(i = 0, j = 0; i < n; i++){
        if(isvogal(s[i]))
        {
            if(i == 0 || !isvogal(s[i-1]) || s[i] != s[i-1])
            {
                s[j++] = s[i];
            }
            else
            {
                count++;
            }
        }
        else{
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
    return count;
}

int duplicaVogais(char *s){
    int added = contaVogais(s);
    
    int size = strlen(s);
    int j = size + added;
    
    s[j--] = '\0';
    
    int i = size - 1;
    
    while(i >= 0)
    {
        if(isvogal(s[i]))
        {
            s[j--] = s[i];
            s[j--] = s[i];
        }
        else
        {
            s[j--] = s[i];
        }
        
        --i;
    } 
    return added;
}

int ordenado (int v[], int N){
  for(int i = 0; i < N ; i++){
    if(v[i] > v[i+1]) return 0;
  }
  return 1;
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int i = 0, j = 0, k = 0;
    while(i < na && j < nb){
        if(a[i] < b[j]){
        r[k] = a[i];
        i++;
        }
        else{
        r[k] = b[j];
        j++;
        }
        k++;
    }
    while(i < na){
        r[k] = a[i];
        i++;
        k++;
    }
    while(j < nb){
        r[k] = b[j];
        j++;
        k++;
    }
}

int partition(int v[], int N, int x){
    int i = 0, j = N-1;
    while(i < j){
        while(v[i] < x) i++;
        while(v[j] >= x) j--;
        if(i < j){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    return i;
} 

int main(int argc, char *argv[]){
    char str1[] = "contaVogais";
    if(strcmp(argv[1], str1) == 0){
        char str2[100];
        strcpy(str2, argv[2]);
        int count = contaVogais(str2);
        printf("%d\n", count);
    }
    char str3[] = "retiraVogaisRep";
    if(strcmp(argv[1], str3) == 0){
        char str4[100];
        strcpy(str4, argv[2]);
        retiraVogaisRep(str4);
        printf("%s\n", str4);
    }
    char str5[] = "duplicaVogais";
    if(strcmp(argv[1], str5) == 0){
        char str6[100];
        strcpy(str6, argv[2]);
        duplicaVogais(str6);
        printf("%s\n", str6);
    }
    char str7[] = "ordenado";
    if(strcmp(argv[1], str7) == 0){
        int v[11] = {0,1,2,3,4,5,6,7,8,9,10};
        int res = ordenado(v, 11);
        printf("%d\n", res);
    }
    char str8[] = "merge";
    if(strcmp(argv[1], str8) == 0){
        int a[5] = {1,3,5,7,9};
        int b[5] = {2,4,6,8,10};
        int r[10];
        merge(a, 5, b, 5, r);
        for(int i = 0; i < 10; i++){
            printf("%d ", r[i]);
        }
        printf("\n");
    }    
    return 0;
}