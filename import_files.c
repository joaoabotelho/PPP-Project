void imp_classes(Classes_list head) {
    FILE *classes;
    char *p;

    classes = fopen("files/classes.txt", "w");
    while(head->next != NULL) {
        head = head->next; 
        p = strchr(head->data.name, '\n');
        *p = '\0';
        fprintf(classes, "%s,", head->data.name);
        p = strchr(head->data.teacher, '\n');
        *p = '\0';
        fprintf(classes," %s;\n", head->data.teacher);
    }
    fclose(classes);
}

void imp_students(Student_list head) {
    FILE *students;
    char *p;

    students = fopen("files/students.txt", "w");
    while(head->next != NULL) {
        head = head->next;

        fprintf(students, "%d,", *head->data.numb);

        p = strchr(head->data.course, '\n');
        *p = '\0';
        fprintf(students, " %s,", head->data.course);
 
        fprintf(students, " %d,", *head->data.year);

        fprintf(students, " %s;\n", head->data.regime); 
    }
    fclose(students);
}

void imp_exams(Exams_list head) {
    FILE *exams;
    Student_list students, copy;
    Classroom_list rooms, copy_class;
    int i;

    exams = fopen("files/exams.txt", "w");
    fprintf(exams, "%d", EXAM_ID);

    while(head->next != NULL) {
        head = head->next;
        i = 0;

        fprintf(exams, "\n%d, ", head->data.id);
        fprintf(exams, "%s, ", head->data.subject->name);
        fprintf(exams, "%s, ", head->data.type);
        fprintf(exams, "%d/ ", head->data.date.day);
        fprintf(exams, "%d/ ", head->data.date.month);
        fprintf(exams, "%d, ", head->data.date.year);
        fprintf(exams, "%d: ", head->data.time.hour);
        fprintf(exams, "%d, ", head->data.time.minutes);
        fprintf(exams, "%d: ", head->data.duration.hour);
        fprintf(exams, "%d, ", head->data.duration.minutes);
        fprintf(exams, "%d: ", head->data.final.hour);
        fprintf(exams, "%d;\n", head->data.final.minutes);

        students = head->data.students_submited;
        copy = students;
        while(copy->next != NULL) {
            copy = copy->next;
            i++;
        } 
        fprintf(exams, "%d;", i);
        while(students->next != NULL) {
            students = students->next;
            fprintf(exams, " %d,", *students->data.numb);
        }
        
        i = 0;
        rooms = head->data.classrooms;
        copy_class = rooms;
        while(copy_class->next != NULL) {
            copy_class = copy_class->next;
            i++;
        }
        fprintf(exams, "\n%d;", i);
        while(rooms->next != NULL) {
            rooms = rooms->next;
            fprintf(exams, " %c.", rooms->data.letter);
            fprintf(exams, " %d.", rooms->data.floor);
            fprintf(exams, " %d;", rooms->data.room);
        }
    }
    fclose(exams);
}

void imp_student_exams(Student_exams_list head) {
    FILE *st_exams;
    int n;
    Exams_list copy;
    
    st_exams = fopen("files/student_exams.txt", "w");

    while(head->next != NULL) {
        head = head->next;
        
        fprintf(st_exams, "%d; ", *head->data.a.numb);
        
        copy = head->data.submited;
        n = 0;
        while(copy->next != NULL) {
            copy = copy->next;
            n++;
        }
        fprintf(st_exams, "%d;", n);

        while(head->data.submited->next != NULL) {
            head->data.submited = head->data.submited->next;
            fprintf(st_exams, " %d,", head->data.submited->data.id);
        }
        fprintf(st_exams, "\n");
    }
    fclose(st_exams);
}


