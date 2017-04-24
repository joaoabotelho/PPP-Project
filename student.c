#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct student{
        int *numb;
        char course[50];
        int *year;
        char regime[50];
} Student;

Student new_student(){
        Student new;
        char temp[50];

        printf("### Esta a criar um novo aluno ###\n\n");
        printf("Qual e o numero de aluno?\n-->");
        fgets(temp,50,stdin);
        new.numb = fgets_to_int(temp); 

        printf("Que curso frequenta?\n-->");
        fgets(new.course,50,stdin);
        
        printf("Que ano frequenta?(1,2,3)\n-->");
        fgets(temp,50,stdin);
        new.year = fgets_to_int(temp);

        printf("Qual o seu regime?\n-->");
        fgets(new.regime,50,stdin);
        return new;
}

int fgets_to_int(char temp[]){
        int i, numb, len = strlen(temp) - 1;
        for(i = 0; i < len; i++){
                if(!isdigit(temp[i]))
                        return 1;
        }
        numb = atoi(temp);
        return numb;
}
/* WITH BUGGS
char check_answer(){
        char answer;
        printf("Pretende alterar(y/n)? ");
        scanf("%c", &answer);
        return answer;
} 

void change_data(Student std){
        char answer;
        printf("### Esta a querer alterar os dados de um aluno ###\n\n");
        // Numb
        printf("Este e o numero do aluno --> %d\n", std.numb);
        answer = check_answer();
        if(answer == 'y'){
                printf("O novo numero do aluno e\n-->");
                scanf("%d", &std.numb);
        }
        // Course
        printf("Este e o curso do aluno --> %s\n", std.course);
        answer = check_answer();
        if(answer == 'y'){
                printf("O novo curso do aluno e\n-->");
                scanf("%s", std.course);
        }
        // Year
        printf("O aluno esta neste ano --> %d\n", std.year);
        answer = check_answer();
        if(answer == 'y'){
                printf("O novo ano do aluno e\n-->");
                scanf("%d", &std.year);
        }
        // Regime 
        printf("Este e o regime do aluno --> %s\n", std.regime);
        answer = check_answer();
        if(answer == 'y'){
                printf("O novo regime do aluno e\n-->");
                scanf("%s", std.regime);
        }
}*/
