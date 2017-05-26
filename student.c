#include <time.h>
#include "header.h"

/* already_exist confirms the existance of a student
 * in the head list by searching for the student_numb
 *
 * if there is this student_numb this prints 
 * "Numero de estudante invalido ou ja existente." and returns 1
 *
 * or else it returns 0
*/
int already_exist(Student_list head, int student_numb) {
    Student_list curr, useless;

    search_student_list(head, student_numb, &useless, &curr);
    if(curr != NULL) {
        printf("\tNumero de estudante invalido ou ja existente.");
        return 1; 
    }    
    return 0;
}

/* new_student creates a new Student and appends it to the head list
 *
 * asks to user for the new student number and checks if it already exists
 * then asks for the course, the year and the regime of this new student
 *
 * finaly appends to the list head
*/
void new_student(Student_list head) {
    Student new;

    printf("\n\n### Esta a criar um novo aluno ###\n\n");
    printf("\tQual e o numero de aluno?\n\t-->");
    new.numb = (int *)malloc(sizeof(int));
    fgets_int(new.numb); 

    if(already_exist(head, *new.numb) == 0) {

        printf("\tQue curso frequenta?\n\t-->");
        new.course = (char *)malloc(CHAR_SIZE * sizeof(char));
        check_memory_char(new.course); // AJDJAJSDAJDJSAJDAJSDAJ
        fgets(new.course, CHAR_SIZE, stdin);

        printf("\tQue ano frequenta?(1,2,3)\n\t-->");
        new.year = (int *)malloc(sizeof(int));
        fgets_int(new.year);

        printf("\tQual o seu regime?\n");
        new.regime = (char *)malloc(CHAR_SIZE * sizeof(char));
        regime(new.regime);
        append_student(&head, new);
    }
}

/* request_student asks the user wich Student in head they wish to use
 *
 * prints head for the user to pick wich Student they wish
 * the user writes the number of the student and its saved on student_numb
 *
 * it goes through the list copy(wich is a copy of the head list) unitl they find the same student_numb 
 * 
 * if they dont find it, it prints "Nao existe ninguem com esse numero. Tente de novo."
 * and it asks the user for another student
 *
 * when it finds the student_numb it goes to the position of that Student in
 * head list returning head in that position 
*/
void request_student(Student_list *head) {
    int student_numb, i, n;
    Student_list copy;

    do {
        copy = *head;
        n = 0;
        printf("\tQue aluno pretende?(n de aluno)");
        print_student_list(copy);
        printf("\t-->");
        fgets_int(&student_numb);

        while((*copy->data.numb != student_numb) && (copy->next != NULL)) {
            copy = copy->next;
            n++;
        }
        
        if(student_numb == 0 || *copy->data.numb != student_numb)
            printf("\tNao existe ninguem com esse numero. Tente de novo.");
    } while(student_numb == 0 || *copy->data.numb != student_numb);

    for(i = 0; i < n; i++) {
        *head = (*head)->next;
    }
}

/* change_slist_data changes information of a Student in head list 
 *
 * checks if there are Students in head
 * asks for the user wich Student they wish to change
 * 
 * asks if they want to change the number
 *      if the new number they want to change to already exists it asks the user
 *      for a new number
 * if they want to change the course, year and regime 
 *
 * if the user wants to change they simply answer 'y' and it will ask for the
 * new information
*/
void change_slist_data(Student_list head) {
    int numb = -1, student_numb; 
    Student_list copy = head;

    
    if(head->next != NULL) {
        printf("\n\n### Esta a querer alterar os dados de um aluno ###\n\n");
        request_student(&head);

        /* Numb */
        student_numb = *head->data.numb;
        do {
            printf("\n\tEste e o numero do aluno --> %d\n", *head->data.numb);
            confirm_answer("\tO novo numero do aluno e\n\t-->", &student_numb, "0");
        } while(student_numb != *head->data.numb && already_exist(copy, student_numb) == 1);
        if(student_numb != 0)
            *head->data.numb = student_numb;

        /* Course */
        printf("\n\tEste e o curso do aluno --> %s", head->data.course);
        confirm_answer("\tO novo curso do aluno e\n\t-->", 0, head->data.course); 

        /* Year */
        printf("\n\tO aluno esta neste ano --> %d\n", *head->data.year);
        confirm_answer("\tO novo ano do aluno e\n\t-->", head->data.year, "0");

        /* Regime  */
        printf("\n\tEste e o regime do aluno --> %s\n", head->data.regime); 
        confirm_answer("\tO novo regime do aluno e\n", &numb, head->data.regime); 
    } else {
        printf("Nao existem alunos na base de dados");
    }
}

/* remove_student_data simply removes from head the Student that the user wants
 *
 * checks if there are Students in head
 *
 * it asks for the user wich Student they want
 * and then removes it from the head list
*/
void remove_student_data(Student_list head) {
    Student_list copy = head;

    if(head->next != NULL) {
        printf("\n\n### ESTA A QUERER REMOVER UM ALUNO DA BASE DE DADOS ###\n\n");
        request_student(&head);

        removes_from_student_list(copy, *head->data.numb);
        printf("\tAluno numero: %d foi retirado da base de dados\n\n", *head->data.numb); 
    } else {
        printf("Nao existem alunos na base de dados");
    }
}

