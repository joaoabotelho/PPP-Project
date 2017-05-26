#ifndef __header__h_
#define __header__h_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

static int EXAM_ID;
#define CHAR_SIZE 50
#define LAST_YEAR 3
#define MAX_ROOM_CAPACITY 30

typedef struct student {
    int *numb;
    char *course;
    int *year;
    char *regime;
} Student;

typedef struct node *Student_list;
typedef struct node {
    Student data;
    Student_list next;
} Student_node;

typedef struct class{
    char *name;
    char *teacher;
} Class;

typedef struct cnode *Classes_list;
typedef struct cnode {
    Class data;
    Classes_list next;
} Classes_node;

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
    int id;
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

typedef struct student_exams {
    Student a;
    Exams_list submited;
} Student_exams;

typedef struct senode *Student_exams_list;
typedef struct senode {
    Student_exams data;
    Student_exams_list next;
} Student_exams_node;

/* Helpers */
void check_memory_char(char *string);
void check_memory_int(int *numb);
int fgets_to_int(char *temp);
void fgets_int(int *numb);
char check_answer();
void confirm_answer(char print[], int *numb, char str[]);

/* List Student */
Student_list create_students_list();
void search_student_list(Student_list head, int student_numb, Student_list *prev, Student_list *curr);
void removes_from_student_list(Student_list head, int student_numb);
void append_student(Student_list *head, Student new);
void print_student_list(Student_list head);
void regime(char str[]);
void swap(Student_list a, Student_list b);
void bubble_sort(Student_list head);
int size_of_student_list(Student_list head);

/* List Classes */
Classes_list create_classes_list();
void search_classes_list(Classes_list head, Class search, Classes_list *prev, Classes_list *curr);
void removes_from_classes_list(Classes_list head, Class remv);
void print_classes_list(Classes_list head);
void request_class(Classes_list *head);
void append_class(Classes_list head, Class new);

/* List Exams */
Exams_list create_exams_list();
Classroom_list create_classroom_list();
void print_classroom_list(Classroom_list head);
void print_exams_list(Exams_list head);
int search_room(Exams_list head, Classroom room);
int compare_hours(Time a,Time b);
int compare_dates(Date a,Date b);
void search_exam_list(Exams_list head, int id, Exams_list *prev, Exams_list *curr);
void remove_from_exam_list(Exams_list head, int id);
void append_exam(Exams_list *head, Exam new);
void append_classroom(Classroom_list head, Classroom new);
void exam_type(char str[]);
void possible_hours(Time time_available[], int n, int hour, int minutes);
void remove_from_exams_list(Exams_list head, int id);

/* List Student-Exams */
Student_exams_list create_student_exams_list();
void search_student_exams_list(Student_exams_list head, int student_numb, Student_exams_list *prev, Student_exams_list *curr);
void append_student_exams(Student_exams_list *head, Student st);

/* Student */
int already_exist(Student_list head, int student_numb);
void new_student(Student_list head);
void request_student(Student_list *head);
void change_slist_data(Student_list head);
void remove_student_data(Student_list head);

/* Class */
void new_class(Classes_list head);
void change_classes_data(Class* cls); 
void change_clist_data(Classes_list *head);
void remove_class_data(Classes_list head);

/* Exam */
void check_same_dates(Exams_list head, Exams_list *node, Date date);
int at_the_same_time(Time beg1, Time final1, Time beg2, Time final2);
void check_same_time(Exams_list head, Exams_list *node, Time time, Time final);
void chose_room(Exams_list head, Classroom *new);
void possible_room(Exams_list head, Date date, Time time, Time final, Classroom_list exam_room);
void exam_time(Time *time, int n, int hour, int minutes);
void create_exam(Exams_list head, Classes_list classes);
void search_exam(Exams_list head, Exams_list *prev, Exams_list *curr);
void print_classrooms(Exams_list head);

/* Student-Exams */
void check_student_exams(Student_exams_list head, Student st);
int eligble_for_exam(Exam ex, Student st);
void append_exam_stex_list(Student_exams_list head, Student st, Exam new);
void submit_students(Student_list all, Exams_list head, Student_exams_list connect);
void print_submited_students(Exams_list head);
void print_exams_of_student(Student_exams_list head, Student_list all);
void remove_submit_students(Exams_list head, Student_exams_list head2);
void delete_exam(Exams_list head, Student_exams_list head2);

/* Extract from files */
void add_until(FILE *file, char look, char *string1);
void associate_string(FILE *file, char look, char *string);
void get_int_file(FILE *file, char look, int *numb, char *string);
void get_int_file_fscan(FILE *file, char look, int *numb);
void get_string_file(FILE *file, char look, char **change, char *string);
void get_string_file_fscan(FILE *file, char look, char **change);
void ex_id(int *num);
void ex_classes(Classes_list head);
void ex_students(Student_list head);
void ex_exams(Exams_list head, Classes_list *classes, Student_list students);
void ex_student_exams(Exams_list exams, Student_list students, Student_exams_list head);

/* Import to files */
void imp_classes(Classes_list head);
void imp_students(Student_list head);
void print_exam_info(Exam head, FILE *exams);
void imp_exams(Exams_list head);
void imp_student_exams(Student_exams_list head);

#endif /* __header_h_ */

