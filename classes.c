void new_class(Classes_list head) {
    Class new;

    printf("\n\n### Esta a criar uma nova disciplina ###\n\n");
    printf("\tQual o nome da disciplina?\n\t-->");
    fgets(new.name,50,stdin);
    printf("\tQual o nome do professor da disciplina?\n\t-->");
    fgets(new.teacher,50,stdin);
    append_class(head, new);
}

void change_classes_data(Class* cls) {
               
        // Name
        printf("\n\tEste e o nome da disciplina --> %s", (*cls).name);
        confirm_answer("\tO novo nome da disciplina e\n\t-->", 0, (*cls).name); 

        // Teacher
        printf("\n\tEste e o nome do professor--> %s", (*cls).teacher);
        confirm_answer("\tO nome do novo professor da disciplina e\n\t-->", 0, (*cls).teacher); 
}

void change_clist_data(Classes_list *head) {
        Classes_list copy = *head;

        printf("\n\n### Esta a querer alterar os dados de uma disciplina ###\n\n");
        get_class(&(*head));
        change_classes_data(&(*head)->data);
}        
 
void remove_class_data(Classes_list head) {
    Classes_list copy = head;
    
    printf("\n\n### ESTA A QUERER REMOVER UMA DISCIPLINA DA BASE DE DADOS ###\n\n");
    get_class(&head);
    removes_from_classes_list(copy, head->data);
    printf("\tA disciplina: %s foi retirado da base de dados\n\n", head->data.name);
}
        









