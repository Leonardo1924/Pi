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

int min(int a,int b){
    if (a < b) return a;
    else return b;
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

void tail(char* s){
    int i;
    for(i=0; s[i]; i++) s[i] = s[i+1];
}

int remRep(char x[]){
    int i;
    for(i = 0; x[i]; i++)
        while(x[i+1] == x[i]) tail(x+i+1);
    return i;
}

int limpaEspacos(char t[]){
    int i;
    for(i=0; t[i];i++)
        while(t[i] == ' ' && t[i+1] == t[i]) tail(t+i+1);
    return i;
}

void insere(int v[], int N, int x){
    int i,j, inserted = 0;
    for(i= 0; i < N && !inserted; i++){
        if (x < v[i]){
            for(j = N ; j > i; j--){
                v[j] = v[j-1];
            }
            v[i] = x;
            inserted = 1;
        }
    }
    if(!inserted) v[N] = x;
}

void merge(int r[], int a[], int b[], int na, int nb){
    int i = 0, j = 0;
    while( i + j < na + nb ){
        if(j== nb || a[i] < b[j]){
            r[i+1] = a[i];
            i++;
        }
        else{
            r[i+j] = b[j];
            j++;
        }
    }
}

int crescente (int a[], int i, int j){
    int k , cresc = 1;
    for(k = i; k < j && cresc; k++)
        if(a[k+1] < a[k]) cresc = 0;
    return cresc;
}

int retiraNeg(int v[], int N){
    int i,j;
    for(i = 0, j= 0; i < N ; i++){
        if(v[i] >= 0){
            v[j] = v[i];
            j++;
        }
    }
    return j;
}

int menosFreq(int v[], int N){
    int i, freq = 1, minFreq = N, ans = v[0];
    for(i = 1; i < N; i++){
        if(v[i] == v[i-1]) freq++;
        else{
            if(freq < minFreq){
                minFreq = freq;
                ans = v[i-1];
            }
            freq = 1;
        }
    }
    if(freq < minFreq){
        minFreq = freq;
        ans = v[i-1];
    }
    
    return ans;
}

int maisFreq (int v[], int N) {
    int i, freq = 1, maxFreq = 0, ans = v[0];
    for(i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        else {
            if(freq > maxFreq) {
                maxFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if(freq > maxFreq) {
        maxFreq = freq;
        ans = v[i - 1];
    }
    return ans;
}

int maxCresc(int v[], int N){
    int i, ans = 1, cres = 1;
    for(i = 1; i < N; i++){
        if(v[i] > v[i-1]) cres++;
        else{
            ans = max(ans, cres);
            cres = 1;
        }
    }
    return max(ans, cres);
}

int elimRep(int v[], int n) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n;) {
            if (v[j] == v[i]) {
                for (k = j; k < n - 1; k++) {
                    v[k] = v[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }
    return n;
}

int elimRepOrd (int v[], int n){
    int i, j;

    if(n== 0 || n == 1) return n;

    for(i = 0, j = 1; j < n; j++){
        if(v[j] != v[i]){
            i++;
            v[i] = v[j];
        }
    }
    return i+1;
}

int comunsOrd (int a[], int na, int b[], int nb){
    int i, j, count = 0;
    for(i = 0, j = 0; i < na && j < nb;){
        if(a[i] == b[j]){
            count++;
            i++;
            j++;
        }
        else if(a[i] < b[j]) i++;
        else j++;
    }
    return count;
}

int comuns (int a[], int na, int b[], int nb){
    int i, j, count = 0;
    for(i = 0; i < na; i++){
        for(j = 0; j < nb; j++){
            if(a[i] == b[j]){
                count++;
                break;
            }
        }
    }
    return count;
}

int minInd (int v[], int n){
    int i, min = v[0], minInd = 0;
    for(i = 1; i < n; i++){
        if(v[i] < min){
            min = v[i];
            minInd = i;
        }
    }
    return minInd;
}

void somasAC(int v[], int Ac[], int N){
    int i , acc = 0 ;
    for(i = 0; i < N ; i++){
        acc += v[i];
        Ac[i] = acc;
    }
}

int triSup (int N, int m [N][N]) {
    int i,j, istrip = 1;
    for(i = 0; i < N && istrip; i++){
        for(j = 0 ; j < i && istrip; j++){
            if(m[i][j] != 0)
                istrip = 0;
        }
    }
    return istrip;
}

void transposta (int N, float m[N][N]) {
    int i, j;
    float temp;
    for(i = 0; i < N;i++){
        for(j = 0; j < i; j++){
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

void addTo (int N, int M, int a [N][M], int b [N][M]){
    int i,j;
    for(i = 0; i < N;i++){
        for(j = 0; j < M; j++)
            a[i][j] += b[i][j];
    }
}

int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int i, len = 0;
    for(i = 0; i < N; i++){
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
    return len;
}

int interesectSet (int N, int v1[N], int v2[N], int r[N]){
    int i, len = 0;
    for(i = 0; i < N; i++){
        r[i] = v1[i] && v2[i];
        len += r[i];
    }
    return len;
}

int intersectMSet (int N, int v1[N] , int v2[N] , int r[N]){
    int i, len = 0;
    for(i = 0; i < N ; i++){
        r[i] = min(v1[i],v2[i]);
        len += r[i];
    }
    return len;
}

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i, len = 0;
    for(i = 0; i < N ; i++){
        r[i] = max(v1[i],v2[i]);
        len += r[i];
    }
    return len;
}

int cardinalMSet (int N, int v[N]){
    int i , len = 0;
    for(i = 0; i < N ; i++) len += v[i];
    return len;
}

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i = 0; i < N; i++){
        switch(mov[i]){
            case Norte:
                inicial.y++;
                break;
            case Oeste:
                inicial.x--;
                break;
            case Sul:
                inicial.y--;
                break;
            case Este:
                inicial.x++;
                break;
        }
    }
    return inicial;
}

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(inicial.x < final.x){
            mov[i] = Este;
            inicial.x++;
        }
        else if(inicial.x > final.x){
            mov[i] = Oeste;
            inicial.x--;
        }
        else if(inicial.y < final.y){
            mov[i] = Norte;
            inicial.y++;
        }
        else if(inicial.y > final.y){
            mov[i] = Sul;
            inicial.y--;
        }
        else break;
    }
    if(inicial.x == final.x && inicial.y == final.y) return i;
    else return -1;
}

int maisCentral (Posicao pos[], int N){
    int i, min = 1000000, minInd = 0;
    for(i = 0; i < N; i++){
        if(pos[i].x*pos[i].x + pos[i].y*pos[i].y < min){
            min = pos[i].x*pos[i].x + pos[i].y*pos[i].y;
            minInd = i;
        }
    }
    return minInd;
}

int vizinhos (Posicao p, Posicao pos[], int N){
    int i, count = 0;
    for(i = 0; i < N; i++){
        if(abs(pos[i].x - p.x) + abs(pos[i].y - p.y) == 1) count++;
    }
    return count;
}

int main()
{
    char str[10] = "aaabbbbccc";
    printf("%c\n",fourteen(str));
    return 0;
}