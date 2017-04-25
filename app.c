#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "base.c"
#include "student.c"
#include "classes.c"

int main(){ 
        Student_list jabuga = create_students_list(),lala;
        new_student(jabuga);
        new_student(jabuga);
        new_student(jabuga);
        print_student_list(jabuga);
        //lala = sort_student(jabuga);
        //print_student_list(lala);
        change_list_data(jabuga);
        print_student_list(jabuga);
        return 0;
}
