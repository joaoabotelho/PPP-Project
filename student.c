#include <time.h>

#include "lists/student_list.c"

void new_student(Student_list list){
    Student new;
    char temp[50];

    printf("### Esta a criar um novo aluno ###\n\n");
    printf("Qual e o numero de aluno?\n-->");
    fgets(temp,50,stdin);
    new.numb = fgets_to_int(temp); 
    //new.numb = 1 + rand() % 10;
    printf("Que curso frequenta?\n-->");
    fgets(new.course,50,stdin);
        
    printf("Que ano frequenta?(1,2,3)\n-->");
    fgets(temp,50,stdin);
    new.year = fgets_to_int(temp);
//    new.year = 1 + rand() % 3;
    printf("Qual o seu regime?\n-->");
    fgets(new.regime,50,stdin);
    append_student(list, new);
}

void change_student_data(Student* change){
    char answer, temp[50];
    printf("### Esta a querer alterar os dados de um aluno ###\n\n");
    // Numb
    printf("Este e o numero do aluno --> %d\n", (*change).numb);
    answer = check_answer();
    if(answer == 'y'){
        printf("O novo numero do aluno e\n-->");
        fgets(temp,50,stdin);
        (*change).numb = fgets_to_int(temp);
    }
    // Course
    printf("Este e o curso do aluno --> %s\n", (*change).course);
    answer = check_answer();
    if(answer == 'y'){
        printf("O novo curso do aluno e\n-->");
        fgets((*change).course,50,stdin);
    }
    // Year
    printf("O aluno esta neste ano --> %d\n", (*change).year);
    answer = check_answer();
    if(answer == 'y'){
        printf("O novo ano do aluno e\n-->");
        fgets(temp,50,stdin);
        (*change).year = fgets_to_int(temp);
    }
    // Regime 
    printf("Este e o regime do aluno --> %s\n", (*change).regime);
    answer = check_answer();
    if(answer == 'y'){
        printf("O novo regime do aluno e\n-->");
        fgets((*change).regime,50,stdin);
    }    
}

void change_list_data(Student_list head){
    Student_list node, copy = head;
    int student_numb;
    char temp[50];
    node = (Student_list) malloc (sizeof (Student_node));
   
    printf("Que aluno deseja alterar?(n de aluno)\n");
    print_student_list(head);
    printf("-->");
    fgets(temp,50,stdin);
    student_numb = fgets_to_int(temp);
    
    node->data.numb = student_numb;
    while(head->data.numb != node->data.numb)
        head = head->next;
    if(head->next == NULL){
        printf("Nao existe ninguem com esse numero. Tente de novo.");
        change_list_data(copy);
    }
    else
        change_student_data(&head->data);
}
