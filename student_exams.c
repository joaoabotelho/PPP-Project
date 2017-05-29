#include "header.h"

/* check_student_exams checks if there is the Student st in the list Student_exams_list
 * head
 *
 * if the list head is empty 
 *      the Student st is added to the list
 *  if the list head isnt empty
 *     checks if the Student st is in the list head
 *     if it isnt in the list head the Student is added to the list
*/
void check_student_exams(Student_exams_list head, Student st) {
    Student_exams_list useless, curr;

    if(head->next != NULL) {
        search_student_exams_list(head, *st.numb, &useless, &curr);
        if(curr == NULL)
            append_student_exams(&head, st); 
    } else {
        append_student_exams(&head, st);
    }
}

/* eligble_for_exam checks if the Student is eligble for the Exam ex
 * 
 * if the Exam has the type Epoca Especial
 *      and if the Student has the regime Normal and has the year different to
 *      the LAST_YEAR (the Student isnt eligble for the Exam)
 *          prints "Este aluno nao esta elegivel para este exame."
 *          and returns 1
 *      else the Student is eligble to the Exam so it returns 0
 * else the Exam doesnt have any special condition so it returns 0
*/
int eligble_for_exam(Exam ex, Student st) {

    if(strncmp(ex.type, "Epoca Especial", 14) == 0) {
        if((strncmp(st.regime, "Normal", 6) == 0) && (*st.year != LAST_YEAR)) {
            printf("\tEste aluno nao esta elegivel para este exame.");
            return 1;
        } else return 0;  
    } else return 0;
}

/* append_exam_stex_list appends a Exam to the Student st in Student_exams_list
 * head
 *
 * it looks for the Student in head returning curr(place in list where the
 * Student is)
 *
 * appends the Exam to the Exam_list(submitted) in the struct Student_exams
*/
void append_exam_stex_list(Student_exams_list head, Student st, Exam new) {
    Student_exams_list useless, curr;

    search_student_exams_list(head, *st.numb, &useless, &curr);
    append_exam(&curr->data.submitted, new);
}

/* submit_students submits a Student to a Exam
 *
 * if the Exams list and the Student list arent empty
 *      asks the user which Exam they want
 *      asks the user which Student they want
 *      checks if the Student is eligble for the Exam(eligble_for_exam)
 *      if it is
 *         checks if the Student is already in Student_exams_list
 *         checks if the Student_list students_submitted associated to the Exam is empty
 *         if it is
 *              appends the Student to the Student_list
 *              students_submitted(append_student)
 *              and appends to the Student_exams_list connect associating
 *              the Student to the Exam(append_exam_stex_list)
 *         if it isnt 
 *              searches for the Student in Student_list students_submitted 
 *              if it finds it it means this Student is already submitted to the Exam
 *              sorts the list(bubble_sort) and appends to the Student_list
 *              students_submitted and appends to the Student_exam_list connect
 *              asssociating the Student to the Exam(append_exams_stex_list)
 *
 *              at the end checks if there are 31 Students submitted to the
 *              Exam if there are it mears the Classroom is full so asks the
 *              user to name another room
*/
void submit_students(Student_list all, Exams_list head, Student_exams_list connect) {
    int num_students;
    Exams_list copy_ex = head, prev, current;
    Student_list submitted, useless, curr;

    if(head->next != NULL && all->next != NULL) {
        printf("\n\n### Esta a querer submeter um aluno a um exame ###/n/n");
        request_exam(head, &prev, &current);

        request_student(&all);

        if(eligble_for_exam(current->data, all->data) != 1) {

            check_student_exams(connect, all->data); 
            submitted = current->data.students_submitted;

            if(submitted->next == NULL) { 
                append_student(&submitted, all->data);
                append_exam_stex_list(connect, all->data, current->data);
            } else {
                num_students = size_of_student_list(submitted);
                search_student_list(submitted, *all->data.numb, &useless, &curr);

                if(curr != NULL) {
                    printf("\n\tO aluno %d ja esta inscrito neste exame", *all->data.numb);
                } else {
                    bubble_sort(submitted);
                    append_student(&submitted, all->data);
                    append_exam_stex_list(connect, all->data, current->data);

                    if(num_students % MAX_ROOM_CAPACITY == 0) {
                        printf("Tem de reservar mais uma sala. Tem neste momento 1 aluno a mais.");
                        possible_room(copy_ex, current->data.date, current->data.time, current->data.final, current->data.classrooms);
                    }
                }
            }
        }
    } else {
        if(head->next == NULL)
            printf("\tNao exitem exames na base de dados\n");
        if(all->next == NULL)
            printf("\tNao existem alunos na base de dados\n");
    }
}

void print_submitted_students(Exams_list head) {
    Student_list submitted;
    Exams_list prev, curr;

    if(head->next != NULL) {
        request_exam(head, &prev, &curr);
        submitted = curr->data.students_submitted;

        if(submitted->next != NULL) {
            bubble_sort(submitted);
            print_student_list(submitted);
        } else {
            printf("\nNao existem alunos inscritos");
        }
    } else {
        printf("\nNao existem exames.");
    }
}

/* print_exams_of_student prints the Exams signed in of a Student 
 *
 * asks the user which Student he wants(request_student)
 * searches the Student_exams_list for that student
 *
 * if it doesnt find it prints "O aluno (number of the Student) nao esta
 * inscrito em exames"
 *
 * if it does find it prints the Exam_list associated to the Student
*/
void print_exams_of_student(Student_exams_list head, Student_list all) {
    Student_exams_list prev, curr;

    if(all->next != NULL){
        printf("\n\n### Quer ver a lista de exames que um aluno se inscreveu ###\n\n");
        request_student(&all);        
        search_student_exams_list(head, *all->data.numb, &prev, &curr);

        if(curr == NULL) {
            printf("O aluno %d nao esta inscrito em exames.", *all->data.numb);
        } else {
            print_exams_list(curr->data.submitted);
        } 
    } else {
        printf("Nao existem alunos da base de dados");
    }
}

/* remove_submit_students removes a Student from the Student_list associated to
 * a Exam and removes that same Exam from the Student_exams_list associated to
 * that Student
 *
 *  first asks the user for the Exam he wants
 *  then asks for the Student they wish in the Student_list student_submitted associated to the
 *  Exam
 *
 *  removes from that list that Student(removes_from_student_list)
 *  searches for that Student in Student_exams_list head2
 *  and removes the Exam in the Exams_list associated to that
 *  Student(remove_from_exams_list)
*/
void remove_submit_students(Exams_list head, Student_exams_list head2) {
    int student_num;
    Student_list copy, submitted;
    Student_exams_list useless, curr;
    Exams_list less, current;

    if(head->next != NULL && head2->next != NULL) {
        printf("\n\n### Esta a querer remover a inscricao de um aluno ###\n\n");
        request_exam(head, &less, &current);

        submitted = current->data.students_submitted;
        copy = current->data.students_submitted;
        if(submitted->next != NULL) {
            request_student(&submitted);

            student_num = *submitted->data.numb;

            removes_from_student_list(copy, student_num);
            search_student_exams_list(head2, student_num, &useless, &curr);
            remove_from_exams_list(curr->data.submitted, current->data.id); 

            printf("O aluno %d ja nao esta inscrito no exame de %s", student_num, current->data.subject->name); 
        } else {
            printf("Nao existem alunos inscritos neste exame.");
        }
    } else {
        if(head->next == NULL)
            printf("Nao existem exames na base de dados");
        if(head2->next == NULL)
            printf("Nao existem alunos inscritos em exames na base de dados");
    }
}

/* delete_exam deletes a Exam from the Exams_list 
 *
 * asks the user which Exam they want(request_exam)
 *
 * goes through each node in Student_exams_list to remove that Exam on each
 * Exams_list(remove_from_exam_list)
 *
 * then removes the Exam in the Exams_list(remove_from_exam_list)
*/ 
void delete_exam(Exams_list head, Student_exams_list head2) {
    Exams_list curr, prev;
    Exams_list submitted;

    printf("\n\n### Esta a querer apagar um exame ###\n\n");
    request_exam(head, &prev, &curr);

    while(head2->next != NULL) {
        head2 = head2->next;
        submitted = head2->data.submitted;
        remove_from_exams_list(submitted, curr->data.id);
    }
    remove_from_exams_list(head, curr->data.id);
}

/* pass_date_exams deletes all the exams that already have been done
 * 
 * goes through the Exams_list head
 *      if it finds a Exam which has a Date before the current_date
 *           goes through the Student_exams_list head2 deleting that Exam in every
 *           Exams_list submitted
 *           then removes the Exam from the Exams_list head 
*/
void pass_date_exams(Exams_list head, Student_exams_list head2) {
    Exams_list copy = head;
    Student_exams_list copy2;
    Date current_date;
    int i = 0;

    current_date.day = CURRENT_DAY;
    current_date.month = CURRENT_MONTH;
    current_date.year = CURRENT_YEAR;
    
    while(copy->next != NULL) {
        copy = copy->next;
        if(compare_dates(copy->data.date, current_date) == 1) {
            copy2 = head2;            
            while(copy2->next != NULL) {
                copy2 = copy2->next;
                remove_from_exams_list(copy2->data.submitted, copy->data.id);
            }
            remove_from_exams_list(head, copy->data.id);
            i++;
        }
    }
    printf("%d exames foram apagados por ja terem sido realizados", i);

}
