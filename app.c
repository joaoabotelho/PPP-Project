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

        printf("$ MENU $\t1.Crie um novo exame.\t2.Mostrar os exames.\n");
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

void main_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam) {
    char choice[50];

    while(1) { 
        printf("@@@@@@      Welcome to this app      @@@@@@\n\n");
        printf("$ MENU $\t1.Crie um novo perfil estudante.\t2.Mude os dados de um estudante.\t3.Mostrar a lista de estudantes.\t4.Remover um estudant da base de dados.\n");
        printf("        \t5.Crie uma numa disciplina.\t6.Mude os dados de uma disciplina.\t7.Mostrar as disciplinas existentes.\t8.Remover uma disciplina da base de dados.\n");
        printf("        \t9. Exams Menu\n-->");
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
            case '5':
                new_class(list_class);
                break;
            case('6'):
                change_clist_data(list_class);
                break;
            case '7':
                print_classes_list(list_class);
                break;
            case '8':
                remove_class_data(list_class);
                break;
            case '9':
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
