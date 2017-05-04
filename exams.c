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

    printf("### Esta a criar um novo exame ###\n\n");
    printf("Disciplina em causa\n");
    get_class(&classes); 
    new.subject = classes->data;

    printf("Qual e o tipo do exame?\n");
    type_of_exam(new.type);

    printf("A que dia/mes/ano se realiza o exame?\n(Day)-->");
    fgets_int(&new.date.day); 
    printf("\n(Month)-->");
    fgets_int(&new.date.month);
    printf("\n(Year)-->");
    fgets_int(&new.date.year);

    printf("\nA que horas?\n\n");
    time_of_exam(&new.time, 19, 9, 0); 

    printf("\nDuracao?\n\n");
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
/* FOR REVIEW


void remov(Exams_list head)
{
    int day,month,year,hour,minutes;
    Date a0;
    Time a1;
    Exams_list I = head->next;
    Exams_list ant,current;
    ant=I;
    current=I->next;
    printf("### Esta funÁ„o vai remover os dados dos exames passados ###\n\n");
    printf("Introduza a data de hoje.\n");
    printf("Dia:\n");
    scanf("%d",&a.day);
    printf("MÍs:\n");
    scanf("%d",&a.month);
    printf("Ano:\n");
    scanf("%d",&a.year);
    printf("Hora:\n");
    scanf("%d",&a1.hour);
    printf("Minutos:\n");
    scanf("%d",&a1.minutes);
    while (temp!=NULL)
    {
        if (compare(a0,I->data.date)==-1)
        {
            ant->next = current->next;
            free (current);

        }
        if (compare(a0,I->data.date)==0)
        {
            if (comparehours(a0,I->data.time)==-1))
            {
                ant->next = current->next;
                free (current);
            }

        }
        ant=current;
        current=I->next;
        I=I->next;
    }
}*/
