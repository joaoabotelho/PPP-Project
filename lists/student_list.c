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
void search_student_list(Student_list head, int student_numb, Student_list *prev, Student_list *curr) {

    *prev = head;
    *curr = head->next;
    while((*curr) != NULL && (*curr)->data.numb < student_numb) {
        *prev = *curr;
        *curr = (*curr)->next;
    }
    if((*curr) != NULL && (*curr)->data.numb != student_numb)
        *curr = NULL;
}

void removes_from_student_list(Student_list head, int student_numb) {
    Student_list prev, curr;

    search_student_list(head, student_numb, &prev, &curr);
    if(curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}

void append_student_wOrder(Student_list head, Student new) {
    Student_list node, prev, useless;

    node = (Student_list) malloc (sizeof (Student_node));
    if(node != NULL) {
        node->data = new;
        search_student_list(head, new.numb, &prev, &useless);
        node->next = prev->next;
        prev->next = node;
    }
}
     
void print_student_list(Student_list head){
    Student_list I = head->next;

    printf("### LISTA ACTUAL DE ALUNOS ###\n\n");
    while(I){
        printf("Num de estudante--> %d\n", I->data.numb);
        printf("Curso do estudant--> %s\n", I->data.course);
        printf("Ano do estudante--> %d\n", I->data.year);
        printf("Regime do estudante--> %s\n", I->data.regime);
        printf("----------------------\n\n");
        I = I->next;
    }
}




