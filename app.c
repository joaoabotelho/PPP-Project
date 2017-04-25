#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.c"

int main(){ 
        Student_list jabuga = create_students_list();
        new_student(jabuga);
        new_student(jabuga);
        print_student_list(jabuga);
        return 0;
}
