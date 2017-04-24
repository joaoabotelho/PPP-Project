typedef struct student{
        int numb;
        char *course;
        int year;
        char *regime;
} Student;

Student new_student(){
        Student new;
        printf("###Esta a criar um novo aluno###\n\n");
        printf("Qual e o numero de aluno?\n-->");
        scanf("%d", &new.numb);
        printf("Que curso frequenta?\n-->");
        scanf("%s", new.course); 
        printf("Que ano frequenta?(1,2,3)\n-->");
        scanf("%d", &new.year);
        printf("Qual o seu regime?\n-->");
        scanf("%s", new.regime);  
        return new;
}

void change_data(Student std){
        
