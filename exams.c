void create_exam(Exams_list head, Classes_list classes){
    Exam new;
    char class_name[50];

    printf("### Esta a criar um novo exame ###\n\n");
    printf("Disciplina em causa\n");
    get_class(&classes); 
    new.subject = classes->data;

    printf("Qual e o tipo do exame?\n");
    type_of_exam(new.type);

    printf("A que dia/mes/ano se realiza o exame?\n(Day)-->"); // YEAR??
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
}
/* FOR REVIEW
int comparedates(Date a,Date b) {
    if ((a.day==b.day) && (a.year==b.year) && (a.year==b.year))
        return 0;
    if ((a.year>b.year) || ((a.year==b.year) && (a.month>b.month)) || ((a.year==b.year) && (a.month==b.month) && (a.day>b.day)))
        return -1; //a mais recente que b
    else
        return 1;
}

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
