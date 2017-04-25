#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int fgets_to_int(char temp[]){
    int i, numb, len = strlen(temp) - 1;
    for(i = 0; i < len; i++){
        if(!isdigit(temp[i]))
            return 1;
    }
    numb = atoi(temp);
    return numb;
}
/*
char* check_answer(){
        char *answer;
        printf("Pretende alterar(y/n)? ");
        scanf("%s",&answer);
        return answer;
}
*/

