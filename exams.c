#include "header.h"

/* at_the_same_time compares the times of two exams(1 and 2) 
 * to check if they are at the same time
 *
 * returns
 *      sees if the exams start at the same time (b1_b2 == 0)
 *      or
 *      sees if the exams end at the same time (f1_f2 == 0)
 *      or
 *      sees if 2 starts in the middle of 1 (beg2_bt1)
 *      or
 *      sees if 2 ends in the middle of 1 (final2_bt1)
*/
int at_the_same_time(Time beg1, Time final1, Time beg2, Time final2) {
    int b1_b2, f1_b2, f2_b1, f1_f2;
    int final2_bt1;
    int beg2_bt1;

    b1_b2 = compare_hours(beg1,beg2);
    f1_f2 = compare_hours(final1, final2);
    f1_b2 = compare_hours(final1, beg2);
    f2_b1 = compare_hours(beg1, final2);

    beg2_bt1 = (b1_b2 == 1) && (f1_b2 == -1);
    final2_bt1 = (f2_b1 == 1) && (f1_f2 == -1);

    return final2_bt1 || beg2_bt1 || (b1_b2 == 0) || (f1_f2 == 0);
}
 
/* check_same_dates compares the dates of the Exams in head to a Date(date)
 * and append to the list *node the Exams that have the same Date
 *
 * it goes through all the Exams in head and if they have the same date
 * appends the Exam to *node
*/
void check_same_dates(Exams_list head, Exams_list *node, Date date) {
    while(head->next != NULL) {
        head = head->next;

        if(compare_dates(head->data.date, date) == 0)
            append_exam(node, head->data);
    }
} 

/* check_same_time compares the dates of the Exams in head to a beginning(time)
 * of a exam and a end(final)
 * and appends to the list *node the Exams that are at_the_same_time
 *
 * it goes through all the Exams in head and if same_time is true
 * appends the Exam to *node
*/   
void check_same_time(Exams_list head, Exams_list *node, Time time, Time final) {
    Time beg_exam, final_exam;
    int same_time;

    while(head->next != NULL) {
        head = head->next;
        beg_exam = head->data.time;
        final_exam = head->data.final;
        same_time = at_the_same_time(beg_exam, final_exam, time, final);

        if(same_time) {
            append_exam(node, head->data);
        }
    }
}

/* chose_room creates a new Classroom that isnt ocuppied by another Exam
 *
 * asks the user wich room they wish 
 * checks if it is ocuppied(search_room)
 * if it is, asks the user again for another room
*/
void chose_room(Exams_list head, Classroom *new) {
    char *temp = (char*)malloc(CHAR_SIZE * sizeof(char));
    check_memory_char(temp);

    do {
        printf("\tBloco?\n\t-->");
        fgets(temp, CHAR_SIZE, stdin);  
        strncpy(&(*new).letter, temp, 1);

        printf("\tPiso?\n\t-->");
        fgets_int(&(*new).floor);

        printf("\tSala?\n\t-->");
        fgets_int(&(*new).room);

        if(search_room(head, *new) == 1) 
            printf("Essa sala esta ocupada. Por favor escolha outra.\n");
    } while(search_room(head, *new) == 1);
    free(temp);
}    

/* possible_room sees what rooms are occupied in a certain Date and Time and
 * saves them in cnode
 *
 * first sees what Exams have the same Date and saves them in node
 *
 * then sees in node wich exams are at the same time and saves them in cnode
 * prints cnode
 * asks the user to name a Classroom(chose_room)
 *
 * and appends that Classroom that is available to Classroom_list exam_room
*/
void possible_room(Exams_list head, Date date, Time time, Time final, Classroom_list exam_room) {
    Exams_list node = create_exams_list(); 
    Exams_list cnode = create_exams_list(); 
    Exams_list copy;
    Classroom new;
   
    check_same_dates(head, &node, date); 

    if(node->next != NULL) {
        check_same_time(node, &cnode, time, final); 
        copy = cnode; 

        if(cnode->next != NULL) 
            printf("### Estas salas estao ocupadas ###\n");
        while(cnode->next != NULL) {
            cnode = cnode->next;
            print_classroom_list(cnode->data.classrooms); 
            printf("-------------------\n"); 
        }

        chose_room(copy, &new);
    } else 
        chose_room(cnode, &new);

    append_classroom(exam_room, new);
}

/* exam_time asks the user for a possible Time
 *
 * saves the possible times in time_available
 * prints time_available with a number associated with each time
 * and asks the user for the number he wants
 *
 * and saves the Time *time that he wants
*/
void exam_time(Time *time, int n, int hour, int minutes) {
    Time time_available[n];
    int i;

    do {
        possible_hours(time_available, n, hour, minutes); 

        printf("\tHoras disponiveis:\n\n");
        for (i = 0; i < n; i++) {
            printf("\t\t%d.\t%d : %d\n", i + 1, time_available[i].hour, time_available[i].minutes);
        }

        printf("\t-->");
        fgets_int(&i);
    } while(i > n || i <  1);

    (*time).hour = time_available[i-1].hour;
    (*time).minutes = time_available[i-1].minutes;
}

/* create_exam creates a new Exam to append in Exams_list head
 *
 * first requests to use a Class in Classes_list classes to associate that Exam
 * to that Class (new.subject)
 *
 * then it gets the global variable EXAM_ID to associate a id to the
 * exam(new.id)
 *
 * asks the user wich exam_type they want(new.type)
 *
 * asks for the Date that the Exam is going to occur(new.date)
 * 
 * asks for the Time when the Exam starts (new.time) and the duration of the
 * Exam (new.duration)
 *
 * calculates when the Exam ends(new.final)
 *
 * creates a new Student_list for the Students to submit for this new Exam
 * (new.student_submitted)
 *
 * creates a new Classroom_list for the Classrooms that the exam is going to
 * take place
 * and asks the user to asign the first Classroom 
 *
 * appends the new Exam to the Exams_list head and adds 1 to the global
 * variable EXAM_ID
*/
void create_exam(Exams_list head, Classes_list classes) {
    Exam new;
    Exams_list copy = head;

    printf("%d\n", EXAM_ID);
    if (classes->next != NULL) {
        printf("\n\n### Esta a criar um novo exame ###\n\n");
        request_class(&classes); 
        new.subject = &classes->data;

        new.id = EXAM_ID + 1;

        printf("\tQual e o tipo do exame?\n");
        new.type = (char*)malloc(CHAR_SIZE * sizeof(char));
        check_memory_char(new.type);
        exam_type(new.type); 

        printf("\tA que dia/mes/ano se realiza o exame?");
        do {
            printf("\n\t(Year)-->");
            fgets_int(&new.date.year);
        } while(new.date.year < CURRENT_YEAR);

        do {
            printf("\n\t(Month)-->");
            fgets_int(&new.date.month);
        } while(new.date.month < 1 || new.date.month > 12);
    
        do {
            printf("\n\t(Day)-->");
            fgets_int(&new.date.day); 
        } while(new.date.day < 1 || new.date.day > max_day(new.date.year, new.date.month));

        printf("\n\tA que horas?\n\n");
        exam_time(&new.time, 19, 9, 0); 

        printf("\n\tDuracao?\n\n");
        exam_time(&new.duration, 6, 0 ,30); 

        new.final.hour = new.time.hour + new.duration.hour;
        new.final.minutes = new.time.minutes + new.duration.minutes;
        if (new.final.minutes == 60) {
            new.final.minutes = 0;
            new.final.hour += 1;
        }

        new.students_submitted = create_students_list();

        new.classrooms = create_classroom_list();
        possible_room(copy, new.date, new.time, new.final, new.classrooms); 
        
        append_exam(&head, new);
        printf("\nExame Criado.");
        EXAM_ID++;
    } else {
        printf("\tNao existem disciplinas na base de dados.");
    }
}

/* request_exam asks the user wich Exam they want
 *
 * prints the Exams_list head
 * and asks the user for the id number associated to the Exam he wants
 * 
 * searchs for the exam
 * if it doesnt exist repeats the process
*/
void request_exam(Exams_list head, Exams_list *prev, Exams_list *curr) {
    int num;

    do {
        print_exams_list(head);
        printf("\tExame em causa (n de exame)\n-->");
        fgets_int(&num);
        search_exam_list(head, num, prev, curr);     
        if(*curr == NULL)
            printf("Nao existem nenhum exame com esse id. Tente de novo.");
    } while(*curr == NULL);
}

/* print_classrooms prints the Classroom_list of a Exam
 *
 * first asks the user wich Exam he wants
 *
 * prints the Classroom_list of that Exam
 */
void print_classrooms(Exams_list head) {
    Exams_list curr, prev;

    if(head->next != NULL) {
        request_exam(head, &prev, &curr);
        print_classroom_list(curr->data.classrooms); 
    } else {
        printf("\t Nao existem exames na base de dados");
    }
}
