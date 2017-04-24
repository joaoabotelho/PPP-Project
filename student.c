typedef struct student{
        int *numb;
        char *course;
        int *year;
        char *regime;
} Student;

Student new_student(){
        Student new;
        printf("### Esta a criar um novo aluno ###\n\n");
        printf("Qual e o numero de aluno?\n-->");
        scanf("%d", new.numb);
        printf("Que curso frequenta?\n-->");
        scanf("%s", new.course);
        printf("Que ano frequenta?(1,2,3)\n-->");
        scanf("%d", new.year);
        printf("Qual o seu regime?\n-->");
        scanf("%s", new.regime);  
        return new;
}
char check_answer(){
        char answer;
        printf("Pretende alterar(y/n)? ");
        scanf("%s", &answer);
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
}
