
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* myStrcat(char firstString[], char secondString[]);
int myStrcmp(char* firstString, char* secondString);
char* myStrcpy(char coppyy[], char *string);
char* myStrncpy(char *firstString, char *secondString, size_t size);
char* myStrstr(char *firstString, char *secondString);
char* myStrchr(char *firstString, int ch);
int myStrlen(char *String);

int main() {
    //       char str[80];
    //        strcpy(str,"these ");
    //        strcat(str, "strings ");
    //        strcat(str, "are ");
    //        strcat(str, "concatenated. ");
    //        puts(str);
    //        
    //        char mstr[80];
    //        myStrcpy(mstr,"these ");
    //        myStrcat(mstr, "strings ");
    //        myStrcat(mstr, "are ");
    //        myStrcat(mstr, "concatenated. ");
    //        puts(mstr);

    //        char key[] = "apple";
    //        char keyb[] = "";
    //        char keyc[] = "apple";
    //        char keyd[] = "A";
    //        char buffer[80];
    //        char keye[] = "0";
    //        printf("%d\n",strcmp(key,keyb));
    //        printf("%d\n",strcmp(key,keyc));
    //        printf("%d\n",strcmp(key,keyd));
    //        printf("%d\n\n",strcmp(key,keye));
    //        
    //        printf("%d\n",myStrcmp(key,keyb));
    //        printf("%d\n",myStrcmp(key,keyc));
    //        printf("%d\n",myStrcmp(key,keyd));
    //        printf("%d\n",myStrcmp(key,keye));
    //
    //        char str1[] = "Sample string";
    //        char str2[40];
    //        char str3[40];
    //        strcpy(str2, str1);
    //        strcpy(str3, "copy successful");
    //        printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
    //    
    //        char str4[] = "Sample string";
    //        char str5[40];
    //        char str6[40];
    //        myStrcpy(str5, str4);
    //        myStrcpy(str6, "copy successful");
    //        printf("str4: %s\nstr5: %s\nstr6: %s\n", str4, str5, str6);

    //        char str1[] = "To be or not to be";
    //        char str2[40];
    //        char str3[40];
    //        strncpy(str2,str1, sizeof(str2));
    //        strncpy(str3,str2,5);
    //        str3[5] = '\0';
    //        puts(str1);
    //        puts(str2);
    //        puts(str3);
    //           printf("\n");
    //        
    //        char mstr1[] = "To be or not to be";
    //        char mstr2[40];
    //        char mstr3[40];
    //        myStrncpy(mstr2,mstr1, sizeof(mstr2));
    //        myStrncpy(mstr3,mstr2,5);
    //        mstr3[5] = '\0';
    //        puts(mstr1);
    //        puts(mstr2);
    //        puts(mstr3);


//            char str[] = "This is a simple string";
//            char * pch;
//            pch = strstr (str,"simple");
//            puts(pch);
//            strncpy(pch,"sample",6);
//            puts(pch);
//            puts(str);
//            
//    char mstr[] = "This is a simple string";
//    char * mpch;
//    mpch = myStrstr(mstr, "simple");
//    puts(mpch);
//    myStrncpy(mpch, "sample", 6);
//    puts(mpch);
//    puts(mstr);
            
//            
    char ch[50];
    char a[] = "ao";
    myStrncpy(ch, a,2);
    printf("\n%s\n", ch);

    return 0;
}

int myStrlen(char *String) {
    int length = 0;
    while (*String != '\0') {
        length++;
        String++;
    }
    return length;
}

char* myStrcat(char firstString[], char secondString[]) {
    int f = myStrlen(firstString);
    int s = myStrlen(secondString);
    int length = f + s;
    int j = 0;
    for (int i = f; i <= length; i++) {
        firstString[i] = secondString[j];
        f++;
        j++;
    }
}

int myStrcmp(char* firstString, char* secondString) {
    int i;
    int l = myStrlen(firstString);
    int s = myStrlen(secondString);
    int c;
    int count = 0;
    if (l == 0 && s == 0) {
        return 0;
    } else if (l == s) {
        for (int j = 0; j <= s - 1; j++) {
            if (firstString[j] == secondString[j]) {
                count = count + 1;
            }
        }
        if (count == s) {
            return 0;
        }
    } else {
        for (i = 0; i <= l; i++) {
            if (firstString[i] != secondString[i]) {
                c = firstString[i] - secondString[i];
                break;
            }
        }
    }
    if (c >= 1) {
        return 1;
    } else if (c <= -1) {
        return -1;
    } else if (c == 0) {
        return 0;
    }

}

char* myStrcpy(char* coppyy, char *string) {
    int j = 0;
    int k = myStrlen(string);
    for (int i = 0; i <= k; i++) {
        coppyy[j] = string[i];
        j++;
    }
}

char* myStrncpy(char *firstString, char *secondString, size_t size) {
    char * ptr = firstString;
//    printf("%d",myStrlen(firstString));
    while (*secondString != '\0' && size != 0) {
        *firstString = *secondString;
        firstString++;
        secondString++;
        size--;
        printf("\n%d\n",size);
    }
     printf("\n%d\n",myStrlen(firstString));
    if(myStrlen(firstString) == myStrlen(secondString)){
        *firstString = '\0';
    }
    return ptr;
}


char* myStrstr(char *firstString, char *secondString) {
    //    int f = myStrlen(firstString);
    //    int s = myStrlen(secondString);
    //    printf("\n%d  %d\n",f,s);
    //    if(*secondString == '\0' || s==0) return firstString;
    //    if(*firstString =='\0' || s > f) return NULL;
    //    int next[s+1];
    //    for(int i = 0;i < s + 1; i++){
    //        next[i] = 0;
    //    }
    ////    printf("\n%s",*next);
    //    for(int i = 1; i < s; i++){
    //        int j = next[i+1];
    //        while(j>0 && secondString[j] != secondString[i]){
    //            j = next[j];
    //        }
    //        if(j > 0 || secondString[j] == secondString[i]){
    //            next[i+1] = j+1;
    //        }
    //    }
    //    for(int i = 0, j = 0; i<f; i++){
    //        if(*(firstString+i)==*(secondString+j)){
    //            if(++j == s){
    //                return (firstString+i-j+1);
    //            }
    //        }else if(j>0){
    //            j = next[j];
    //            i--;
    //        }
    //    }
    //    return NULL;
    int f = myStrlen(firstString);
    int s = myStrlen(secondString);
    int flag;
    int r = 0;
    char * tmp = (char*) calloc(100, sizeof (char));
    if (f == 0 && s == 0) {
        return NULL;
    } else if (f > 0 && s == 0) {
        return firstString;
    } else if (s > f) {
        return NULL;
    } else {
        int j = 0;
        for (int i = 0; i < f; i++) {
//            printf("\nF:%c\n",firstString[10]);
//            printf("\nS:%c\n",secondString[j]);
            if (firstString[i] == secondString[j]) {
                int t = 0;
                t = i;
                do {
                    flag = 0;
                    t++;
                    j++;
                    if (j == s) {
//                        printf("\n%d\n",i);
                        for (int k = i; k < f; k++) {
                            tmp[r] = firstString[k];
                            r = r + 1;
                        }
                        tmp[r] = '\0';
                        return tmp;
                    }
                    if (firstString[t] == secondString[j]) {
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                } while (flag == 1);
                j--;
                //                for(int k = i; k < f; k++ )
                //                {
                //                    tmp[r] = firstString[k];
                //                    r = r + 1;
                //                }
                //                tmp[r] = '\0';
                //                return tmp;
            }

        }
        return NULL;
    }

}

char* myStrchr(char *firstString, int ch) {
    char MLOC[100];

    int j = 0;
    char*str;

    for (int i = 0; i <= myStrlen(firstString) - 1; i++) {
        if (firstString[i] == ch) {
            for (i; i <= myStrlen(firstString) - 1; i++) {
                MLOC[j] = firstString[i];
                j++;
            }
            MLOC[j] = '\0';
            str = (char*) calloc(100, sizeof (char));
            str = MLOC;
            //            free(str);
            return str;
        }
    }
    return NULL;
} 