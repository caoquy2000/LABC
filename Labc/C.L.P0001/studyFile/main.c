#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#define FILENAME "dictionary.txt"

int compareToString(char name[], char key[]);
int main()
{
    printf("\nWelcome to the Spell Checked!");
    printf("\nThe dictionary has been loaded");
        int choice;
    do{
     char *line_buf = NULL; //check xem chuoi co null khong. |*line_buf chua du lieu buffer duoc tra ve sau moi lan dung ham getline()
     //getline() lay hang do bien thanh chuoi tra ra dia chi cua ki tu dau tien cua chuoi
    size_t line_buf_size = 0; //lay do dai cua chuoi line buf
    int line_count = 0;

    int count = 0;
    ssize_t line_size;
    FILE *fp = fopen(FILENAME, "r");
    if (!fp)
    {
        fprintf(stderr, "Error! '%s'\n", FILENAME);
        return EXIT_FAILURE;
    }

    line_size = getline(&line_buf, &line_buf_size, fp);
    char key[30];

    printf("\nPlease enter the word you would like checked:  ");
    gets(key);
    strlwr(key);
    fflush(stdin);
    strcat(key,"\0");




    int flag = 0;
    char nameTmp[40];
    while (line_size >= 0){
        line_count++;

        char name[40];
        strcpy(name,line_buf);

        if(compareToString(name,key) == 1){
            flag = 1;
            strcpy(nameTmp,name);
        }
         //printf("size: %d , %s ", strlen(name) ,line_buf);
        //check
        char *first;
        first = strstr(name, key);
        if (first != NULL)
        {
                printf("size: %d , %s ", strlen(name) ,line_buf);
              count++;
        }
        line_size = getline(&line_buf, &line_buf_size, fp);
    }


    fclose(fp);





    if(flag == 1){
        printf("\nGreat, %s is in the dictinary! ",key);

    }else if(count == 0){
        printf("\nNo, Cannot find.");
    }else{
        //reset
        *line_buf = NULL; //check xem chuoi co null khong. |*line_buf chua du lieu buffer duoc tra ve sau moi lan dung ham getline()
        //getline() lay hang do bien thanh chuoi tra ra dia chi cua ki tu dau tien cua chuoi
        line_buf_size = 0; //lay do dai cua chuoi line buf
        line_count = 0;


        ssize_t line_size;
        FILE *fp = fopen(FILENAME, "r");
        line_size = getline(&line_buf, &line_buf_size, fp);
        printf("\nHere are the possible words you could have meant:");
        while (line_size >= 0){
            line_count++;

            char name[40];
            strcpy(name,line_buf);

            //check
            char *first;
            first = strstr(name, key);
            if (first != NULL)
            {
                printf(" %s " ,line_buf);
            }
            line_size = getline(&line_buf, &line_buf_size, fp);
        }
    }
    //free(line_buf);
    //line_buf = NULL;


        fclose(fp);
        char charTmp[40];
        do{
            printf("\nWould you like to enter another word?  (yes/no)");

            gets(charTmp);
            fflush(stdin);
            strlwr(charTmp);
            if(strcmp(charTmp,"yes") != 0 && strcmp(charTmp,"no") != 0){
                printf("\nEnter again");
            }
        }while(strcmp(charTmp,"yes") != 0 && strcmp(charTmp,"no") != 0);
        if(strcmp(charTmp,"yes") == 0){
            choice = 0;
        }else{
            choice = 1;
        }
    }while(choice == 0);

    return EXIT_SUCCESS;

}

int compareToString(char name[], char key[]){
    if((strlen(name) - 1)== strlen(key)){
        for(int i = 0 ; i<= strlen(key) - 1; i++){
            if(key[i] != name[i]){
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}
//zabad
//012345
//zabad\0

