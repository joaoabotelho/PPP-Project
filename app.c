#include "student.c"
#include "classes.c"

int main(){ 
        Student_list jabuga = create_students_list();
        new_student(jabuga);
        new_student(jabuga);
        print_student_list(jabuga);
        return 0;
}
