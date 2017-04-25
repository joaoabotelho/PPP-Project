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

void append_student(Student_list head, Student new){
    Student_list node;
    node = (Student_list) malloc (sizeof (Student_node));
    node->data = new;
    while(head->next != NULL)
        head = head->next;
    head->next = node;
    head = node;
    head->next = NULL;
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

int size_of_list(Student_list head){
    int elements=0;
    while(head->next != NULL){
        head = head->next;
        elements++;
    }
    return elements;
}
/* DOESNT WORK SORT_STUDENT
Student_list bigger(Student_list head){
    Student_list bigger = create_students_list();
    bigger->data.numb = 0;
    while(head->next != NULL){
        head = head->next;
        print_student_list(bigger);
        if((bigger->data.numb < head->data.numb)){
            append_student(bigger, head->data);
            bigger->data.numb = head->data.numb;
        }
    }
    return bigger;
}

Student_list sort_student(Student_list head){
        // Variables
        int i, size = size_of_list(head);// Counter, size of list, biggest int in list
        Student_list big = bigger(head);
        Student_list final = create_students_list(); // Final result
        Student_list temp = create_students_list(); // keeps track of last value
        Student_list node = create_students_list(); // saves the next value to add to final
        
        for(i=0; i<size; i++){

                Student_list copy = head; // creates a copy of the list every time it cycles
                node->data = big->data;
                while(copy->next != NULL){
                        copy = copy->next;  
                        if((temp->data.numb < copy->data.numb) && (node->data.numb > copy->data.numb))
                                node->data = copy->data;
                }
                append_student(temp, node->data);
                append_student(final, node->data);
                temp = temp->next;
        }

        return final;
}
*/




