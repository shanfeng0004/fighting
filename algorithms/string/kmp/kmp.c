#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GenNextArray(char* p, int next[])
{
    int len = strlen(p);
    next[0] = -1;
    int j = -1;
    int i = 0;

    while (i < len-1) {
        //p[j]表示前缀，p[i]表示后缀 
        if (j == -1 || p[i] == p[j]) {
            i++;
            j++;
            if (p[i] != p[j]) {
                next[i] = j;
            } else {
                next[i] = next[j];
            }
        } else {
            j = next[j];
        }
    }
}

int KmpSearch(char* s, char* p)
{
    int i = 0;
    int j = 0;
    int leni = strlen(s);
    int lenj = strlen(p);

    int* next = (int*)malloc(lenj*sizeof(int));
    GenNextArray(p, next);

    printf("next array:\n");
    for (int k = 0; k < lenj; k++) {
        printf("%d\t", next[k]);
    }
    printf("\n");
    
    while (i < leni && j < lenj) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    if (j == lenj) {
        free(next);
        return i - j; 
    } else {
        free(next);
        return -1;
    }
}

int main()
{
    char* s = "substring searching algorithm";
    char* p = "search";
    int pos = KmpSearch(s, p);
    printf("Find p in s begin at %d\n", pos);

    return 0;
}
