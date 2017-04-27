int fgets_to_int(char *temp) {
    int i, numb, len = strlen(temp) - 1;
    for(i = 0; i < len; i++){
        if(!isdigit(temp[i]))
            return 1;
    }
    numb = atoi(temp);
    return numb;
}

void regime(char str[]) {
    char temp[50];

    printf("1.Normal\n2.Trabalhador-estudante\n3.Atleta\n4.Dirigente associativo\n5.Aluno de Erasmus\n-->");
    fgets(temp,50,stdin);
    switch(temp[0]) {
        case '1':
            strcpy(str, "Normal");
            break;
        case '2':
            strcpy(str, "Trabalhador-estudante");
            break;
        case '3':
            strcpy(str, "Atleta");
            break;
        case '4':
            strcpy(str, "Dirigente associativo");
            break;
        case '5':
            strcpy(str, "Aluno de Erasmus");
            break;
        default:
            printf("Wrong choice. Enter again.\n");
            regime(str);
    }
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
