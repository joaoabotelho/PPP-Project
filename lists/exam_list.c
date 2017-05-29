#include "../header.h"

/* check_memory_elist checks if a Exams_list equals NULL
 * if it is NULL the whole program stops because its a sign of no dynamic memory */
void check_memory_elist(Exams_list a) {
    if(!a) { 
        printf("No memory\n");
        exit(0);
    } 
}

/* check_memory_crlist checks if a Classroom_list equals NULL
 * if it is NULL the whole program stops because its a sign of no dynamic memory */
void check_memory_crlist(Classroom_list a) {
    if(!a) { 
        printf("No memory\n");
        exit(0);
    } 
}

/* create_exams_list returns a new Exams_list */ 
Exams_list create_exams_list() {
    Exams_list aux;
    Exam useless;

    useless.type = "";
    aux = (Exams_list)malloc(sizeof (Exams_node));
    check_memory_elist(aux);
    if(aux != NULL) {
        aux->data = useless;
        aux->next = NULL;
    }
    return aux;
}

/* create_classroom_list returns a new Classroom_list */ 
Classroom_list create_classroom_list() {
    Classroom_list aux;
    Classroom useless;

    useless.room = 0;
    aux = (Classroom_list)malloc(sizeof (Classrooms_node));
    check_memory_crlist(aux);
    if(aux != NULL) {
        aux->data = useless;
        aux->next = NULL;
    }
    return aux;
}

/* print_classroom_list prints the Classroom_list head */
void print_classroom_list(Classroom_list head) {
    Classroom_list I = head->next;

    while(I) { 
        printf("\tSala--> %c%d.%d\n", I->data.letter, I->data.floor, I->data.room);
        I=I->next;
    }

}

/* print_exams_list prints the Exams_list head */
void print_exams_list(Exams_list head) {
    Exams_list I = head->next;

    printf("\n\n#### Lista de exames ####");
    while(I) {
        printf("\n\tExame num --> %d\n", I->data.id);
        printf("\t%s\n", I->data.type);
        printf("\tNome da Disciplina--> %s\n", I->data.subject->name);
        printf("\tDocente da Disciplina--> %s\n", I->data.subject->teacher);
        printf("\tData do exame--> %d / %d / %d\n", I->data.date.day, I->data.date.month, I->data.date.year);
        printf("\tInicio do exame--> %d : %d\n", I->data.time.hour, I->data.time.minutes);
        printf("\tFim do exame--> %d : %d\n", I->data.final.hour, I->data.final.minutes);
        print_classroom_list(I->data.classrooms);
        printf("\n--------------------\n");
        I = I->next;
    }
}

/* search_room trys to find a room in the Exams_list
 *
 * checks every Exam in Exams_list the Classroom_list associated to it
 * if it finds it
 *      returns 1
 * if it doesnt
 *      returns 0
*/
int search_room(Exams_list head, Classroom room) {
    Classroom_list copy;
    int num = 0;

    while(head->next != NULL) {
        head = head->next;
        copy = head->data.classrooms;
        while(copy->next != NULL) {
            copy = copy->next;
            if((copy->data.letter == room.letter) && (copy->data.floor == room.floor) && (copy->data.room == room.room))
                num = 1;
        }   
    }
    return num;
}

/* compares 2 Times "a" and "b" 
 *
 * if "a" and "b" are the same returns 0
 * if "a" is after b returns -1
 * if "a" if before b returns 1
*/
int compare_hours(Time a,Time b) {
    if ((a.hour == b.hour) && (a.minutes == b.minutes))
        return 0; 
    else if ((a.hour > b.hour) || ((a.hour == b.hour) && (a.minutes > b.minutes)))
        return -1;
    else
        return 1;
}

/* compares 2 Dates "a" and "b" 
 *
 * if "a" and "b" are the same returns 0
 * if "a" is after b returns -1
 * if "a" if before b returns 1
*/
int compare_dates(Date a,Date b) {
    if ((a.day==b.day) && (a.month==b.month) && (a.year==b.year))  
        return 0;
    else if ((a.year>b.year) || ((a.year==b.year) && (a.month>b.month)) || ((a.year==b.year) && (a.month==b.month) && (a.day>b.day)))
        return -1;
    else
        return 1;
}

/* search_exam_list searches for a id of a Exam in Exams_list 
 *
 * if it finds it curr will be in the position of the searched Exam
 * if it doesnt find it curr will be NULL
*/
void search_exam_list(Exams_list head, int id, Exams_list *prev, Exams_list *curr) { 
    *prev = head;
    *curr = head->next;
    while((*curr) != NULL && (*curr)->data.id < id) {
        *prev = *curr;
        *curr = (*curr)->next;
    }
    if((*curr) != NULL && (*curr)->data.id != id)
        *curr = NULL;
}

/* append_exam appends to the Exams_list *head the new Exam */
void append_exam(Exams_list *head, Exam new) {
    Exams_list node, prev, useless;

    node = (Exams_list)malloc(sizeof (Exams_node));
    check_memory_elist(node);
    if(node != NULL) {
        node->data = new;
        search_exam_list(*head, new.id, &prev, &useless);
        node->next = prev->next;
        prev->next = node;
    }
}

/* append_classroom appends to the Classroom_list head the new Classroom */
void append_classroom(Classroom_list head, Classroom new) {
    Classroom_list node;

    node = (Classroom_list)malloc(sizeof (Classrooms_node));
    node->data = new;

    while(head->next != NULL)
        head = head->next;
    head->next = node;
    head = node;
    head->next = NULL;
}

/* max_day returns the last day of that specific month
 *
 * (checks if its February and if its a leap year)
*/
int max_day(int year,int month) {
    int max_day;

    if(month == 2) {
        if(year % 4 == 0) {
            max_day = 29;
        } else {
            max_day = 28;
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        max_day = 30;
    } else {
        max_day = 31;
    }

    return max_day;
}

/* exam_type makes the user pick a type for the Exam */
void exam_type(char str[]) {
    char *temp = (char*)malloc(CHAR_SIZE * sizeof(char));

    check_memory_char(temp);
    while(temp[0] != '1' && temp[0] != '2' && temp[0] != '3') { 
        printf("\t\t1.Epoca Normal\n\t\t2.Epoca de Recurso\n\t\t3.Epoca Especial\n\t-->");
        fgets(temp, CHAR_SIZE, stdin);

        switch(temp[0]) {
            case '1':
                strcpy(str, "Epoca Normal");
                break;
            case '2':
                strcpy(str, "Epoca de Recurso");
                break;
            case '3':
                strcpy(str, "Epoca Especial");
                break;
            default:
                printf("\t\tEscolha errada. Tente de novo..\n");
        }
    }
    free(temp);
}

/* possible_hours calculates all the n hours starting at hour:minutes with a 30min space between each
 * possbile hours */ 
void possible_hours(Time time_available[], int n, int hour, int minutes) {
    int i;

    for (i = 0; i < n; i++) {
        time_available[i].hour = hour;
        time_available[i].minutes = minutes;

        if (minutes == 30) {
            hour += 1;
            minutes -= 30;
        } else {
            minutes += 30;
        }
    }
}

/* removes_from_exams_list removes Exam from the Exams_list */
void remove_from_exams_list(Exams_list head, int id) {
    Exams_list prev, curr;

    search_exam_list(head, id, &prev, &curr);
    if(curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}
