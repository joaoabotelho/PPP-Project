void ex_classes(Classes_list head){
    FILE *classes;
    Class temp;
    char *string = (char*) malloc (CHAR_SIZE * sizeof(char));
    char *p;

    classes = fopen("files/classes.txt", "r");

    while(fscanf(classes, "%s", string) != EOF) {
            p = strchr(string, ',');
            *p = 0;
            temp.name = string;
            
            string = (char*) malloc (CHAR_SIZE * sizeof(char));

            fscanf(classes, "%s", string);
            temp.teacher = string;
            append_class(head, temp);

            string = (char*) malloc (CHAR_SIZE * sizeof(char));
    }
    fclose(classes);
}
