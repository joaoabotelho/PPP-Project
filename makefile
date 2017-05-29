run: exec
	    ./exec
			 
exec: app.c student.c exams.c extract_files.c import_files.c helpers.c student_exams.c classes.c lists/class_list.c lists/exam_list.c lists/student_exams_list.c lists/student_list.c
	    gcc app.c student.c exams.c extract_files.c import_files.c helpers.c student_exams.c classes.c lists/class_list.c lists/exam_list.c lists/student_exams_list.c lists/student_list.c -ansi -Wall -o exec && ./exec
