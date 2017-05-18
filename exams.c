void chose_room(Exams_list head, Classroom *new) {
    char *temp = (char*) malloc (CHAR_SIZE * sizeof(char));

    printf("\tBloco?\n\t-->");
    fgets(temp, CHAR_SIZE, stdin); // funcao check_answer para 1 char tirar o print
    strncpy(&(*new).letter, temp, 1);

    printf("\tPiso?\n\t-->");
    fgets_int(&(*new).floor);

    printf("\tSala?\n\t-->");
    fgets_int(&(*new).room);

    if(search_room(head, *new) == 1) {
        printf("Essa sala esta ocupada. Por favor escolha outra.\n");
        chose_room(head, new);
    }
}

void check_same_dates(Exams_list head, Exams_list *node, Date date) {
    while(head->next != NULL) {
        head = head->next;
        if(compare_dates(head->data.date, date) == 0)
            append_exam(*node, head->data);
    }
} 

void check_same_time(Exams_list head, Exams_list *node, Time time, Time final) {
    while(head->next != NULL) {
        head = head->next;
        if(((comparehours(head->data.time, time) == 1) && (comparehours(head->data.final, time) == -1)) || ((comparehours(head->data.time, final) == 1) && (comparehours(head->data.final, final) == -1)) || (comparehours(head->data.time, time) == 0) || (comparehours(head->data.final, final) == 0)) {
            append_exam(*node, head->data);
        }
    }
}    
void possible_room(Exams_list head, Date date, Time time, Time final, Classroom_list exam_room) {
    Exams_list node = create_exams_list();;
    Exams_list cnode = create_exams_list();
    Exams_list copy;
    Classroom new;
   
    check_same_dates(head, &node, date);

    if(node->next != NULL) {
        check_same_time(node, &cnode, time, final);
        copy = cnode; 
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

void time_of_exam(Time *time, int n, int hour, int minutes) {
    Time time_available[n];
    int i;
    
    possible_hours(time_available, n, hour, minutes);
    printf("\tHoras disponiveis:\n\n");
    for (i = 0; i < n; i++) {
        printf("\t\t%d.\t%d : %d\n", i+1, time_available[i].hour, time_available[i].minutes);
    }

    printf("\t-->");
    fgets_int(&i);
    (*time).hour = time_available[i-1].hour;
    (*time).minutes = time_available[i-1].minutes;
}


void create_exam(Exams_list head, Classes_list classes){
    Exam new;
    Exams_list copy = head;
    char *class_name = (char*) malloc (CHAR_SIZE * sizeof(char));

    printf("\n\n### Esta a criar um novo exame ###\n\n");
    get_class(&classes); 
    new.subject = &classes->data;

    printf("\tQual e o tipo do exame?\n");
    new.type = (char*) malloc (CHAR_SIZE * sizeof(char));
    type_of_exam(new.type);

    printf("\tA que dia/mes/ano se realiza o exame?\n\t(Day)-->");
    fgets_int(&new.date.day); 
    printf("\n\t(Month)-->");
    fgets_int(&new.date.month);
    printf("\n\t(Year)-->");
    fgets_int(&new.date.year);

    printf("\n\tA que horas?\n\n");
    time_of_exam(&new.time, 19, 9, 0); 

    printf("\n\tDuracao?\n\n");
    time_of_exam(&new.duration, 6, 0 ,30); 

    new.final.hour = new.time.hour + new.duration.hour;
    new.final.minutes = new.time.minutes + new.duration.minutes;
    if (new.final.minutes == 60) {
        new.final.minutes = 0;
        new.final.hour += 1;
    }

    new.students_submited = create_students_list();

    new.classrooms = create_classroom_list();
    possible_room(copy, new.date, new.time, new.final, new.classrooms);

    append_exam(head, new);
    printf("\nExame Criado.");
}

void search_exam(Exams_list *head) {
    int num, i;

    print_exams_list(*head);
    printf("\tExame em causa (n de exame)\n-->");
    fgets_int(&num);

    for(i = 0; i < num; i++) {
        *head = (*head)->next;
    }
}

void submit_students(Student_list all, Exams_list head) {
    Student_list copy_st = all;
    Student_list useless, curr;
    Exams_list copy_ex = head;
    int num_students = 0;
    const int MAX_ROOM_CAPACITY = 2;

    printf("\n\n### Esta a querer submeter um aluno a um exame ###/n/n");
    search_exam(&head);

    what_student(&all);

    if(strncmp(head->data.type, "Epoca Especial", 14) == 0) {
        if((strncmp(all->data.regime, "Normal", 6) == 0) && (*all->data.year != 3)) {
            printf("\tEste aluno não está elegivel para este exame.");
            submit_students(copy_st, copy_ex);
        }  
    } 

    if(head->data.students_submited->next == NULL) { 
        append_student_wOrder(&head->data.students_submited, all->data);

    } else {
        num_students = size_of_sList(head->data.students_submited);
        search_student_list(head->data.students_submited, *all->data.numb, &useless, &curr);

        if(curr != NULL) {
            printf("\n\tO aluno %d ja esta inscrito neste exame", *all->data.numb);

        } else {
            bubbleSort(head->data.students_submited);
            append_student_wOrder(&head->data.students_submited, all->data);

            if(num_students % MAX_ROOM_CAPACITY == 0) {
                printf("Tem de reservar mais uma sala. Tem neste momento 1 aluno a mais.");
                possible_room(copy_ex, head->data.date, head->data.time, head->data.final, head->data.classrooms);
            }
        }
   }
}

void print_submited_students(Exams_list head) {
    search_exam(&head);
    bubbleSort(head->data.students_submited);
    print_student_list(head->data.students_submited);
}

void print_classrooms(Exams_list head) {
    search_exam(&head);
    print_classroom_list(head->data.classrooms); 
}
