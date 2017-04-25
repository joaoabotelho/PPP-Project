// FOR REVIEW
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
    char letter[1];
} Classroom;

typedef struct cnode *Enrolledstd_list;
typedef struct cnode {
    Student data;
    Enrolledstd_list next;
} Enrolledstd_node;

typedef struct cnode *Classrooms_list;
typedef struct cnode {
    Classroom data;
    Classrooms_list next;
} Classrooms_node;

typedef struct exam{
    char type[50];
    Classes subject;
    Date date;
    Time time;
    Time duration;
    Enrolledstd_list students;
    Classrooms_list classrooms;
} Exam;

typedef struct cnode *Exams_list;
typedef struct cnode {
    Exam data;
    Exams_list next;
} Exams_node;

Exams_list create_exams_list(){
    Exams_list aux;
    Exam null;
    aux = (Exams_list) malloc (sizeof (Exams_node));
    if(aux != NULL){
        aux->data = null;
        aux->next = NULL;
    }
    return aux;
}

void print_exams_list(Exams_list head, Enrolledstd_list head1, Classrooms_list head2){
    Exams_list I = head->next;
    while(I){
        printf("Tipo/…poca--> %s\n", I->data.type);
        printf("Nome da Disciplina--> %s\n", I->data.subject.name);
        printf("Docente da Disciplina--> %s\n", I->data.subject.teacher);
        printf("Data do exame--> %d / %d / %d\n", I->data.date.day,data.date.month,data.date.year);
        printf("Hora do exame--> %d : %d\n", I->data.time.hour,data.time.minutes);
        printf("DuraÁ„o do exame--> %d : %d\n", I->data.duration.hour,data.duration.minutes);
        printf("Lista de alunos inscritos-->\n");
        print_enrolledstd_list(head1);
        printf("Lista de salas do exame-->\n");
        print_classrooms_list(head2);
        I = I->next;
    }
}

print_enrolledstd_list(Enrolledstd_list head);
{
    Enrolledstd_list I = head->next;
    while(I){
        printf("Nome do Aluno--> %s\n", I->data.name);
        I=I->next;
    }

}

print_classrooms_list(Classrooms_list head);
{
    Classrooms_list I = head->next;
    while(I){
        printf("Sala--> %s\n", I->data.classrooms.letter,I->data.classrooms.numb);
        I=I->next;
    }

}

void append_class(Exams_list head, Exam new){
    Exams_list node;
    node = (Exams_list) malloc (sizeof (Exams_node));
    node->data = new;
    while(head->next != NULL)
        head = head->next;
    head->next = node;
    head = node;
    head->next = NULL;
}
