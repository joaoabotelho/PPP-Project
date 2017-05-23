#include <time.h>

void already_exist(Student_list head, int student_numb) {
    Student_list curr, useless;

    search_student_list(head, student_numb, &useless, &curr);
    if(curr != NULL) 
        printf("Um estudante com este numero ja foi criado");
}

void new_student(Student_list head) {
    Student new;
    Student_list curr, useless;

    printf("\n\n### Esta a criar um novo aluno ###\n\n");
    printf("\tQual e o numero de aluno?\n\t-->");
    new.numb = (int *) malloc (sizeof(int));
    fgets_int(new.numb); 

    search_student_list(head, *new.numb, &useless, &curr);
    if(curr != NULL) { 
        printf("\tUm estudante com este numero ja foi criado.");

    } else {

        printf("\tQue curso frequenta?\n\t-->");
        new.course = (char *) malloc (CHAR_SIZE * sizeof(char));
        fgets(new.course, CHAR_SIZE, stdin);

        printf("\tQue ano frequenta?(1,2,3)\n\t-->");
        new.year = (int *) malloc (sizeof(int));
        fgets_int(new.year);

        printf("\tQual o seu regime?\n");
        new.regime = (char *) malloc (CHAR_SIZE * sizeof(char));
        regime(new.regime);
        append_student_wOrder(&head, new);
    }
}
   
void what_student(Student_list *head) {
    int student_numb;

    do {
        printf("\tQue aluno pretende?(n de aluno)");
        print_student_list(*head);
        printf("\t-->");
        fgets_int(&student_numb);

        while((*(*head)->data.numb != student_numb) && ((*head)->next != NULL))
            *head = (*head)->next;
        if(*(*head)->data.numb != student_numb)
            printf("\tNao existe ninguem com esse numero. Tente de novo.");
    } while(*(*head)->data.numb != student_numb);
}

void change_slist_data(Student_list head) {
    int numb = -1; 

    if(head->next != NULL) {
        printf("\n\n### Esta a querer alterar os dados de um aluno ###\n\n");
        what_student(&head);

        /* Numb */
        printf("\n\tEste e o numero do aluno --> %d\n", *head->data.numb);
        confirm_answer("\tO novo numero do aluno e\n\t-->", head->data.numb, "0");

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

void remove_student_data(Student_list head) {
    Student_list copy = head;

    if(head->next != NULL) {
        printf("\n\n### ESTA A QUERER REMOVER UM ALUNO DA BASE DE DADOS ###\n\n");
        what_student(&head);

        removes_from_student_list(copy, *head->data.numb);
        printf("\tAluno numero: %d foi retirado da base de dados\n\n", *head->data.numb); 
    } else {
        printf("Nao existem alunos na base de dados");
    }
}

