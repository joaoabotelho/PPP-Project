#include "../header.h"

Student_exams_list create_student_exams_list() {
    Student_exams_list aux;
    Student_exams useless;

    useless.a.numb = (int *) malloc (sizeof(int));
    *useless.a.numb = -1;
    useless.submitted = create_exams_list();
    aux = (Student_exams_list)malloc(sizeof (Student_exams_node));
    if(aux != NULL) {
        aux->data = useless;
        aux->next = NULL;
    }
    return aux;
}

void search_student_exams_list(Student_exams_list head, int student_numb, Student_exams_list *prev, Student_exams_list *curr) {

    *prev = head;
    *curr = head->next;
    while((*curr) != NULL && *(*curr)->data.a.numb < student_numb) {
        *prev = *curr;
        *curr = (*curr)->next;
    }
    if((*curr) != NULL && *(*curr)->data.a.numb != student_numb)
        *curr = NULL;
}

void append_student_exams(Student_exams_list *head, Student st) {
    Student_exams_list node, prev, useless;
    Student_exams new;

    new.a = st;
    new.submitted = create_exams_list();

    node = (Student_exams_list)malloc(sizeof (Student_exams_node));
    if(node != NULL) {
        node->data = new;
        search_student_exams_list(*head, *new.a.numb, &prev, &useless);
        node->next = prev->next;
        prev->next = node;
    }
}

