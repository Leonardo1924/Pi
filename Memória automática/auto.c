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

char fourteen(char s[]){
    if (*s == '\0') return '\0';
    int morefreq = 0;
    int count = 1;
    char t = '\0';
    for (int i = 0; s[i] != '\0'; i++){
        if(s[i] == s[i+1]){
            count++;
        }
        else{
          if(count > morefreq){
            morefreq = count;
            t = s[i];
          }
          count = 1;
        }
    }
    return t;
}






int main()
{
    char str[10] = "aaabbbbccc";
    printf("%c\n",fourteen(str));
    return 0;
}