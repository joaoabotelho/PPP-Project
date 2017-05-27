#include "header.h"

/* check_student_exams  */
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

int eligble_for_exam(Exam ex, Student st) {

    if(strncmp(ex.type, "Epoca Especial", 14) == 0) {
        if((strncmp(st.regime, "Normal", 6) == 0) && (*st.year != LAST_YEAR)) {
            printf("\tEste aluno não está elegivel para este exame.");
            return 1;
        } else return 0;  
    } else return 0;
}

void append_exam_stex_list(Student_exams_list head, Student st, Exam new) {
    Student_exams_list useless, curr;

    search_student_exams_list(head, *st.numb, &useless, &curr);
    append_exam(&curr->data.submitted, new);
}

void submit_students(Student_list all, Exams_list head, Student_exams_list connect) {
    int num_students;
    Exams_list copy_ex = head, prev, current;
    Student_list submitted, useless, curr;

    if(head->next != NULL && all->next != NULL) {
        printf("\n\n### Esta a querer submeter um aluno a um exame ###/n/n");
        search_exam(head, &prev, &current);

        request_student(&all);

        if(eligble_for_exam(current->data, all->data) != 1) {

            check_student_exams(connect, all->data); 
            submitted = current->data.students_submitted;

            if(submitted->next == NULL) { 
                append_student(&submitted, all->data);
                append_exam_stex_list(connect, all->data, current->data);
                printf("%d\n", *all->data.numb);
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
        search_exam(head, &prev, &curr);
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

void remove_submit_students(Exams_list head, Student_exams_list head2) {
    int student_num;
    Student_list copy, submitted;
    Student_exams_list useless, curr;
    Exams_list less, current;

    if(head->next != NULL && head2->next != NULL) {
        printf("\n\n### Esta a querer remover a inscricao de um aluno ###\n\n");
        search_exam(head, &less, &current);

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

void delete_exam(Exams_list head, Student_exams_list head2) {
    Exams_list curr, prev;
    Exams_list submitted;

    printf("\n\n### Esta a querer apagar um exame ###\n\n");
    search_exam(head, &prev, &curr);

    while(head2->next != NULL) {
        head2 = head2->next;
        submitted = head2->data.submitted;
        remove_from_exam_list(submitted, curr->data.id);
    }
    remove_from_exam_list(head, curr->data.id);
}
