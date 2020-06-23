
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100

char* lTrim(char s[]); //Xoa nhung khoang trang dau cua chuoi
char* rTrim(char s[]); //Xoa nhung khoang trang sau chuoi
char* trim(char s[]); //Xoa nhung khoang trang thua giua cac ki tu
char* nameStr(char s[]); //Viet hoa chu dau tien

int checkNum(char s);
int checkAlpha(char s);
int checkSpace(char s);

int main() {
    char s[NMAX];
    int len;
    int i;
    char k;
    do {
        int flag;
        do {
            flag = 0;
            printf("\nEnter a string:");
            fgets(s, NMAX, stdin);
            len = strlen(s);
            for (i = 0; i <= len - 1; i++) {
                if (!checkNum(s[i]) && !checkAlpha(s[i]) && !checkSpace(s[i]) && s[i] != 10) {
                    printf("Something wrong, enter again!");
                    flag = 1;
                    break;
                }
            }
        } while (flag);
        lTrim(s);
        rTrim(s);
        trim(s);
        //        nameStr(s);
        printf("String after:");
        puts(s);
        printf("Enter to continue, Esc to exit");
        k = getch();
    } while (k != 27);
    return 0;
}

char* lTrim(char s[]) {
    int i = 0;
    while (s[i] == ' ')i++;
    if (i > 0) strcpy(&s[0], &s[i]);
    return s;
}

char* rTrim(char s[]) {
    int i = strlen(s) - 1;
    while (s[i] == ' ') i--;
    s[i + 1] = '\0';
    return s;
}

char* trim(char s[]) {
    rTrim(lTrim(s));
    char *ptr = strstr(s, "  ");
    while (ptr != NULL) {
        strcpy(ptr, ptr + 1);
        ptr = strstr(s, "  ");
    }
    return s;
}

//char* nameStr(char s[]) {
//    int L = strlen(s);
//    int i;
//    for (i = 0; i <= L - 1; i++) {
//        if (i == 0) {
//            s[0] = toupper(s[0]);
//        }
//    }
//    return s;
//}

int checkNum(char s) {
    return s >= '0' && s <= '9';
}

int checkAlpha(char s) {
    return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
}

int checkSpace(char s) {
    return s == ' ';
}






