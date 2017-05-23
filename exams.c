void check_same_dates(Exams_list head, Exams_list *node, Date date) {
    while(head->next != NULL) {
        head = head->next;

        if(compare_dates(head->data.date, date) == 0)
            append_exam(node, head->data);
    }
} 

int at_the_same_time(Time beg1, Time final1, Time beg2, Time final2) {
    int b1_b2, f1_b2, f2_b1, f1_f2;
    int final2_bt1;
    int beg2_bt1;

    b1_b2 = comparehours(beg1,beg2);
    f1_f2 = comparehours(final1, final2);
    f1_b2 = comparehours(final1, beg2);
    f2_b1 = comparehours(beg1, final2);

    beg2_bt1 = (b1_b2 == 1) && (f1_b2 == -1);
    final2_bt1 = (f2_b1 == 1) && (f1_f2 == -1);

    return final2_bt1 || beg2_bt1 || (b1_b2 == 0) || (f1_f2 == 0);
}
    
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

/* Gets data of room */
void chose_room(Exams_list head, Classroom *new) {
    char *temp = (char*) malloc (CHAR_SIZE * sizeof(char));

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
}    

/* Sees what rooms are available at the time of the exam in question  */
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

/* Says what times are available to the user 
and makes the user choose a time for the exam */
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

void create_exam(Exams_list head, Classes_list classes) {
    Exam new;
    Exams_list copy = head;

    if (classes->next != NULL) {
        printf("\n\n### Esta a criar um novo exame ###\n\n");
        get_class(&classes); 
        new.subject = &classes->data;

        new.id = EXAM_ID + 1;

        printf("\tQual e o tipo do exame?\n");
        new.type = (char*) malloc (CHAR_SIZE * sizeof(char));
        exam_type(new.type); 

        printf("\tA que dia/mes/ano se realiza o exame?\n\t(Day)-->");
        fgets_int(&new.date.day); 
        printf("\n\t(Month)-->");
        fgets_int(&new.date.month);
        printf("\n\t(Year)-->");
        fgets_int(&new.date.year);

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

        new.students_submited = create_students_list();

        new.classrooms = create_classroom_list();
        possible_room(copy, new.date, new.time, new.final, new.classrooms); 
        
        append_exam(&head, new);
        printf("\nExame Criado.");
        EXAM_ID++;
    } else {
        printf("\tNao existem disciplinas na base de dados.");
    }
}

void search_exam(Exams_list head, Exams_list *prev, Exams_list *curr) {
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

void print_classrooms(Exams_list head) {
    Exams_list curr, prev;
    if(head->next != NULL) {
    search_exam(head, &prev, &curr);
    print_classroom_list(curr->data.classrooms); 
    } else {
        printf("\t Nao existem exames na base de dados");
    }
}
