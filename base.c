int fgets_to_int(char *temp) {
    int i, numb, len = strlen(temp) - 1;
    for(i = 0; i < len; i++){
        if(!isdigit(temp[i]))
            return 1;
    }
    numb = atoi(temp);
    return numb;
}

void fgets_int(int *numb) {
    char temp[50];
    fgets(temp,50,stdin);
    *numb = fgets_to_int(temp);
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
        if(numb == 0) {
            fgets(temp,50,stdin);
            strcpy(str, temp); 
        }
        else if(*numb == -1) {
            regime(str);
        }
        else{
            fgets(temp,50,stdin);
            *numb = fgets_to_int(temp);
        }
    }
}

void time_of_exam(Time *time, int n, int hour, int minutes) {
    Time time_available[n];
    int i;
    
    possible_hours(time_available, n, hour, minutes);
    printf("\tHoras disponiveis:\n\n");
    for (i = 0; i < n; i++) {
        printf("\t\t%d.\t%d : %d\n", i+1, time_available[i].hour, time_available[i].minutes);
    }

    fgets_int(&i);
    (*time).hour = time_available[i-1].hour;
    (*time).minutes = time_available[i-1].minutes;
}


