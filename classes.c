void new_class(Classes_list head) {
    Class new;

    printf("### Esta a criar uma nova disciplina ###\n\n");
    printf("Qual o nome da disciplina?\n");
    fgets(new.name,50,stdin);
    printf("Qual o nome do professor da disciplina?\n");
    fgets(new.teacher,50,stdin);
    append_class(head, new);
}

void change_classes_data(Class* cls) {
        char answer;
              
        printf("### Esta a querer alterar os dados de uma disciplina ###\n\n");
       
        // Name
        printf("Este e o nome da disciplina --> %s\n", (*cls).name);
        confirm_answer("O novo nome da disciplina e\n-->", 0, (*cls).name); 

        // Teacher
        printf("Este e o nome do professor--> %s\n\n", (*cls).teacher);
        confirm_answer("O nome do novo professor da disciplina e\n-->", 0, (*cls).teacher); 
}

void change_clist_data(Classes_list *head) {
        Classes_list copy = *head;

        printf("Que disciplina deseja alterar?\n");
        get_class(&(*head));
        change_classes_data(&(*head)->data);
}        
 
void remove_class_data(Classes_list head) {
    Classes_list copy = head;
    char class_name[50];
    
    printf("### ESTA A QUERER REMOVER UMA DISCIPLINA DA BASE DE DADOS ###\n\n");
    printf("Que disciplina deseja remover?(n de aluno)\n");
    get_class(&head);
    removes_from_classes_list(copy, head->data);
    printf("A disciplina: %s foi retirado da base de dados\n\n", class_name);
}
        









