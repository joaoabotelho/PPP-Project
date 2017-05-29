#include "header.h"

/* check_memory_char checks if string equals NULL
 * if it is NULL the whole program stops because its a sign of no dynamic memory */
void check_memory_char(char *string) {
    if(!string) { 
        printf("No memory\n");
        exit(0);
    } 
}

/* check_memory_int checks if numb equals NULL
 * if it is NULL the whole program stops because its a sign of no dynamic memory */
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
            return 0;
    }
    numb = atoi(temp);

    return numb;
}

/* Gets the value of numb(int) from a fgets */
void fgets_int(int *numb) {
    char *temp = (char*)malloc(CHAR_SIZE * sizeof(char));
    check_memory_char(temp);

    fgets(temp, CHAR_SIZE, stdin);
    *numb = fgets_to_int(temp);
    free(temp);
}

/* yes or no question to confirm if user wants to change something */
char check_answer() {
    char *temp = (char*)malloc(CHAR_SIZE * sizeof(char));
    char answer;

    check_memory_char(temp);
    printf("Pretende alterar(y/n)? ");
    fgets(temp, CHAR_SIZE ,stdin);
    answer = temp[0];
    free(temp);

    return answer;
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

/* Asks the user for the current Date */
void ask_for_the_current_date(int *month, int *day) {
    do {
        printf("Mes actual\n-->");
        fgets_int(month);
    } while(*month < 1 || *month > 12);

    do {
        printf("Dia actual\n-->");
        fgets_int(day);
    } while(*day < 1 || *day > max_day(CURRENT_YEAR, *month));
}
