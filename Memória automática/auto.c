#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

void swapW(char *x, char *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int one()
{
    int max = 0;
    while (1)
    {
        int num;
        scanf("%d", &num);
        if (num == 0)
            break;
        if (num > max)
            max = num;
    }
    return max;
}

int two()
{
    int mean = 0;
    int count = 0;
    while (1)
    {
        int num;
        scanf("%d", &num);
        if (num == 0)
            break;
        mean += num;
        count++;
    }
    return mean / count;
}

int three()
{
    int max = 0;
    int max2 = 0;
    while (1)
    {
        int num;
        scanf("%d", &num);
        if (num == 0)
            break;
        if (num > max)
        {
            max2 = max;
            max = num;
        }
    }
    return max2;
}

int four(unsigned int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
            count++;
        n = n / 2;
    }
    return count;
}

int five(unsigned int n)
{
    int count = 0;
    while (n % 2 == 0)
    {
        count++;
        n = n / 2;
    }
    return count;
}

int six(unsigned int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}

char *seven(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    while (s1[i] != '\0')
    {
        i++;
    }
    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return s1;
}

char *eight(char *dest, char source[])
{
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int nine(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else if (s1[i] == '\0')
        return -1;
    else
        return 1;
}

char *ten(char s1[], char s2[])
{
    char *ret = NULL;
    int i, j, l;
    if (!(*s2))
        ret = s1;
    for (i = 0; s1[i] && !ret; i++)
    {
        if (s1[i] == *s2)
        {
            for (j = i, l = 0; s2[l] && s1[j] == s2[l]; j++, l++)
                ;
            if (!s2[l])
                ret = s1 + i;
        }
    }
    return ret;
}

void eleven(char s[]){
    int i , j = 0;
    for(i = 0; s[i] != '\0'; i++){
    }

    for(j = 0; j < i; j++, i--){
        swapW(&s[j], &s[i-1]);
    }
}

int isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}


void twelve(char s[]){
    int i, j = 0;
    for(i = 0; s[i] != '\0'; i++){
        if(isVowel(s[i])){
            for(j = i; s[j] != '\0'; j++){
                s[j] = s[j+1];
            }
            i--;
        }
    }
}

void thirteen(char t[], int n){
    int size = strlen(t);
    int i = 0;
    int counter = 0;

    for(i = 0; i < size ; i++){
        if(t[i] == '\0') break;
        if(t[i] == ' ')
        {
            counter = 0;
        }
        else if(counter >= n)
        {
            int j;
            for(j = i; j < size; j++)
            {
                if(j == size - 1)
                    t[j] = '\0';
                else
                    t[j] = t[j+1];
            }
            --i;
        }
        else{
            ++counter;
        }
    }
}

int freqC(char ch, char s[]) {
    int i, freq = 0;
    for(i = 0; s[i]; i++) {
        if(s[i] == ch) freq++;
    }
    return freq;
}

char fourteen (char s[]) {
    char maisFreq = 0;
    int i, freqMax = 0, freq;
    for(i = 0; s[i]; i++) {
        if((freq = freqC(s[i],s)) > freqMax) {
            freqMax = freq;
            maisFreq = s[i];
        }
    }
    return maisFreq;
}

int iguaisConsecutivos (char s[]){
    int i, max = 0 , count = 1;
    for(i = 0; s[i]; i++){
        if(s[i] == s[i+1]) count++;
        else{
            if (count > max) max = count;
            count = 1;
        }
    }
    return max;
}

int not_in_prev(char s[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(s[i] == s[n]) {
            return 0;
        }
    }
    return 1;
}

int difConsecutivos(char s[]) {
    int consec, difs = 0;
    size_t i, j;
    for(i = 0; s[i]; i++) {
        for(j = 0, consec = 0; s[i+j] && not_in_prev(s+i,j); j++, consec++);
        if (consec > difs) difs = consec;
    }
    return difs;
}

int maiorPrefixo(char s1[], char s2[]){
    int i;
    for(i = 0; s1[i] == s2[i] && s1[i]; i++);
    return i;
}

int maiorSufixo(char s1[], char s2[]){
    int size1,size2, max = 0;
    for(size1 = 0; s1[size1]!= '\0'; size1++);
    for(size2 = 0; s2[size2]!= '\0'; size2++);
    while(s1[--size1] == s2[--size2]) max++;
    return max;
}

int sufPref(char s1[], char s2[]){
    int n1,n2 = 0;
    for(int n1 = 0; s1[n1]; n1++){
        if(s1[n1] == s2[n2]) n2++;
        else n2 = 0; 
    }
    return n2;
}


int contaPal(char s[]){
    int i, inWord = 0, count = 0;
    for(i = 0; s[i]; i++){
        if (s[i] == ' '|| s[i] == '\n' || s[i] == '\t'){
            if(inWord) count++;
            inWord = 0;
        }
        else inWord = 1;
    }
    return count + inWord;
}

int isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int contaVogais(char s[]){
    int i , count = 0;
    for(i = 0; s[i]; i++){
        if(isVowel(s[i])) count++;
    }
    return count;
}

int contida (char a[], char b[]) {
    int i, j;
    int acc = 1, contemLetra;
    for(i = 0; a[i] && acc; i++) {
        contemLetra = 0;
        for(j = 0; b[j] && !contemLetra; j++)
            if (b[j] == a[i])
                contemLetra = 1;
        acc = contemLetra;
    }
    return acc;
}

int palindrome (char s[]) {
    int i, N = 0;
    for(i = 0; s[i]; i++) N++;
    for(i = 0; i < N && s[i] == s[N - i - 1]; i++);
    return i == N;
}




int main()
{
    char str[10] = "aaabbbbccc";
    printf("%c\n",fourteen(str));
    return 0;
}