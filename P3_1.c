// Aim: To find the real root of an algebraic expression using
// 1. Secant Method.
// 2. Newton Raphson Method.

// Algorithm:

// Secant Method:
// 1. Read the values of x0 and x1 as the range that are required for beginning the first iteration.
// 2. Calculate the value of x as:
//        x = x1 - [(x1 - x0)/(f(x1) - f(x0))]*f(x1)
// 3. Put x0 = x1 and x1 = x for further iterations. Repeat the process unless two successive values of x come equal.
// 4. Print the root of the equation, i.e., x.

// Q1. A real root of the given equation f(x) = x^3 - 5x + 1 lies in the interval (0, 1). Find it using Secant Method.

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include<stdio.h>
#include<math.h>

float f(float x) {
    return (x*x*x - 5*x + 1);
}

void roots(float x0, float x1, float aerr) {
    int itr = 0;
    
    while (1) {
        if (f(x0) == f(x1)) {
            printf("Secant Method failed.");
            break;
        }
        
        float x = x1 - (f(x1)*(x1 - x0)/(f(x1) - f(x0)));

        printf("%d Iteration: x = %f, f(x) = %f\n", ++itr, x, f(x));

        x0 = x1;
        x1 = x;

        if (fabs(f(x1)) <= aerr) {
            printf("Exact root: %f", x);
            break;
        }
    }
}

int main() {
    float x0, x1, aerr;

    printf("Enter the values of x0 and x1: ");
    scanf("%f %f", &x0, &x1);
    printf("Root lies between %f and %f.\n", x0, x1);

    printf("Enter the allowed error: ");
    scanf("%f" ,&aerr);

    roots(x0, x1, aerr);

    return 0;
}