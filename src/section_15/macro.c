#define OU 3.14

#define PRNT(a,b)\
    printf("value 1 = %d\n", a); \
    printf("value 2 = %d\n", b);

#define CIRCLE_AREA(x) ((3.14) * (x) * (x));
#define BAD_CIRCLE_AREA(x) (3.14 * x * x);


// Fancy way of printing e.g count = 10;
// # gives you a means to create a character string out of a macro argument
#define printint(var) \
    printf(#var" = %i\n", var);

static inline void printInline(int a, int b) {
    printf("value 1 = %d\n", a);
    printf("value 2 = %d\n", b);
}

int main() {

    int a = 10;
    int b = 15;

    PRNT(a,b); // This get replaces by the preprocessor with the macro definition
    /*
    printf("value 1 = %d\n", a);
    printf("value 2 = %d\n", b);
    */

   printInline(a, b);

    float area = CIRCLE_AREA(4);
    int areaInt = CIRCLE_AREA(4);
    float correct = CIRCLE_AREA(2 * 2);
    float correct2 = CIRCLE_AREA(3 + 1); // works because (x) is enclosed in ( )

    printf("area(f): %.2f\n", area);
    printf("area(i): %d\n", areaInt);
    printf("correct(f): %.2f\n", correct);
    printf("correct2(f): %.2f\n", correct2);

    float wrong = BAD_CIRCLE_AREA(3 + 1); // doesn't work because no parentheses around (x) and operator precedence gets mixd up
    printf("wrong(f): %.2f\n", wrong); 

    int count = 10;
    printint(count);


    return 0;
}