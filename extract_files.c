#include "header.h"

/* add_until adds 2 strings in a *file until it finds a char look
 *
 * while it string1 doesnt have the char look scans the *file saving the scaned
 * string in string2 
 *
 * adds to string1 a space and then adds string1 to string2
 * 
 * returning string1 full until it finds the char look
*/
void add_until(FILE *file, char look, char *string1) {
    char *string2 = (char*)malloc(CHAR_SIZE * sizeof(char)); 
    check_memory_char(string2);

    while(!strchr(string1, look)) {
        fscanf(file, "%s", string2);
        strcat(string1, " ");
        strcat(string1, string2);
    }
    free(string2);
}

/* associate_string scans *file until it finds char look and substitutes the
 * char look for "\n" */
void associate_string(FILE *file, char look, char *string) {
    char *p;

    add_until(file, look, string); 
    p = strchr(string, look);
    *p = 0;
    strcat(string, "\n");
}

/* get_int_file scans a int in *file
 * 
 * first gets the full *string until it finds the char look
 * 
 * and transforms the string into a int associating to *numb
*/
void get_int_file(FILE *file, char look, int *numb, char *string) {

    associate_string(file, look, string);
    *numb = fgets_to_int(string);
}
 
/* get_int_file_fscan scans a int in *file
 * 
 * first scans the first time and saves to string
 * then gets the full *string until it finds the char look
 * 
 * and transforms the string into a int associating to *numb
*/
void get_int_file_fscan(FILE *file, char look, int *numb) {
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));
    check_memory_char(string);

    fscanf(file, "%s", string);
    associate_string(file, look, string);
    *numb = fgets_to_int(string);
    free(string);
}

/* get_string_file scans a string(*change) in *file
 * 
 * first gets the full *string until it finds the char look
 * 
 * and associates the *string to *change
*/
void get_string_file(FILE *file, char look, char **change, char *string) {

    associate_string(file, look, string);
    *change = string;
}

/* get_string_file_fscanscans a string(*change) in *file
 * 
 * first scans the first time and saves to string
 * first gets the full *string until it finds the char look
 * 
 * and associates the *string to *change
*/
void get_string_file_fscan(FILE *file, char look, char **change) {
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));
    check_memory_char(string);

    fscanf(file, "%s", string);
    associate_string(file, look, string);
    *change = string;
}

/* ex_id gets the first line of the file exams.txt
 * that is the value of the global variable 
 *
*/
void ex_id(int *num) {
    FILE *exams;

    exams = fopen("files/exams.txt", "r");
    fscanf(exams, "%d", num);
    fclose(exams);
}

/* ex_classes gets all the information of classes.txt to Classes_list head */
void ex_classes(Classes_list head) {
    FILE *classes;
    Class temp;
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));
    check_memory_char(string);

    classes = fopen("files/classes.txt", "r");

    while(fscanf(classes, "%s", string) != EOF) { 
            get_string_file(classes, ',', &temp.name, string);
             
            get_string_file_fscan(classes, ';', &temp.teacher);
            string = (char*)malloc(CHAR_SIZE * sizeof(char));
            check_memory_char(string);
            append_class(head, temp);
    }
    fclose(classes);
}

/* ex_students gets all the information of student.txt to Student_list head */
void ex_students(Student_list head) {
    FILE *students;
    Student temp;
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));
    check_memory_char(string);


    students = fopen("files/students.txt", "r");

    while(fscanf(students, "%s", string) != EOF) {
        temp.numb = (int *)malloc(sizeof(int));
        check_memory_int(temp.numb);
        get_int_file(students, ',', temp.numb, string);

        temp.course = (char *)malloc(CHAR_SIZE * sizeof(char));
        check_memory_char(temp.course);
        get_string_file_fscan(students, ',', &temp.course);

        temp.year = (int *)malloc(sizeof(int));
        check_memory_int(temp.numb);
        get_int_file_fscan(students, ',', temp.year); 

        temp.regime = (char *)malloc(CHAR_SIZE * sizeof(char));
        check_memory_char(temp.regime);
        get_string_file_fscan(students, ';', &temp.regime);
        
        append_student(&head, temp);
    }
    fclose(students);
    free(string);
}

/* ex_exams gets all the information of exam.txt to Exams_list head associating
 * the Classes and Students submited to each exam */
void ex_exams(Exams_list head, Classes_list *classes, Student_list students) {
    FILE *exams;
    Exam temp;
    Classroom rooms;
    Student_list copy;
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));
    int student_num, i, n; 
    char *p;
    Classes_list copy2;

    check_memory_char(string);
    exams = fopen("files/exams.txt", "r");
    fscanf(exams, "%s", string);

    while(fscanf(exams, "%s", string) != EOF) {
        get_int_file(exams, ',', &temp.id, string);
        string = (char*)malloc(CHAR_SIZE * sizeof(char));
 
        copy2 = *classes;
        fscanf(exams, "%s", string);
        associate_string(exams, ',', string);
        while((strcmp(copy2->data.name, string) != 0) && (copy2->next != NULL))
            copy2 = copy2->next;
        temp.subject = &copy2->data; 
        printf("%s", temp.subject->name);
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
         
        temp.students_submitted = create_students_list();
        for(i = 0; i < n; i++) {
            copy = students;
            get_int_file_fscan(exams, ',', &student_num); 

            while((*copy->data.numb != student_num) && (copy->next != NULL))
                copy = copy->next;
            append_student(&temp.students_submitted, copy->data); 
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
        check_memory_char(string);
    } 
    fclose(exams);
}

/* ex_student_exams gets all the information of student_exams.txt to
 * Student_exams_list head associating all the Students submited to each Exam */
void ex_student_exams(Exams_list exams, Student_list students, Student_exams_list head) {
    FILE *st_exams;
    Student_list useless_st, curr_st;
    Exams_list useless_exam, curr_exam;
    int student_numb, n, i, id_exam;
    char *string = (char*)malloc(CHAR_SIZE * sizeof(char));
    
    check_memory_char(string);
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
    free(string);
}
