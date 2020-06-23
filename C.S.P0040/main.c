
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
int quaDratic(float a, float b, float c);
float bankDeposit(float t, float l, float m);

int main() {
    int choice;
    int number;
    int month;
    float a, b, c;
    float t;
    float l, m;
    float total;
    char buffer, s, p;
    int flag;
    do {
        do {
            menu();
            printf("\nSelect an option:");
            scanf("%d", &choice);
            scanf("%c", &buffer);
            fflush(stdin);
            if (buffer != 10) {
                printf("\nEnter again!");
            }
        } while (buffer != 10);
        switch (choice) {
            case 1:
                do {
                    flag = 0;
                    do {
                        printf("\nEnter a:");
                        scanf("%f", &a);
                        scanf("%c", &buffer);
                        fflush(stdin);
                        if (buffer != 10) {
                            printf("\n Enter a number.");
                            flag = 1;
                        } else if (a < 0) {
                            printf("\nPT vo nghiem! Ban hay nhap lai.");
                            flag = 1;
                        } else {
                            flag = 0;
                        }

                    } while (flag == 1);
                    do {
                        printf("\nEnter b:");
                        scanf("%f", &b);
                        scanf("%c", &s);
                        fflush(stdin);
                        if (s != 10) {
                            printf("\n Enter a number.");
                            flag = 1;
                        } else {
                            flag = 0;
                        }
                    } while (flag == 1);

                    do {
                        printf("\nEnter c:");
                        scanf("%f", &c);
                        scanf("%c", &p);
                        fflush(stdin);
                        if (p != 10) {
                            printf("\nEnter a number!");
                            flag = 1;
                        }
                    } while (flag == 1);

                    if (a == 0 && b == 0 && c == 0) {
                        printf("\n Nhap lai.");
                        flag = 1;
                    } else if ((a == 0) && (b == 0)) {
                        printf("\n Nhap lai.");
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                } while (flag != 0);
                quaDratic(a, b, c);
                break;
            case 2:
                do {
                    flag = 0;
                    do {
                        printf("\nEnter deposits: ");
                        scanf("%f", &t);
                        scanf("%c", &buffer);
                        fflush(stdin);
                        number = 0;
                        while (1) {
                            if (number > t) {
                                break;
                            }
                            number = number + 1;
                        }
                        number = number - 1;

                        if (t - number > 0) {
                            printf("\nMoney Error");
                            flag = 1;
                        } else if (buffer != 10) {
                            printf("\nEnter a positive number!");
                            flag = 1;
                        } else if (t < 0) {
                            printf("\n Enter a deposits is positive number > 0");
                            flag = 1;
                        } else {
                            flag = 0;
                        }
                    } while (flag == 1);

                    do {
                        printf("\nEnter deposits interest rates: ");
                        scanf("%f", &l);
                        scanf("%c", &s);
                        fflush(stdin);
                        if (s != 10) {
                            printf("\n Enter a positive number!");
                            flag = 1;
                        } else if (l - 0.1f > (float) 0) {
                            flag = 1;
                        } else {
                            flag = 0;
                        }


                    } while (flag == 1);
                    do {
                        printf("\nEnter months: ");
                        scanf("%f", &m);
                        scanf("%c", &p);
                        fflush(stdin);
                        month = 0;
                        while (1) {
                            if (month > m) {
                                break;
                            }
                            month = month + 1;
                        }
                        month = month - 1;
                        if (m - month > 0) {
                            printf("\nMonth Error");
                            flag = 1;
                        } else if (p != 10) {
                            printf("\nEnter a positive number!");
                            flag = 1;
                        } else if (m < 0) {
                            printf("\nEnter  months is positive number > 0");
                            flag = 1;
                        } else {
                            flag = 0;
                        }
                    } while (flag == 1);


                } while (flag != 0);

                total = bankDeposit(t, l, m);
                printf("\nReceived = %f", total);
                break;
            case 3:
                printf("\nQuit!");
                return 0;
                break;
            default:
                break;
        }
    } while (choice != 3);
    return 0;
}

void menu() {
    printf("\nMenu:");
    printf("\n1-Quadratic equation.");
    printf("\n2-Bank deposit problem.");
    printf("\n3-Quit.");
}

int quaDratic(float a, float b, float c) {
    float x;
    float x1;
    float x2;
    if (a == 0) {
        x = -c / b;
        printf("\nPhuong trinh co 1 nghiem: %f", x);
        return 0;
    }
    float d = b * b - 4 * a*c;
    if (d < 0) {
        printf("\nPT vo nghiem!");
    } else if (d == 0) {
        x1 = x2 = -b / (2 * a);
        printf("\nPt co nghiem kep la : %f", x1);
    } else {
        d = sqrt(d);
        x1 = (-b + d) / (2 * a);
        x2 = (-b - d) / (2 * a);
        printf("\nPT co 2 nghiem X1 = %f va X2 = %f", x1, x2);
    }
}

float bankDeposit(float t, float l, float m) {
    float total;
    total = t * l*m;
    return total;
}