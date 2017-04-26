int fgets_to_int(char *temp) {
    int i, numb, len = strlen(temp) - 1;
    for(i = 0; i < len; i++){
        if(!isdigit(temp[i]))
            return 1;
    }
    numb = atoi(temp);
    return numb;
}

char check_answer() {
    char answer[50];
    printf("Pretende alterar(y/n)? ");
    fgets(answer,50,stdin);
    return answer[0];
} 

void confirm_answer(char print[], int *numb, char str[]) {
    char answer = check_answer(), temp[50];
    if(answer == 'y') {
        printf("%s", print);
        if(numb != 0) {
            fgets(temp,50,stdin);
            *numb = fgets_to_int(temp);
        }
        else{
            fgets(temp,50,stdin);
            strcpy(str, temp); 
        }
    }
}
