int fgets_to_int(char temp[]){
    int i, numb, len = strlen(temp) - 1;
    for(i = 0; i < len; i++){
        if(!isdigit(temp[i]))
            return 1;
    }
    numb = atoi(temp);
    return numb;
}

char check_answer(){
    char answer[50];
    printf("Pretende alterar(y/n)? ");
    fgets(answer,50,stdin);
    return answer[0];
} 


