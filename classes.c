/* Creates a new class */
void new_class(Classes_list head) {
    Class new;
    Classes_list curr, useless;

    printf("\n\n### Esta a criar uma nova disciplina ###\n\n");

    /* Asks for name of class */
    printf("\tQual o nome da disciplina?\n\t-->");
    new.name = (char *) malloc (CHAR_SIZE * sizeof(char));
    fgets(new.name, CHAR_SIZE, stdin);

    search_classes_list(head, new, &useless, &curr);
    if(curr != NULL) {
        printf("Uma disciplina com esse nome ja existe. Tente de novo.");

    } else {
        /* Asks for name of teacher */
        printf("\tQual o nome do professor da disciplina?\n\t-->");
        new.teacher = (char *) malloc (CHAR_SIZE * sizeof(char));
        fgets(new.teacher, CHAR_SIZE, stdin);

        /* Adds to the list of classes this new class */
        append_class(head, new);
    }
}

/* Changes the data of classes */
void change_classes_data(Class* cls) {
               
        /* Name */
        printf("\n\tEste e o nome da disciplina --> %s", (*cls).name);
        confirm_answer("\tO novo nome da disciplina e\n\t-->", 0, (*cls).name);

        /* Teacher */
        printf("\n\tEste e o nome do professor--> %s", (*cls).teacher);
        confirm_answer("\tO nome do novo professor da disciplina e\n\t-->", 0, (*cls).teacher); 
}

void change_clist_data(Classes_list *head) {

        if((*head)->next != NULL) {
            printf("\n\n### Esta a querer alterar os dados de uma disciplina ###\n\n");
            get_class(&(*head)); 
            change_classes_data(&(*head)->data);
        } else {
            printf("Nao existem disciplinas na base de dados");
        }
}        
 
/* Asks the user wich class they wish to remove from the list and removes it */
void remove_class_data(Classes_list head) {
    Classes_list copy = head;
    
    if(head->next != NULL) {
        printf("\n\n### ESTA A QUERER REMOVER UMA DISCIPLINA DA BASE DE DADOS ###\n\n");
        get_class(&head); 

        removes_from_classes_list(copy, head->data); 
        printf("\tA disciplina: %s foi retirado da base de dados\n\n", head->data.name);
    } else {
        printf("Nao existem disciplinas na base de dados");
    }
}
