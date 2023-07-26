#include <stdio.h>

// global accessible only within the file
static double file_scope = 1.0;

// global accesible within whole program
float progam_scoped = 2.f;

int main() {
    // an int variable with block scope and temporary storage
    int local_scope_temp = 3;

    // a float local variable with permanent storage
    static float local_permanent = 4;

    // a register int variable
    register int register_variable = 5;
    return 0;

}