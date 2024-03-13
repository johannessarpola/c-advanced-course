#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
#include <math.h>

typedef double (*MathFunction)(double);

int main()
{
    // You can specify the RTLD_LAZY flag to resolve symbols only as needed.
    void *mathLib = dlopen("libm.so.6", RTLD_LAZY);
    if (!mathLib)
    {
        fprintf(stderr, "Error loading math library: %s\n", dlerror());
        return 1;
    }

    // get the pointer to the function
    MathFunction cosFunction = (MathFunction)dlsym(mathLib, "cos");
    const char *error = dlerror();
    if (error != NULL)
    {
        fprintf(stderr, "Error resolving symbol cos: %s\n", error);
        dlclose(mathLib);
        return 1;
    }

    double angle = 123.0;
    double d = cosFunction(angle);
    printf("cos(%f) = %f\n", angle, d);

    // close the library
    dlclose(mathLib);
    return 0;
}