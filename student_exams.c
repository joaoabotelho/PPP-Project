void check_student_exams(Student_exams_list head, Student st) {
    Student_exams_list useless, curr;

    if(head->next != NULL) {
        search_student_exams_list(head, *st.numb, &useless, &curr);
        if(curr == NULL)
            append_student_exams_wOrder(&head, st); 
    } else {
        append_student_exams_wOrder(&head, st);
    }
}

int eligble_for_exam(Exam ex, Student st) {
    const int LAST_YEAR = 3;

    if(strncmp(ex.type, "Epoca Especial", 14) == 0) {
        if((strncmp(st.regime, "Normal", 6) == 0) && (*st.year != LAST_YEAR)) {
            printf("\tEste aluno não está elegivel para este exame.");
            return 1;
        } else return -1;  
    } else return -1;
}

void append_exam_stex_list(Student_exams_list head, Student st, Exam new) {
    Student_exams_list useless, curr;

    search_student_exams_list(head, *st.numb, &useless, &curr);
    append_exam(&curr->data.submited, new);
}

void submit_students(Student_list all, Exams_list head, Student_exams_list connect) {
    const int MAX_ROOM_CAPACITY = 30;
    int num_students;
    Student_list copy_st = all;
    Exams_list copy_ex = head, prev, current;
    Student_exams_list copy_st_ex = connect;
    Student_list submited, useless, curr;

    if(head->next != NULL && all->next != NULL) {
        printf("\n\n### Esta a querer submeter um aluno a um exame ###/n/n");
        search_exam(head, &prev, &current);

        what_student(&all);

        if(eligble_for_exam(current->data, all->data) == 1)
            submit_students(copy_st, copy_ex, copy_st_ex);

        check_student_exams(connect, all->data); 
        submited = current->data.students_submited;

        if(current->data.students_submited->next == NULL) { 
            append_student_wOrder(&submited, all->data);
            append_exam_stex_list(connect, all->data, current->data);

        } else {
            num_students = size_of_sList(submited);
            search_student_list(submited, *all->data.numb, &useless, &curr);

            if(curr != NULL) {
                printf("\n\tO aluno %d ja esta inscrito neste exame", *all->data.numb);

            } else {
                bubbleSort(submited);
                append_student_wOrder(&submited, all->data);
                append_exam_stex_list(connect, all->data, current->data);

                if(num_students % MAX_ROOM_CAPACITY == 0) {
                    printf("Tem de reservar mais uma sala. Tem neste momento 1 aluno a mais.");
                    possible_room(copy_ex, current->data.date, current->data.time, current->data.final, current->data.classrooms);
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

void print_submited_students(Exams_list head) {
    Student_list submited;
    Exams_list prev, curr;

    if(head->next != NULL) {
        search_exam(head, &prev, &curr);
        submited = curr->data.students_submited;

        if(submited->next != NULL) {
            bubbleSort(submited);
            print_student_list(submited);
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
        what_student(&all);        
        search_student_exams_list(head, *all->data.numb, &prev, &curr);

        if(curr == NULL) {
            printf("O aluno %d nao esta inscrito em exames.", *all->data.numb);
        } else {
            print_exams_list(curr->data.submited);
        } 
    } else {
        printf("Nao existem alunos da base de dados");
    }
}

void remove_submit_students(Exams_list head, Student_exams_list head2) {
    int student_num;
    Student_list copy, submited;
    Student_exams_list useless, curr;
    Exams_list less, current;

    if(head->next != NULL && head2->next != NULL) {
        printf("\n\n### Esta a querer remover a inscricao de um aluno ###\n\n");
        search_exam(head, &less, &current);

        submited = current->data.students_submited;
        copy = current->data.students_submited;
        if(submited->next != NULL) {
            what_student(&submited);

            student_num = *submited->data.numb;

            removes_from_student_list(copy, student_num);
            search_student_exams_list(head2, student_num, &useless, &curr);
            remove_from_exams_list(curr->data.submited, current->data.id); 

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
    Exams_list submited;

    printf("\n\n### Esta a querer apagar um exame ###\n\n");
    search_exam(head, &prev, &curr);

    while(head2->next != NULL) {
        head2 = head2->next;
        submited = head2->data.submited;
        remove_from_exam_list(submited, curr->data.id);
    }
    remove_from_exam_list(head, curr->data.id);
}


