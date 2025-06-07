#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hashsize 16

int scrollup(int what, int upto) {
    while (1) {
        if (what > upto)
            what -= upto;
        else
            break;
    }
    return what;
}

char* mkhashcode(char* seed) {
    int i; int j;
    char* out;
    out = malloc(hashsize);
    j = 0;
    for (i = 0; i < hashsize; i++) {
        out[i] = scrollup((int)((((seed[scrollup(i, strlen(seed))] + 10) * 2) + out[i]) * 0.25), 127);
        j += 1;
        if (i == hashsize - 1 && j < (int)strlen(seed)) i = -1;
    }
    return out;
}

void print(char* hex) {
    int i;
    printf("0x");
    for (i = 0; i < (int)strlen(hex); i++) {
        printf("%02X", hex[i]);
    }
    printf("\n");
}

int main() {
    char* seed = malloc(1024);
    char* hashcode;
    printf("Enter a seed: ");
    scanf("%s", seed);
    hashcode = mkhashcode(seed);
    printf("Result: ");
    print(hashcode);
    free(hashcode);
    return 0;
}