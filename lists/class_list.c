typedef struct class{
    char *name;
    char *teacher;
} Class;

typedef struct cnode *Classes_list;
typedef struct cnode {
    Class data;
    Classes_list next;
} Classes_node;

Classes_list create_classes_list() {
    Classes_list aux;
    Class useless;

    useless.name = (char *) malloc (CHAR_SIZE * sizeof(char));
    useless.name = "";
    aux = (Classes_list) malloc (sizeof (Classes_node));
    if(aux != NULL){
        aux->data = useless;
        aux->next = NULL;
    }
    return aux;
}

void search_classes_list(Classes_list head, Class search, Classes_list *prev, Classes_list *curr) {

    *prev = head;
    *curr = head->next;
    while((*curr) != NULL && strcmp((*curr)->data.name, search.name) != 0) {
        *prev = *curr;
        *curr = (*curr)->next;
    }

    if((*curr) != NULL && strcmp((*curr)->data.name, search.name) != 0)
        *curr = NULL;
}

void removes_from_classes_list(Classes_list head, Class remv) {
    Classes_list prev, curr;

    search_classes_list(head, remv, &prev, &curr);
    if(curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}

void print_classes_list(Classes_list head) {
    Classes_list I = head->next;

    printf("\n\n### LISTA ACTUAL DE DISCIPLINAS ###\n\n");
    while(I){
        printf("\tDisciplina--> %s\n", I->data.name);
        printf("\tDocente--> %s\n", I->data.teacher);
        printf("---------------------------\n");
        I = I->next;
    }
}

void get_class(Classes_list *head) {
    char *class_name = (char *) malloc (CHAR_SIZE * sizeof(char));

    do {
        printf("\t Que disciplina pretende?");
        print_classes_list(*head);
        printf("\t-->");
        fgets(class_name, CHAR_SIZE, stdin);

        while((strcmp((*head)->data.name, class_name) != 0) && ((*head)->next != NULL))
            *head = (*head)->next;
        if(strcmp((*head)->data.name, class_name) != 0)
            printf("\t\tNome de disciplina nao existente. Tende de novo.\n");
    } while(strcmp((*head)->data.name, class_name) != 0);
}


void append_class(Classes_list head, Class new) {
    Classes_list node;

    node = (Classes_list) malloc (sizeof (Classes_node));
    node->data = new;

    while(head->next != NULL)
        head = head->next;
    head->next = node;
    head = node;
    head->next = NULL;
}
