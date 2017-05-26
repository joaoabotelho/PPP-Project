#include "header.h"

/* new_class creates a new Class and append it to the head list
 *
 * asks to user for the new Class name 
 *
 * checks if it already exists that Class
 *      if it already exists prints "Uma disciplina com esse nome ja existe. Tente de novo."
 *      and continues
 *
 *      else asks the user for the name of the teacher
 *      and appends to head the new Class
*/
void new_class(Classes_list head) {
    Class new;
    Classes_list curr, useless;

    printf("\n\n### Esta a criar uma nova disciplina ###\n\n");

    printf("\tQual o nome da disciplina?\n\t-->");
    new.name = (char *)malloc(CHAR_SIZE * sizeof(char));
    fgets(new.name, CHAR_SIZE, stdin);

    search_classes_list(head, new, &useless, &curr);
    if(curr != NULL) {
        printf("Uma disciplina com esse nome ja existe. Tente de novo.");
    } else {
        printf("\tQual o nome do professor da disciplina?\n\t-->");
        new.teacher = (char *)malloc(CHAR_SIZE * sizeof(char));
        fgets(new.teacher, CHAR_SIZE, stdin);

        append_class(head, new);
    }
}

/* change_classes_data changes the data of a Class
 * 
 * prints the name of the Class
 * and asks the user if they want to change the name of the Class
 *
 * prints the teacher of the Class
 * and asks the user if they want to change the name of the Class
 *
 * if the user wants to change they simply answer 'y' and it will ask for the
 * new information
*/
void change_classes_data(Class *cls) { 
        /* Name */
        printf("\n\tEste e o nome da disciplina --> %s", (*cls).name);
        confirm_answer("\tO novo nome da disciplina e\n\t-->", 0, (*cls).name);

        /* Teacher */
        printf("\n\tEste e o nome do professor--> %s", (*cls).teacher);
        confirm_answer("\tO nome do novo professor da disciplina e\n\t-->", 0, (*cls).teacher); 
}

/* change_clist_data changes information of a Class in head list
 * 
 * checks if there are Classes in head
 * asks to the user wich Class they wish to change
 *
 * and changes the class information
*/
void change_clist_data(Classes_list *head) {
        if((*head)->next != NULL) {
            printf("\n\n### Esta a querer alterar os dados de uma disciplina ###\n\n");
            request_class(&(*head)); 
            change_classes_data(&(*head)->data);
        } else {
            printf("Nao existem disciplinas na base de dados");
        }
}        
 
/* remove_class_data simply removes from head the Class that the user wants
 *
 * checks if there are Classes in head
 *
 * it asks to the user wich Class they want
 * and then removes it from the head list
*/
void remove_class_data(Classes_list head) {
    Classes_list copy = head;
    
    if(head->next != NULL) {
        printf("\n\n### ESTA A QUERER REMOVER UMA DISCIPLINA DA BASE DE DADOS ###\n\n");
        request_class(&head); 

        removes_from_classes_list(copy, head->data); 
        printf("\tA disciplina: %s foi retirado da base de dados\n\n", head->data.name);
    } else {
        printf("Nao existem disciplinas na base de dados");
    }
}
