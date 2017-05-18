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
    Student_list copy_st = all;
    Exams_list copy_ex = head;
    Student_exams_list copy_st_ex = connect;
    Student_list useless, curr;
    int num_students;
    const int MAX_ROOM_CAPACITY = 30;

    printf("\n\n### Esta a querer submeter um aluno a um exame ###/n/n");
    search_exam(&head);

    what_student(&all);

    if(eligble_for_exam(head->data, all->data) == 1)
        submit_students(copy_st, copy_ex, copy_st_ex);

    check_student_exams(connect, all->data); 

    if(head->data.students_submited->next == NULL) { 
        append_student_wOrder(&head->data.students_submited, all->data);
        append_exam_stex_list(connect, all->data, head->data);

    } else {
        num_students = size_of_sList(head->data.students_submited);
        search_student_list(head->data.students_submited, *all->data.numb, &useless, &curr);

        if(curr != NULL) {
            printf("\n\tO aluno %d ja esta inscrito neste exame", *all->data.numb);

        } else {
            bubbleSort(head->data.students_submited);
            append_student_wOrder(&head->data.students_submited, all->data);
            append_exam_stex_list(connect, all->data, head->data);

            if(num_students % MAX_ROOM_CAPACITY == 0) {
                printf("Tem de reservar mais uma sala. Tem neste momento 1 aluno a mais.");
                possible_room(copy_ex, head->data.date, head->data.time, head->data.final, head->data.classrooms);
            }
        }
   }
}

void print_submited_students(Exams_list head) {
    if(head->next != NULL) {
        search_exam(&head);
        bubbleSort(head->data.students_submited);
        print_student_list(head->data.students_submited);
    } else {
        printf("Nao existe alunos inscritos");
    }
}

void print_exams_of_student(Student_exams_list head, Student_list all) {
    Student_exams_list prev, curr;

    printf("\n\n### Quer ver a lista de exames que um aluno se inscreveu ###\n\n");
    what_student(&all);        
    search_student_exams_list(head, *all->data.numb, &prev, &curr);
    
    if(curr == NULL) {
        printf("O aluno %d nao esta inscrito em exames.", *all->data.numb);
    } else {
        print_exams_list(curr->data.submited);
    } 
}

void remove_submit_students(Exams_list head, Student_exams_list head2) {
    Student_list copy;
    Student_exams_list useless, curr;
    int student_num;
    
    printf("\n\n### Esta a querer remover a inscricao de um aluno ###\n\n");
    search_exam(&head);
    
    copy = head->data.students_submited;
    what_student(&head->data.students_submited);
    
    student_num = *head->data.students_submited->data.numb;

    removes_from_student_list(copy, student_num);
    search_student_exams_list(head2, student_num, &useless, &curr);
    remove_from_exams_list(curr->data.submited, head->data.date, head->data.time); 

    printf("O aluno %d ja nao esta inscrito no exame de %s", student_num, head->data.subject->name); 
}
