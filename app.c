#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.c"

int main(){ 
        Student_list jabuga = create_students_list();
        Student new1 = new_student();
        Student new2 = new_student();
        append_student(jabuga, new2);
        append_student(jabuga, new1);
        print_student_list(jabuga);
        return 0;
}
