#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "lists/student_list.c"
#include "lists/class_list.c"
#include "lists/exam_list.c"
#include "base.c"
#include "student.c"
#include "classes.c"
#include "exams.c"

void exams_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam) {
    char choice[50];

    printf("\n\n$ EXAMS MENU $\n\t1.Crie um novo exame.\n\t2.Mostrar os exames.\n-->");
    fgets(choice,50,stdin);

    switch(choice[0]) {

        case '1': 
            create_exam(list_exam, list_class);
            break;
        case '2':
            print_exams_list(list_exam);
            break;
        default:
            printf("Wrong choice. Enter again.\n");
            exams_menu(list_student, list_class, list_exam);
    }  
}

void classes_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam) {
    char choice[50];

    printf("\n\n$ CLASSES MENU $\n");
    printf("\t1.Crie uma numa disciplina.\n\t2.Mude os dados de uma disciplina.\n\t3.Mostrar as disciplinas existentes.\n\t4.Remover uma disciplina da base de dados.\n-->");
    fgets(choice,50,stdin);

    switch(choice[0]) {

        case '1':
            new_class(list_class);
            break;
        case '2':
            change_clist_data(&list_class);
            break;
        case '3':
            print_classes_list(list_class);
            break;
        case '4':
            remove_class_data(list_class);
            break;
        default:
            printf("Wrong choice. Enter again.\n");
            classes_menu(list_student, list_class, list_exam);
    }  
}

void students_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam) {
    char choice[50];

    printf("\n\n$ STUDENTS MENU $\n");
    printf("\t1.Crie um novo aluno.\n\t2.Mude os dados de um aluno.\n\t3.Mostrar lista de alunos existentes.\n\t4.Remover um aluno da base de dados.\n-->");
    fgets(choice,50,stdin);

    switch(choice[0]) {

        case '1': 
            new_student(list_student);
            break;
        case '2': 
            change_slist_data(list_student);
            break;
        case '3':
            print_student_list(list_student);
            break;
        case '4':
            remove_student_data(list_student);
            break;
        default:
            printf("Wrong choice. Enter again.\n");
            students_menu(list_student, list_class, list_exam);
    }
}
void main_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam) {
    char choice[50];

    while(1) { 
        printf("@@@@@@      Welcome to this app      @@@@@@\n\n");
        printf("$ MENU $\t1. Students Menu\n");
        printf("        \t2. Classes Menu\n"); 
        printf("        \t3. Exams Menu\n-->");
        fgets(choice,50,stdin);

        switch(choice[0]) {
            case '1':
                students_menu(list_student, list_class, list_exam);
                break;
            case '2':
                classes_menu(list_student, list_class, list_exam);
                break;
            case '3':
                exams_menu(list_student, list_class, list_exam);
                break;
            default:
                printf("Wrong choice. Enter again.\n");
                break;
        } 
        main_menu(list_student, list_class, list_exam);
    }
}

int main() { 
    Student_list list_student = create_students_list();
    Classes_list list_class = create_classes_list();
    Exams_list list_exam = create_exams_list();

    main_menu(list_student, list_class, list_exam);

    return 0;
}
