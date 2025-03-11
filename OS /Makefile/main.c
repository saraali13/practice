#include <stdio.h>
#include "add.h"
#include "subtract.h"

//contains the main func with execution of all the functions in other .c file (classesone either)
int main() {
    int a = 10, b = 5;
    printf("Addition: %d\n", add(a, b));
    printf("Subtraction: %d\n", subtract(a, b));
    return 0;
}
