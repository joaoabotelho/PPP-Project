// FOR REVIEW
int comparedates(Date a,Date b) {
    if ((a.day==b.day) && (a.year==b.year) && (a.year==b.year))
        return 0;
    if ((a.year>b.year) || ((a.year==b.year) && (a.month>b.month)) || ((a.year==b.year) && (a.month==b.month) && (a.day>b.day)))
        return -1; /*a mais recente que b*/
    else
        return 1;
}

int comparehours(Time a,Time b)
{
    if ((a.hour==b.hour) && (a.minutes==b.minutes))
        return 0;
    if ((a.hour>b.hour) || ((a.hour==b.hour) && (a.minutes>b.minutes)))
        return -1;
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
}
