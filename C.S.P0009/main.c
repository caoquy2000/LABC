#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

void inputArray(float array[], int n);
int findMin(float array[],int n);
void pos(float array[], int n);
int main() {
    float n;
    int number;
    char buffer;
    int min;
    float array[NMAX];
    int flag;
    do {
        do {
            printf("\nEnter size of array:");
            scanf("%f", &n);
            scanf("%c", &buffer);
            fflush(stdin);
            if ((buffer != 10) || (n < 0)) {
                printf("\n Error!");
            }else if(n == 0){
                printf("\n Enter a number > 0");
            }
        } while (buffer != 10 || n < 0 || n==0);
        number = 0;
        flag = 0;
        while(1) {
            if (number > n) {
                break;
            }
            number += 1;
        }
        number = number - 1;
        if (n - number > 0) {
            printf("Error!\n");
            flag = 0;
        } else {
            flag = 1;
        }
    } while (flag != 1);

    inputArray(array, n);
    min = findMin(array, n);
    printf("Element min off array: %d\n", min);
    pos(array, n);
    return 0;
}

void inputArray(float array[], int n) {
    char check;
    for (int i = 0; i <= n - 1; i++) {
        do {
            printf("\n array[%d]=", i);
            scanf("%f", &array[i]);
            scanf("%c", &check);
            fflush(stdin);
            if (check != 10) {
                printf("Error!");
            }
        } while (check != 10);
    }
}
int findMin(float array[],int n){
    float min;
    min = array[0];
    for(int i = 1 ; i <= n-1; i++){
        if(min > array[i]){
            min = array[i];
        }
    }
    return min;
}
void pos(float array[], int n){
    float min = findMin(array,n);
    printf("\n Pos: ");
    for(int i = 0; i < n; i++){
        if(array[i] == min){
            printf("%2d", i);
        }
    }
}