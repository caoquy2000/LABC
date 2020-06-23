

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 10000
#define MAX 10000

int findElementDup(char s[], char k[], int *length, int len);
void removeDup(char s[], int*length, int pos);
void findDup(char s[], char k[], int*len, int length);
int find(char k[], int len, int index);


int main() {
    int length;
    int flag;
    int m;
    int len, l;
    int check;
    char s[NMAX];
    char k[MAX];
    do {
        flag = 0;
        printf("\nPlease enter a string:");
        fgets(s, NMAX, stdin);
        strlwr(s);
        length = strlen(s);
        len = 0;
        findDup(s, k, &len, length);
        for (int i = 0; i <= length - 1; i++) {
            while (1) {
                l = find(k, len, i);
                if (l == -1) {
                    break;
                } else {
                    removeDup(k, &len, l);
                }
            }
        }
        while (1) {
            check = findElementDup(s, k, &length, len);

            if (check == -1) {
                break;
            } else {
                removeDup(s, &length, check);
            }
        }
        printf("\nPound characters:");
        for (int i = 0; i <= length; i++) {
            printf("%5c", s[i]);
        }
        printf("\nPress enter to continue, ESC to exit.");
        m = getch();
    } while(m!=27);
    return 0;
}

void findDup(char s[], char k[], int*len, int length) {
    int h = 0;
    for (int i = 0; i <= length - 1; i++) {
        for (int j = i + 1; j <= length - 1; j++) {
            if (s[i] == s[j]) {
                k[h] = s[i];
                h++;
                *len = *len + 1;
            }
        }
    }
}

int findElementDup(char s[], char k[], int *length, int len) {
    for (int i = 0; i <= *length - 1; i++) {
        for (int j = 0; j <= len - 1; j++) {
            if (s[i] == k[j]) {
                return i;
            }
        }
    }
    return -1;
}

void removeDup(char s[], int*length, int pos) {
    for (int i = pos; i <= *length - 1; i++) {
        s[i] = s[i + 1];
    }
    *length = *length - 1;
}


int find(char k[], int len, int index) {
    for (int i = index + 1; i <= len - 1; i++) {
        if (k[index] == k[i]) {
            return i;
        }
    }
    return -1;
}
