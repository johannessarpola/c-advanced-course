//
// Created by johan on 21/08/2023.
//

#include "stdio.h"
int main() {
    char *d_str="first_name,last_name,manager,45";
    char firstname[12],lastname[12],title[12];
    int age = 0;

    // %[^,] defines the string delimeted by ','
    int items = sscanf(d_str, "%[^,],%[^,],%[^,],%d", firstname, lastname, title, &age);

    printf("Items parsed:   %d\n", items);
    printf("Firstname:      %s\n", firstname);
    printf("Lastname:       %s\n", lastname);
    printf("Title:          %s\n", title);
    printf("Age:            %d\n", age);
    return 0;
}