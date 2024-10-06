// Aim: To find the real root of an algebraic expression using Bisection Method.

// Algorithm:

// Bisection Method:
// 1. Choose x0 and x1 such that f(x0)*f(x1) < 0.
// 2. Bisect [x0, x1] into two halves as [x0, x] and [x, x1], using x = (x0 + x1)/2.
// 3. If f(x) = 0, stop and print the value of x (root).
// 4. If f(x0)*f(x) < 0, set x1 = x, else if f(x)*f(x1) < 0, set x0 = x.
// 5. Repeat the process until the given number of iterations or derived accuracy.
// 6. Print the root of the equation i.e., x.

// Q1. f(x) = x^3 - x + 1, find the real root of the equation using Bisection Method, correct upto 4 decimal places.

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include<stdio.h>
#include<math.h>

float f(float x) {
   // return (x*log10(x) - 1.2);
    return (x*x*x - x + 1);
}

void roots(float x0, float x1, float x, float aerr){
    int itr = 1;
    do {
        x = (x0 + x1)/2;
        printf("%d Iteration: x = %f, f(x) = %f\n", itr, x, f(x));

        itr++;
        if(fabs(f(x)) == 0) {
            printf("Exact root = %f\n", x);
            break;
        } else if(f(x) > 0) {
            x1 = x;
        } else {
            x0 = x;
        }
    } while(fabs(x1 - x0) > aerr);
    printf("Approximate root = %.4f\n", x);
}

int main() {
    float x0, x1, x, aerr;
    int flag = 0;

    do {
        printf("\nEnter the value of x1 and x2:\n");
        scanf("%f %f", &x0, &x1);

        if(f(x0) * f(x1) < 0) {
            printf("Root lies between %f and %f.\n", x0, x1);
            printf("Enter the allowed error: ");
            scanf("%f", &aerr);
            roots(x0, x1, x, aerr);    
            flag = 1;
        } else {
            printf("Wrong intervals.\n");
        }
    } while(!flag);

    return 0;
}