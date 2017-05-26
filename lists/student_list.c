#include "../header.h"

Student_list create_students_list() {
    Student_list aux = (Student_list)malloc(sizeof (Student_node));
    Student useless;

    useless.numb = (int *)malloc(sizeof(int));
    *useless.numb = -1;
    if(aux != NULL){
        aux->data = useless;
        aux->next = NULL;
    }
    return aux;
}

void search_student_list(Student_list head, int student_numb, Student_list *prev, Student_list *curr) {

    *prev = head;
    *curr = head->next;
    while((*curr) != NULL && *(*curr)->data.numb < student_numb) {
        *prev = *curr;
        *curr = (*curr)->next;
    }
    if((*curr) != NULL && *(*curr)->data.numb != student_numb) {
        *curr = NULL;
    }
}

void removes_from_student_list(Student_list head, int student_numb) {
    Student_list prev, curr;

    search_student_list(head, student_numb, &prev, &curr);
    if(curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}

void append_student(Student_list *head, Student new) {
    Student_list node, prev, useless;

    node = (Student_list)malloc(sizeof (Student_node));
    if(node != NULL) {
        node->data = new;
        search_student_list(*head, *new.numb, &prev, &useless);
        node->next = prev->next;
        prev->next = node;
    }
}

void print_student_list(Student_list head){
    Student_list I = head->next;

    printf("\n\n### LISTA ACTUAL DE ALUNOS ###\n\n");
    while(I){
        printf("\tNum de estudante--> %d\n", *I->data.numb);
        printf("\tCurso do estudant--> %s\n", I->data.course);
        printf("\tAno do estudante--> %d\n", *I->data.year);
        printf("\tRegime do estudante--> %s\n", I->data.regime);
        printf("----------------------\n\n");
        I = I->next;
    }
}   

void regime(char str[]) {
    char *temp = (char *)malloc(CHAR_SIZE * sizeof(char));

    check_memory_char(temp);
    while(temp[0] != '1' && temp[0] != '2' &&  temp[0] != '3' && temp[0] != '4' && temp[0] != '5') {
        printf("\t\t1.Normal\n\t\t2.Trabalhador-estudante\n\t\t3.Atleta\n\t\t4.Dirigente associativo\n\t\t5.Aluno de Erasmus\n\t-->");
        fgets(temp, CHAR_SIZE, stdin);

        switch(temp[0]) {
            case '1':
                strcpy(str, "Normal\n");
                break;
            case '2':
                strcpy(str, "Trabalhador-estudante\n");
                break;
            case '3':
                strcpy(str, "Atleta\n");
                break;
            case '4':
                strcpy(str, "Dirigente associativo\n");
                break;
            case '5':
                strcpy(str, "Aluno de Erasmus\n");
                break;
            default:
                printf("\t\tEscolha errada. Tente de novo.\n");
        }
    }
    free(temp);
}

void swap(Student_list a, Student_list b) {
    Student temp = a->data;

    a->data = b->data;
    b->data = temp;
}

void bubble_sort(Student_list head) {
    int swapped;
    Student_list ptr1, lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = head->next;

        while(ptr1->next != lptr) {
            if(*ptr1->data.numb > *ptr1->next->data.numb) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while(swapped);
}

int size_of_student_list(Student_list head) {
    int num = 0;
    
    while(head->next != NULL) {
        head = head->next;
        num++;
    }

    return num;
}
