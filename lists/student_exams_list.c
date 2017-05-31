#include "../header.h"

/* check_memory_selist checks if a Student_exams_list equals NULL
 * if it is NULL the whole program stops because its a sign of no dynamic memory */
void check_memory_selist(Student_exams_list a) {
    if(!a) { 
        printf("No memory\n");
        exit(0);
    } 
}

/* create_student_exams_list returns a new Student_exams_list */ 
Student_exams_list create_student_exams_list() {
    Student_exams_list aux;
    Student_exams useless;

    useless.a.numb = (int *) malloc (sizeof(int));
    *useless.a.numb = -1;
    useless.submitted = create_exams_list();
    aux = (Student_exams_list)malloc(sizeof (Student_exams_node));
    check_memory_selist(aux);
    if(aux != NULL) {
        aux->data = useless;
        aux->next = NULL;
    }
    return aux;
}

/* search_student_exams_list searches for a Student number in the
 * Students_exams_list 
 *
 * if it finds it curr will be in the position of the searched Student_exams
 * if it doesnt find it curr will be NULL
*/
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

/* append_student_exams appends to the Student_exams_list head the new Student_exams
 * associating st Student and a empty Exams_list */
void append_student_exams(Student_exams_list *head, Student st) {
    Student_exams_list node, prev, useless;
    Student_exams new;

    new.a = st;
    new.submitted = create_exams_list();

    node = (Student_exams_list)malloc(sizeof (Student_exams_node));
    check_memory_selist(node);
    if(node != NULL) {
        node->data = new;
        search_student_exams_list(*head, *new.a.numb, &prev, &useless);
        node->next = prev->next;
        prev->next = node;
    }
}

void removes_from_student_exams_list(Student_exams_list head, int student_numb) {
    Student_exams_list prev, curr;
    
    search_student_exams_list(head, student_numb, &prev, &curr);
    if(curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}
