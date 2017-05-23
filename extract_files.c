#include "header.h"

void add_until(FILE *file, char look, char *string1) {
    char *string2 = (char*) malloc (CHAR_SIZE * sizeof(char)); 

    while(!strchr(string1, look)) {
        fscanf(file, "%s", string2);
        strcat(string1, " ");
        strcat(string1, string2);
    }
}

void associate_string(FILE *file, char look, char *string) {
    char *p;

    add_until(file, look, string); 
    p = strchr(string, look);
    *p = 0;
    strcat(string, "\n");
}

void get_int_file(FILE *file, char look, int *numb, char *string) {

    associate_string(file, look, string);
    *numb = fgets_to_int(string);
}
 

void get_int_file_fscan(FILE *file, char look, int *numb) {
    char *string = (char*) malloc (CHAR_SIZE * sizeof(char));

    fscanf(file, "%s", string);
    associate_string(file, look, string);
    *numb = fgets_to_int(string);
}

void get_string_file(FILE *file, char look, char **change, char *string) {

    associate_string(file, look, string);
    *change = string;
}

void get_string_file_fscan(FILE *file, char look, char **change) {
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));

    fscanf(file, "%s", string);
    associate_string(file, look, string);
    *change = string;
}

void ex_id(int *num) {
    FILE *exams;

    exams = fopen("files/exams.txt", "r");
    fscanf(exams, "%d", num);
    fclose(exams);}

void ex_classes(Classes_list head) {
    FILE *classes;
    Class temp;
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));

    classes = fopen("files/classes.txt", "r");

    while(fscanf(classes, "%s", string) != EOF) { 
            get_string_file(classes, ',', &temp.name, string);
             
            get_string_file_fscan(classes, ';', &temp.teacher);
            string = (char*)malloc(CHAR_SIZE * sizeof(char));

            append_class(head, temp);
    }
    fclose(classes);
}

void ex_students(Student_list head) {
    FILE *students;
    Student temp;
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));

    students = fopen("files/students.txt", "r");

    while(fscanf(students, "%s", string) != EOF) {
        temp.numb = (int *)malloc(sizeof(int));
        get_int_file(students, ',', temp.numb, string);

        temp.course = (char *)malloc(CHAR_SIZE * sizeof(char));
        get_string_file_fscan(students, ',', &temp.course);

        temp.year = (int *)malloc(sizeof(int));
        get_int_file_fscan(students, ',', temp.year); 

        temp.regime = (char *)malloc(CHAR_SIZE * sizeof(char));
        get_string_file_fscan(students, ';', &temp.regime);
        
        append_student(&head, temp);
    }
    fclose(students);
}

void ex_exams(Exams_list head, Classes_list *classes, Student_list students) {
    FILE *exams;
    Exam temp;
    Classroom rooms;
    Student_list copy;
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));
    int student_num, i, n; 
    char *p;

    ex_id(&EXAM_ID);
    exams = fopen("files/exams.txt", "r");
    fscanf(exams, "%s", string);

    while(fscanf(exams, "%s", string) != EOF) {
        get_int_file(exams, ',', &temp.id, string);
        string = (char*)malloc(CHAR_SIZE * sizeof(char));
 
        fscanf(exams, "%s", string);
        associate_string(exams, ',', string);
        while((strcmp((*classes)->data.name, string) != 0) && ((*classes)->next != NULL))
            *classes = (*classes)->next;
        temp.subject = &(*classes)->data; 
        string = (char*)malloc(CHAR_SIZE * sizeof(char));
        
        fscanf(exams, "%s", string);
        add_until(exams, ',', string); 
        p = strchr(string, ',');
        *p = 0;
        temp.type = string;
 
        get_int_file_fscan(exams, '/', &temp.date.day); 
        get_int_file_fscan(exams, '/', &temp.date.month); 
        get_int_file_fscan(exams, ',', &temp.date.year); 
  
        get_int_file_fscan(exams, ':', &temp.time.hour); 
        get_int_file_fscan(exams, ',', &temp.time.minutes); 
  
        get_int_file_fscan(exams, ':', &temp.duration.hour); 
        get_int_file_fscan(exams, ',', &temp.duration.minutes); 
  
        get_int_file_fscan(exams, ':', &temp.final.hour); 
        get_int_file_fscan(exams, ';', &temp.final.minutes); 
  
        get_int_file_fscan(exams, ';', &n); 
         
        temp.students_submited = create_students_list();
        for(i = 0; i < n; i++) {
            copy = students;
            get_int_file_fscan(exams, ',', &student_num); 

            while((*copy->data.numb != student_num) && (copy->next != NULL))
                copy = copy->next;
            append_student(&temp.students_submited, copy->data); 
        }
        
        get_int_file_fscan(exams, ';', &n); 
        
        temp.classrooms = create_classroom_list(); 
        for(i = 0; i < n; i++) {

            get_string_file_fscan(exams, '.', &p);
            rooms.letter = *p;

            get_int_file_fscan(exams, '.', &rooms.floor); 
            get_int_file_fscan(exams, ';', &rooms.room); 

            append_classroom(temp.classrooms, rooms);
        }
        append_exam(&head, temp); 
        string = (char*)malloc(CHAR_SIZE * sizeof(char));
    } 
    fclose(exams);
}

void ex_student_exams(Exams_list exams, Student_list students, Student_exams_list head) {
    FILE *st_exams;
    Student_list useless_st, curr_st;
    Exams_list useless_exam, curr_exam;
    int student_numb, n, i, id_exam;
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));


    st_exams = fopen("files/student_exams.txt", "r");

    while(fscanf(st_exams, "%s", string) != EOF) {
        get_int_file(st_exams, ';', &student_numb, string);
        search_student_list(students, student_numb, &useless_st, &curr_st);
        append_student_exams(&head, curr_st->data);

        get_int_file_fscan(st_exams, ';', &n);
        for(i = 0; i < n; i++) {
            get_int_file_fscan(st_exams, ',', &id_exam);
            search_exam_list(exams, id_exam, &useless_exam, &curr_exam);
            append_exam_stex_list(head, curr_st->data, curr_exam->data); 
        } 
    }
    fclose(st_exams);
}
