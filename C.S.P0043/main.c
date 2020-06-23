
#include <stdio.h>
#include <stdlib.h>
#define NMAX 1000
#define ASC 100
#define DESC 100


void menu();
void add(int array[], int*size);
void searchValue(int array[], int size);
void showArray(int array[], int size);
int posRemove(int array[], int size, int value);

void removeElement(int array[], int*size, int pos);

void Asc(int array[], int size);
void Desc(int array[], int size);

int main() {
    int array[NMAX] = {-7, 5, 5, 2, 2, 8, -1, 7};
    int asc[ASC];
    int desc[DESC];
    int choice;
    int check;
    int value;
    char buffer;
    int pos;
    int size = 8;
    int m;
    do {
        do {
            menu();
            printf("\n Input your choice: ");
            scanf("%d", &choice);
            scanf("%c", &buffer);
            if (buffer != 10) {
                printf("Enter again! \n");
            }
        } while (buffer != 10);
        switch (choice) {
            case 1:
                add(array, &size);
                break;
            case 2:
                searchValue(array, size);
                break;
            case 3:
                printf("\nEnter value :");
                scanf("%d",&value);
                fflush(stdin);
                pos = posRemove(array, size,value);
                if (pos == -1) {
                    printf("\nFinish");
                } else {
                    removeElement(array, &size, pos);
                }
                printf("\n Array after remove first:");
                for(int i = 0; i<=size-1;i++){
                    printf("%2d",array[i]);
                }
                break;
            case 4:
                printf("\nEnter value :");
                scanf("%d",&value);
                fflush(stdin);
                while (1) {
                    check = posRemove(array, size, value);
                    if (check == -1) {
                        printf("\nFinish");
                        break;
                    } else {
                        removeElement(array, &size, check);
                    }
                }
                printf("\n Array after remove all:");
                  for(int i = 0; i<=size-1;i++){
                    printf("%2d",array[i]);
                }
                break;
            case 5:
                showArray(array, size);
                break;
            case 6:
                Asc(array, size);
                break;
            case 7:
                Desc(array, size);
                break;
            default:
                printf("Quit\n");
        }
    } while (choice>=1 && choice <=7);
    return 0;
}

void menu() {
    printf("\nMenu:\n");
    printf("1-Add a value.\n");
    printf("2-Search a value. \n");
    printf("3-Remove the first existence of a value. \n");
    printf("4-Remove all existences of a value. \n");
    printf("5-Print out the array. \n");
    printf("6-Sort the array in ascending order(positions of element are preserved).\n");
    printf("7-Sort the array in descending order (positions of element are preserved).\n");
    printf("Others-Quit.\n");
}

void add(int array[], int*size) {
    printf("\n Add:");
    scanf("%d", &array[*size]);
    fflush(stdin);
    *size = *size + 1;
}

void searchValue(int array[], int size) {
    int value;
    printf("\n Enter a value:");
    scanf("%d", &value);
    printf("\nPos of value:");
    for (int i = 0; i <= size - 1; i++) {
        if (value == array[i]) {
            printf("%2d", i);
        }
    }
}

int posRemove(int array[], int size, int value) {
    for (int i = 0; i <= size - 1; i++) {
        if (value == array[i]) {
            return i;
        }
    }
    return -1;
}

void removeElement(int array[], int*size, int pos) {
    for (int i = pos; i <= *size - 1; i++) {
        array[i] = array[i + 1];
    }
    *size = *size - 1;
}

void showArray(int array[], int size) {
    if (size == 0) {
        printf("\n Nothing to print!");
    } else {
        printf("\n Array:");
        for (int i = 0; i <= size - 1; i++) {
            printf("%2d", array[i]);
        }
    }
}

void Asc(int array[], int size) {
    int asc[ASC];
    int j = 0;
    int tmp;
    for (int i = 0; i <= size - 1; i++) {
        asc[j] = array[i];
        j++;
    }
    printf("\nArray before sort ASC:");
    for (int k = 0; k <= j - 1; k++) {
        printf("%2d", asc[k]);
    }
    for (int i = 0; i <= size - 1; i++) {
        for (int m = i + 1; m <= size; m++) {
            if (asc[i] > asc[m]) {
                tmp = asc[i];
                asc[i] = asc[m];
                asc[m] = tmp;
            }
        }
    }
    printf("\nArray after sort ASC:");
    for (int i = 0; i <= j - 1; i++) {
        printf("%2d", asc[i]);
    }
}

void Desc(int array[], int size) {
    int desc[DESC];
    int j = 0;
    int tmp;
    for (int i = 0; i <= size - 1; i++) {
        desc[j] = array[i];
        j++;
    }
    printf("\nArray before sort ASC:");
    for (int k = 0; k <= j - 1; k++) {
        printf("%2d", desc[k]);
    }
    for (int i = 0; i <= size - 1; i++) {
        for (int m = i + 1; m < size; m++) {
            if (desc[i] < desc[m]) {
                tmp = desc[i];
                desc[i] = desc[m];
                desc[m] = tmp;
            }
        }
    }
    printf("\nArray after sort ASC:");
    for (int i = 0; i <= j - 1; i++) {
        printf("%2d", desc[i]);
    }

}