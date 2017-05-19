void add_until(FILE *file, char look, char *string1) {
    char *string2 = (char*) malloc (CHAR_SIZE * sizeof(char)); 

    while(!strchr(string1, look)) {
        fscanf(file, "%s", string2);
        strcat(string1, " ");
        strcat(string1, string2);
    }
}

void associate_string(FILE *file, char look, char *string) {
    char *p;

            add_until(file, look, string); 
            p = strchr(string, look);
            *p = 0;
            strcat(string, "\n");
}

void ex_classes(Classes_list head){
    FILE *classes;
    Class temp;
    char *string = (char*) malloc (CHAR_SIZE * sizeof(char));
    char *p;

    classes = fopen("files/classes.txt", "r");

    while(fscanf(classes, "%s", string) != EOF) { 
            associate_string(classes, ',', string);
            temp.name = string;
            string = (char*) malloc (CHAR_SIZE * sizeof(char));
             
            fscanf(classes, "%s", string);
            associate_string(classes, ';', string);
            temp.teacher = string;

            append_class(head, temp);
            string = (char*) malloc (CHAR_SIZE * sizeof(char));
    }
    fclose(classes);
}

void ex_id(int *num) {
    FILE *exams;

    exams = fopen("files/exams.txt", "r");
    fscanf(exams, "%d", num);
    fclose(exams);
}
