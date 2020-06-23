

#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

void inputArray(float array[], int size);
void ascAAdd(float array[], float*size);

int main() {
    int number;
    float size;
    int flag;
    float array[NMAX];
    char buffer;
    do {
        flag = 0;
        printf("\nEnter size of array:");
        scanf("%f", &size);
        scanf("%c", &buffer);
        fflush(stdin);
        if (buffer != 10) {
            printf("\nEnter again!");
            flag = 1;
        }
        if(size < 0){
            printf("\nError!");
            flag = 1;
        }
        number = 0;
        while (1) {
            if (number > size) {
                break;
            }
            number = number + 1;
        }
        number = number - 1;

    } while (flag != 0);
    inputArray(array, (int) size);
    ascAAdd(array, &size);
    return 0;
}

void inputArray(float array[], int size) {
    char check;
    for (int i = 0; i <= size - 1; i++) {
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

void ascAAdd(float array[], float*size) {
    float tmp;
    for (int i = 0; i <= *size - 1; i++) {
        for (int j = i + 1; j <= *size - 1; j++) {
            if (array[i] > array[j]) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    printf("\nArray after sort ASC: ");
    for (int i = 0; i <= *size - 1; i++) {
        printf("%3.0f", array[i]);
    }
    float value;
    char buffer;
    do {
        printf("\nPlease enter new value:");
        scanf("%f", &value);
        scanf("%c", &buffer);
        fflush(stdin);
    } while (buffer != 10);
    *size = *size + 1;
    array[(int)*size - 1] = value;
    for (int i = 0; i <= *size - 1; i++) {
        for (int j = i + 1; j <= *size - 1; j++) {
            if (array[i] > array[j]) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    printf("\nNew array:");
    for (int i = 0; i <= *size - 1; i++) {
        printf("%3.0f", array[i]);
    }
}
