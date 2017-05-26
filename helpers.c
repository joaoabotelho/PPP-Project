#include "header.h"

void check_memory_char(char *string) {
    if(!string) { 
        printf("No memory\n");
        exit(0);
    } 
}

void check_memory_int(int *numb) {
    if(!numb) { 
        printf("No memory!\n");
        exit(0);
    } 
}

/* Transforms the char of fgets to int */
int fgets_to_int(char *temp) {
    int i, numb, len = strlen(temp) - 1;

    for(i = 0; i < len; i++) {
        if(!isdigit(temp[i]))
            return 1;
    }
    numb = atoi(temp);

    return numb;
}

/* Gets the value of numb(int) from a fgets */
void fgets_int(int *numb) {
    char *temp = (char*)malloc(CHAR_SIZE * sizeof(char));

    fgets(temp, CHAR_SIZE, stdin);
    *numb = fgets_to_int(temp);
    free(temp);
}

/* yes or no question to confirm if user wants to change something */
char check_answer() {
    char *answer = (char*)malloc(CHAR_SIZE * sizeof(char));

    printf("Pretende alterar(y/n)? ");
    fgets(answer, CHAR_SIZE ,stdin);

    return answer[0];
} 

/* Used in classes.c and student.c to print a desired string and 
change the desired data */
void confirm_answer(char print[], int *numb, char str[]) {
    char answer = check_answer();
    char *temp = (char*)malloc(CHAR_SIZE * sizeof(char));

    if(answer == 'y') {
        printf("%s", print);

        if(numb == 0) {
            fgets(temp, CHAR_SIZE, stdin);
            strcpy(str, temp); 

        } else if(*numb == -1) {
            regime(str);

        } else{
            fgets(temp, CHAR_SIZE, stdin);
            *numb = fgets_to_int(temp);
        }
    }
    free(temp);
}
