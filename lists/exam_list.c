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
    float numb;
    char letter;
} Classroom;

typedef struct rnode *Classroom_list;
typedef struct rnode {
    Classroom data;
    Classroom_list next;
} Classrooms_node;

typedef struct exam {
    char type[50];
    Class subject;
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
    if(aux != NULL){
        aux->data = null;
        aux->next = NULL;
    }
    return aux;
}

Classroom_list create_classroom_list() {
    Classroom_list aux;
    Classroom null;

    aux = (Classroom_list) malloc (sizeof (Classrooms_node));
    if(aux != NULL){
        aux->data = null;
        aux->next = NULL;
    }
    return aux;
}
void print_classroom_list(Classroom_list head) {
    Classroom_list I = head->next;

    while(I){
        printf("Sala--> %c %f\n", I->data.letter, I->data.numb);
        I=I->next;
    }

}

void print_exams_list(Exams_list head) {
    Exams_list I = head->next;

    while(I){
        printf("%s\n", I->data.type);
        printf("Nome da Disciplina--> %s\n", I->data.subject.name);
        printf("Docente da Disciplina--> %s\n", I->data.subject.teacher);
        printf("Data do exame--> %d / %d / %d\n", I->data.date.day, I->data.date.month, I->data.date.year);
        printf("Hora do exame--> %d : %d\n", I->data.time.hour, I->data.time.minutes);
        printf("Duracao do exame--> %d : %d\n", I->data.duration.hour, I->data.duration.minutes);
//        printf("Lista de salas do exame\n\n");
  //      print_classroom_list(I->data.classrooms);
        I = I->next;
    }
}

void append_exam(Exams_list head, Exam new) {
    Exams_list node;

    node = (Exams_list) malloc (sizeof (Exams_node));
    node->data = new;

    while(head->next != NULL)
        head = head->next;
    head->next = node;
    head = node;
    head->next = NULL;
}

int comparehours(Time a,Time b) {

    if ((a.hour == b.hour) && (a.minutes == b.minutes))
        return 0; // "a" = "b"
    else if ((a.hour > b.hour) || ((a.hour == b.hour) && (a.minutes > b.minutes)))
        return -1; // "a" after "b"
    else
        return 1; // "b" after "a"
}

void type_of_exam(char str[]) {
    char temp[50];

    printf("1.Epoca Normal\n2.Epoca de Recurso\n3.Epoca Especial\n-->");
    fgets(temp,50,stdin);

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
            printf("Wrong choice. Enter again.\n");
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

void possible_room(Exams_list head, Date date, Time time, Time final, Classroom_list *exam_room) {
    Exams_list node = create_exams_list();;
    Exams_list cnode = create_exams_list();

    while(head->next != NULL) {
        if((head->data.date.day == date.day) && (head->data.date.month == date.month) && (head->data.date.year == date.year)) 
            append_exam(node, head->data);
        head = head->next;
    
    }
    while(node->next != NULL) {
        if(((comparehours(node->data.time, time) == 1) && (comparehours(node->data.final, time) == -1)) || ((comparehours(node->data.time, final) == 1) && (comparehours(node->data.final, final) == -1)) || (comparehours(node->data.time, time) == 0) || (comparehours(node->data.final, final) == 0)) {
            append_exam(cnode, node->data);
            node = node->next;
        }
    }

    
}
