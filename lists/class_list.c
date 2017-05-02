typedef struct class{
    char name[50];
    char teacher[50];
} Class;

typedef struct cnode *Classes_list;
typedef struct cnode {
    Class data;
    Classes_list next;
} Classes_node;

Classes_list create_classes_list() {
    Classes_list aux;
    Class null;

    aux = (Classes_list) malloc (sizeof (Classes_node));
    if(aux != NULL){
        aux->data = null;
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

    printf("### LISTA ACTUAL DE DISCIPLINAS ###\n\n");
    while(I){
        printf("Disciplina--> %s\n", I->data.name);
        printf("Docente--> %s\n", I->data.teacher);
        printf("---------------------------\n");
        I = I->next;
    }
}

void get_class(Classes_list *head) {
    char class_name[50];
    Classes_list *copy = head;

    print_classes_list(*head);
    printf("-->");
    fgets(class_name,50,stdin);
    while((strcmp((*head)->data.name, class_name) != 0) && ((*head)->next != NULL))
        *head = (*head)->next;

    if(strcmp((*head)->data.name, class_name) != 0) {
        get_class(copy);
    }
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
