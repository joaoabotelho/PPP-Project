#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct class{
    char name[50];
    char teacher[50];
} Class;

typedef struct cnode *Classes_list;
typedef struct cnode {
    Class data;
    Classes_list next;
} Classes_node;

Classes_list create_classes_list(){
    Classes_list aux;
    Class null;
    aux = (Classes_list) malloc (sizeof (Classes_node));

    if(aux != NULL){
        aux->data = null;
        aux->next = NULL;
    }
    return aux;
}

void print_classes_list(Classes_list head){
    Classes_list I = head->next;

    printf("### LISTA ACTUAL DE DISCIPLINAS ###\n\n");
    while(I){
        printf("Disciplina--> %s\n", I->data.name);
        printf("Docente--> %s\n", I->data.teacher);
        printf("---------------------------\n");
        I = I->next;
    }
}

void append_class(Classes_list head, Class new){
    Classes_list node;
    node = (Classes_list) malloc (sizeof (Classes_node));

    node->data = new;
    while(head->next != NULL)
        head = head->next;
    head->next = node;
    head = node;
    head->next = NULL;
}


