#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.c"

typedef struct node *List;
typedef struct node{
        int value;
	      List next;
} List_node;

List create_list(){
        List aux;
        aux = (List) malloc (sizeof (List_node));
        if(aux != NULL){
                aux->value = 0;
                aux->next = NULL;
        }
        return aux;
}

void print_list(List numb){
        List I = numb->next;
        while(I){
                printf("%d\n",I->value);
                I=I->next;
        }
}

int main(){ 
        Student lala = new_student();
        //change_data(lala);
        return 0;
}
