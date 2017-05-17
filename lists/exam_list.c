typedef struct date {
    int day;
    int month;
    int year;
} Date;

typedef struct time {
    int hour;
    int minutes;
} Time;

typedef struct classroom {
    char letter;
    int floor;
    int room;
} Classroom;

typedef struct rnode *Classroom_list;
typedef struct rnode {
    Classroom data;
    Classroom_list next;
} Classrooms_node;

typedef struct exam {
    char *type;
    Class *subject;
    Date date;
    Time time;
    Time duration;
    Time final;
    Student_list students_submited;
    Classroom_list classrooms;
} Exam;

typedef struct enode *Exams_list;
typedef struct enode {
    Exam data;
    Exams_list next;
} Exams_node;

Exams_list create_exams_list() {
    Exams_list aux;
    Exam null;

    aux = (Exams_list) malloc (sizeof (Exams_node));
    if(aux != NULL) {
        aux->data = null;
        aux->next = NULL;
    }
    return aux;
}

Classroom_list create_classroom_list() {
    Classroom_list aux;
    Classroom null;

    aux = (Classroom_list) malloc (sizeof (Classrooms_node));
    if(aux != NULL) {
        aux->data = null;
        aux->next = NULL;
    }
    return aux;
}
void print_classroom_list(Classroom_list head) {
    Classroom_list I = head->next;

    while(I) { 
        printf("\tSala--> %c%d.%d\n", I->data.letter, I->data.floor, I->data.room);
        I=I->next;
    }

}

void print_exams_list(Exams_list head) {
    Exams_list I = head->next;
    int i = 1;

    printf("\n\n#### Lista de exames ####");
    while(I) {
        printf("\n\tExame num --> %d\n", i);
        printf("\t%s\n", I->data.type);
        printf("\tNome da Disciplina--> %s\n", I->data.subject->name);
        printf("\tDocente da Disciplina--> %s\n", I->data.subject->teacher);
        printf("\tData do exame--> %d / %d / %d\n", I->data.date.day, I->data.date.month, I->data.date.year);
        printf("\tInicio do exame--> %d : %d\n", I->data.time.hour, I->data.time.minutes);
        printf("\tFim do exame--> %d : %d\n", I->data.final.hour, I->data.final.minutes);
        print_classroom_list(I->data.classrooms);
        printf("\n--------------------\n");
        I = I->next;
        i++;
    }
}

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

int comparehours(Time a,Time b) {
    if ((a.hour == b.hour) && (a.minutes == b.minutes))
        return 0; // "a" = "b"
    else if ((a.hour > b.hour) || ((a.hour == b.hour) && (a.minutes > b.minutes)))
        return -1; // "a" after "b"
    else
        return 1; // "b" after "a"
}

int compare_dates(Date a,Date b) {
    if ((a.day==b.day) && (a.month==b.month) && (a.year==b.year))  
        return 0;
    if ((a.year>b.year) || ((a.year==b.year) && (a.month>b.month)) || ((a.year==b.year) && (a.month==b.month) && (a.day>b.day)))
        return -1;
    else
        return 1;
}

void search_exam_list(Exams_list head, Date date, Time time, Exams_list *prev, Exams_list *curr) {
     
    *prev = head;
    *curr = head->next;
    while(((*curr) != NULL) && ((compare_dates(date, (*curr)->data.date) == -1) || (comparehours(time, (*curr)->data.time)))) {
        *prev = *curr;
        *curr = (*curr)->next;
    }
}

void append_exam(Exams_list head, Exam new) {
    Exams_list node, prev, useless;

    node = (Exams_list) malloc (sizeof (Exams_node));
    if(node != NULL) {
        node->data = new;
        search_exam_list(head, new.date, new.time, &prev, &useless);
        node->next = prev->next;
        prev->next = node;
    }
}

void append_classroom(Classroom_list head, Classroom new) {
    Classroom_list node;

    node = (Classroom_list) malloc (sizeof (Classrooms_node));
    node->data = new;

    while(head->next != NULL)
        head = head->next;
    head->next = node;
    head = node;
    head->next = NULL;
}

void type_of_exam(char str[]) {
    char *temp = (char*) malloc (CHAR_SIZE * sizeof(char));

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
            printf("\t\tWrong choice. Enter again.\n");
            type_of_exam(str);
    }
}

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
