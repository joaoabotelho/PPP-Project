#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const int CHAR_SIZE = 50;

#include "lists/student_list.c"
#include "lists/class_list.c"
#include "lists/exam_list.c"
#include "lists/student_exams_list.c"
#include "base.c"
#include "student.c"
#include "classes.c"
#include "exams.c"
#include "student_exams.c"
#include "extract_files.c"
#include "import_files.c"

void display_of_options(char *options[], int n) {
    int i;
    
    for(i = 0; i < n; i++) {
        printf("\n\t %d.%s", i + 1, options[i]);
    }
}

// Menu to add/see/associate with other data/manage data of exams
void exams_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam, Student_exams_list list_student_exams) {
    char *choice = (char*) malloc (CHAR_SIZE * sizeof(char));
    char *options[] = {
        "Crie um novo exame.", 
        "Mostrar os exames.",
        "Submeter um aluno a um exame.",
        "Remover um aluno inscrito de um exame.",
        "Mostrar lista de alunos inscritos num exame.",
        "Mostrar lista de salas ocupadas num exame.",
        "Apagar exame"
    };

    printf("\n\n$ EXAMS MENU $");
    display_of_options(options, 7);
    printf("\n-->");
    fgets(choice, CHAR_SIZE, stdin);

    switch(choice[0]) {
        case '1': 
            create_exam(list_exam, list_class);
            break;
        case '2':
            print_exams_list(list_exam);
            break;
        case '3':
            submit_students(list_student, list_exam, list_student_exams);
            break;
        case '4':
            remove_submit_students(list_exam, list_student_exams);
            break;
        case '5':
            print_submited_students(list_exam);
            break;
        case '6':
            print_classrooms(list_exam);
            break;
        case '7':
            delete_exam(list_exam, list_student_exams);
            break;
        default:
            printf("Escolha errada. Tente de novo.\n");
            exams_menu(list_student, list_class, list_exam, list_student_exams);
    }   
}

// Menu to add/change/see/remove data from classes
void classes_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam, Student_exams_list list_student_exams) {
    int i;
    char *choice = (char*) malloc (CHAR_SIZE * sizeof(char));
    char *options[] = { 
        "Crie uma nova disciplina.",
        "Mude os dados de uma disciplina.",
        "Mostrar as disciplinas existentes.",
        "Remover uma disciplina da base de dados." 
    };

    printf("\n\n$ CLASSES MENU $");
    display_of_options(options, 4);
    printf("\n-->");
    fgets(choice, CHAR_SIZE, stdin);

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
            printf("Escolha errada. Tente de novo.\n");
            classes_menu(list_student, list_class, list_exam, list_student_exams);
    }  
}

// Menu to add/change/see/remove data of students
void students_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam, Student_exams_list list_student_exams) {
    char *choice = (char*) malloc (CHAR_SIZE * sizeof(char));
    char *options[] = {
        "Crie um novo aluno.",
        "Mude os dados de um aluno.",
        "Mostrar lista de alunos existentes.",
        "Remover um aluno da base de dados.",
        "Mostrar exames inscritos por um aluno."
    };

    printf("\n\n$ STUDENTS MENU $");
    display_of_options(options, 5);
    printf("\n-->");
    fgets(choice, CHAR_SIZE, stdin);

    switch(choice[0]) {
        case '1': 
            new_student(list_student);
            break;
        case '2': 
            change_slist_data(list_student);
            bubbleSort(list_student);
            break;
        case '3':
            print_student_list(list_student);
            break;
        case '4':
            remove_student_data(list_student);
            break;
        case '5':
            print_exams_of_student(list_student_exams, list_student);
            break;
        default:
            printf("Escolha errada. Tente de novo.\n");
            students_menu(list_student, list_class, list_exam, list_student_exams);
    }
}

void exit_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam, Student_exams_list list_student_exams) {
    imp_classes(list_class);
    printf("\nObrigado. Os dados foram atualizados nos ficheiros.");
}

// Goes to other menus Student/Classes/Exams
void main_menu(Student_list list_student, Classes_list list_class, Exams_list list_exam, Student_exams_list list_student_exams) {
    char *choice = (char*) malloc (CHAR_SIZE * sizeof(char));
    char *options[] = {
        "Students Menu",
        "Classes Menu",
        "Exams Menu",
        "Exit Menu"
    };
    printf("\n\n@@@@@@      Welcome to this app      @@@@@@\n\n");
    printf("$ MENU $");
    display_of_options(options, 4);
    printf("\n-->");
    fgets(choice, CHAR_SIZE, stdin);

    switch(choice[0]) {
        case '1':
            students_menu(list_student, list_class, list_exam, list_student_exams);
            main_menu(list_student, list_class, list_exam, list_student_exams);
            break;
        case '2':
            classes_menu(list_student, list_class, list_exam, list_student_exams);
            main_menu(list_student, list_class, list_exam, list_student_exams);
            break;
        case '3':
            exams_menu(list_student, list_class, list_exam, list_student_exams);
            main_menu(list_student, list_class, list_exam, list_student_exams);
            break;
        case '4':
            exit_menu(list_student, list_class, list_exam, list_student_exams);
            break;
        default:
            printf("Escolha errada. Tente de novo.\n");
            main_menu(list_student, list_class, list_exam, list_student_exams);
    } 
}

int main() { 
    Student_list list_student = create_students_list();
    Classes_list list_class = create_classes_list();
    Exams_list list_exam = create_exams_list();
    Student_exams_list list_student_exams = create_student_exams_list();

    ex_classes(list_class);
    main_menu(list_student, list_class, list_exam, list_student_exams);

    return 0;
}
