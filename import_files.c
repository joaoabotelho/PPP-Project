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
