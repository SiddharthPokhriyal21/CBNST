// Q2. Find the real roots of 2x - log10(x) = 7, correct upto 3 decimal places using Iteration Method.

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include<stdio.h>
#include<math.h>

float f(float x) {
    //return (2*x - log10(x) - 7);
    return (x*x*x - 4*x - 9);
}

float q(float x) {
    //return ((log10(x) + 7)/2.0);
    return (pow((4 * x + 9), (1.0 / 3)));
}

float dq(float x) {
    //return (1/(2.0*x));
    return ((4.0 / 3)*pow(4*x + 9, -2.0/3));
}

int main() {
    float x, x1, aerr;
    printf("Enter the initial value of x: ");
    scanf("%f", &x);
    printf("Enter the allowed value of error: ");
    scanf("%f", &aerr);
    
    if (fabs(dq(x)) >= 1) {
        printf("Case not satisfied: |dq(x)| >= 1\n");
        return 0;
    }

    int itr = 1;
    
    while(1) {
        x1 = q(x);
        printf("\n%d Iteration, Value of x is %f.", itr, x1);
        if((fabs(f(x1))) <= aerr) {
            printf("\nThe root of the equation is: %f\n", x1);
            break;
        } else{
            x=x1;
        }

        itr++;
    }
    return 0;
}