#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct student{
    int numb;
    char course[50];
    int year;
    char regime[50];
} Student;

typedef struct node *Student_list;
typedef struct node{
    Student data;
    Student_list next;
} Student_node;

Student_list create_students_list(){
    Student_list aux;
    Student null;
    aux = (Student_list) malloc (sizeof (Student_node));
    if(aux != NULL){
        aux->data = null;
        aux->next = NULL;
    }
    return aux;
}

void append_student(Student_list list, Student new){
    Student_list node;
    node = (Student_list) malloc (sizeof (Student_node));
    node->data = new;
    while(list->next != NULL)
        list = list->next;
    list->next = node;
    list = node;
    list->next = NULL;
}
     
void print_student_list(Student_list head){
    Student_list I = head->next;
    printf("### LISTA ACTUAL DE ALUNOS ###\n\n");
    while(I){
        printf("Num de estudante--> %d\n", I->data.numb);
        printf("Curso do estudant--> %s\n", I->data.course);
        printf("Ano do estudante--> %d\n", I->data.year);
        printf("Regime do estudante--> %s\n\n", I->data.regime);
        I = I->next;
    }
}



