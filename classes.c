#include "lists/class_list.c"

void new_class(Classes_list head){
    Class new;

    printf("### Esta a criar uma nova disciplina ###\n\n");
    printf("Qual o nome da disciplina?\n");
    fgets(new.name,50,stdin);
    printf("Qual o nome do professor da disciplina?\n");
    fgets(new.teacher,50,stdin);
    append_class(head, new);
}

void change_classes_data(Class* cls){
        char answer;
              
        printf("### Esta a querer alterar os dados de uma disciplina ###\n\n");
        // Name
        printf("Este e o nome da disciplina --> %s\n", (*cls).name);
        answer = check_answer();
        if(answer == 'y'){
            printf("O novo nome da disciplina e\n-->\n");
            fgets((*cls).name,50,stdin);
        }
        // Teacher
        printf("Este e o nome do professor--> %s\n\n", (*cls).teacher);
        answer = check_answer();
        if(answer == 'y'){
            printf("O nome do novo professor da disciplina e\n-->\n");
            fgets((*cls).teacher,50,stdin);
        }
}
/*
void change(node_t *head)
{
    node_t *temp;
    temp=head;
    while (temp!=NULL)
    {
        change_data(&temp->val);
        temp=temp->next;
    }
}

void remov(node_t *head){
    char classname[50];
    node_t *temp,*ant,*actual;
    temp=head;
    ant=temp;
    actual=temp->next;
    printf("### Esta a querer remover os dados de uma disciplina ###\n\n");
    printf("Introduza o nome da disciplina que pretende remover.");
    fflush(stdin);
    fgets(classname,50,stdin);
    while (temp!=NULL){
        if (strcmp(temp->val.name,classname)==0){
            ant->next = actual->next;
            free (actual);
            break;
        }
        ant=actual;
        actual=temp->next;
        temp=temp->next;
    }
}
*/










