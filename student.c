#include <time.h>

#include "lists/student_list.c"

void new_student(Student_list list){
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
    
    printf("Qual o seu regime?\n");
    regime(new.regime);
    append_student_wOrder(list, new);
}

void change_student_data(Student* change) {
    char answer, temp[50];
    int numb = -1; 

    printf("### Esta a querer alterar os dados de um aluno ###\n\n");
   
   
    // Numb
    printf("Este e o numero do aluno --> %d\n", (*change).numb);
    confirm_answer("O novo numero do aluno e\n-->", &(*change).numb, "0");
    
    // Course
    printf("Este e o curso do aluno --> %s\n", (*change).course);
    confirm_answer("O novo curso do aluno e\n-->", 0, (*change).course); 
    
    // Year
    printf("O aluno esta neste ano --> %d\n", (*change).year);
    confirm_answer("O novo ano do aluno e\n-->", &(*change).year, "0");

    // Regime 
    printf("Este e o regime do aluno --> %s\n", (*change).regime); 
    confirm_answer("O novo regime do aluno e", &numb, (*change).regime); 
}

void change_slist_data(Student_list head) {
    Student_list copy = head;
    int student_numb;
    char temp[50];
   
    printf("Que aluno deseja alterar?(n de aluno)\n");
    print_student_list(head);
    printf("-->");
    fgets(temp,50,stdin);
    student_numb = fgets_to_int(temp);
    
    while((head->data.numb != student_numb) && (head->next != NULL))
        head = head->next;
    if(head->data.numb != student_numb){
        printf("Nao existe ninguem com esse numero. Tente de novo.");
        change_slist_data(copy);
    }
    else
        change_student_data(&head->data);
}

void remove_student_data(Student_list head) {
    Student_list copy = head;
    int student_numb;
    char temp[50];
    
    printf("### ESTA A QUERER REMOVER UM ALUNO DA BASE DE DADOS ###\n\n");
    printf("Que aluno deseja remover?(n de aluno)\n)");
    print_student_list(head);
    printf("-->");
    fgets(temp,50,stdin);
    student_numb = fgets_to_int(temp);
    
    while((head->data.numb != student_numb) && (head->next != NULL))
        head = head->next;
    if(head->data.numb != student_numb){
        printf("Nao existe ninguem com esse numero. Tente de novo.");
        remove_student_data(copy);
    }
    else
        removes_from_student_list(copy, student_numb);
        printf("Aluno numero: %d foi retirado da base de dados\n\n", student_numb); 
}
    
