#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "base.c"
#include "student.c"
#include "classes.c"


void menu(Student_list list_student){
    Student_list copy = list_student;
    char choice[50];
    while(1){ 
        printf("@@@@@@      Welcome to this app      @@@@@@\n");
        printf("$ MENU $\t1.Crie um novo perfil estudante.\t2.Mude os dados de um estudante.\t3.Mostrar a lista de estudantes.\n-->");
        fgets(choice,50,stdin);

        switch(choice[0]){
            case '1': 
                new_student(list_student);
                copy = list_student;
                break;
            case '2': // BUG: dont change the list in the menu;
                change_list_data(list_student);
                copy = list_student;
                break;
            case '3':
                print_student_list(list_student);
                Student_list copy = list_student;
                break;
            default:
                printf("Wrong choice. Enter again.\n");
                break;
        } 
        menu(copy);
    }
}

int main(){ 
    Student_list list_student = create_students_list();
    //menu(list_student);
    new_student(list_student);
    new_student(list_student);
    new_student(list_student);
    print_student_list(list_student);
    //lala = sort_student(jabuga);
    //print_student_list(lala);
    change_list_data(list_student);
    print_student_list(list_student);
}
