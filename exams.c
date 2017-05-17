void chose_room(Exams_list head, Classroom *new) {   
    char temp[50];

    printf("Bloco?\n");
    fgets(temp,50,stdin); // funcao check_answer para 1 char tirar o print
    strncpy(&(*new).letter, temp, 1);

    printf("Piso?\n");
    fgets_int(&(*new).floor);

    printf("Sala?\n");
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

void create_exam(Exams_list head, Classes_list classes){
    Exam new;
    Exams_list copy = head;
    char class_name[50];

    printf("\n\n### Esta a criar um novo exame ###\n\n");
    printf("\tDisciplina em causa\n");
    get_class(&classes); 
    new.subject = &classes->data;

    printf("\tQual e o tipo do exame?\n");
    type_of_exam(new.type);

    printf("\tA que dia/mes/ano se realiza o exame?\n(Day)-->");
    fgets_int(&new.date.day); 
    printf("\n\t\t(Month)-->");
    fgets_int(&new.date.month);
    printf("\n\t\t(Year)-->");
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
    Exams_list copy_ex = head;
    int num, i, student_numb;

    printf("\n\n### Esta a querer submeter um aluno a um exame ###/n/n");
    search_exam(&head);

    what_student(&all);

    if(strncmp(head->data.type, "Epoca Especial", 14) == 0) {
        if((strncmp(all->data.regime, "Normal", 6) == 0) && (all->data.year != 3)) {
            printf("\tEste aluno não está elegivel para este exame.");
            submit_students(copy_st, copy_ex);
        }  
    } 
    
    append_student_wOrder(head->data.students_submited, all->data); 
    print_student_list(head->data.students_submited); 
}
