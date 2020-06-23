
#include <stdio.h>
#include <stdlib.h>

int convertBin(float n);

int main() {
    float n;
    int number;
    int b;
    int flag;
    char k;
    char buffer;
    do {
        do {
            printf("Convert Decimal to Binary program:\n");
            printf("Enter a positive number: ");
            scanf("%f", &n);
            scanf("%c", &buffer);
            fflush(stdin);
            if (buffer != 10 || n < 0) {
                printf("Error, Pls enter a positive number! \n");
            }
            number = 0;
            flag = 0;
            while(1){
                if(number > n){
                    break;
                }
                number+=1;
            }
            number = number - 1;
            if((n - number) > 0){
                printf("No, enter a integer!\n");
                flag = 0;
            }else{
                flag = 1;
            }
        } while ((buffer != 10) || (n < 0) || (flag != 1));
        b = convertBin(n);
        printf("Binary number: %d \n",b);
        printf("Press any key to do another conversion! \n");
        k = getchar();
    } while(1);
    return 0;
}

int convertBin(float n) {
    int tmp;
    int s = 0;
    int i = 1;
    while (n > 0) {
        tmp = (int)n % 2;
        s = s  + i*tmp;
        n = n / 2;
        i=i*10;
    }
    return s;
}

