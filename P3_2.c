// Q2. Using Newton Raphson Method, find teh real root of the equation 3x = Cos(x) + 1, correct to 4 decimal places.

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include<stdio.h>
#include<math.h>

float f(float x) {
    return (3*x - cos(x) - 1);
}

float df(float x) {
    return (3 + sin(x));
}

void roots(float x0, float aerr) {
    int itr = 0;

    while (1) {
        if (df(x0) == 0) {
            printf("Newton Raphson Method failed.");
            break;
        }

        float x = x0 - (f(x0)/df(x0));

        printf("%d Iteration: x = %f, f(x) = %f\n", ++itr, x, f(x));

        x0 = x;

        if (fabs(f(x)) <= aerr) {
            printf("Approx root: %f", x);
            break;
        }
    }
}

int main() {
    float a, b, x0, aerr;
    while (1) {
        printf("Enter the values of a and b: ");
        scanf("%f %f", &a, &b);

        if (f(a) < 0 && f(b) > 0) {
            printf("Root lies between %f and %f.\n", a, b);
            
            printf("Enter the value of x0: ");
            scanf("%f", &x0);

            printf("Enter the allowed error: ");
            scanf("%f", &aerr);

            roots(x0, aerr);
            break;
        }
        else {
            printf("Wrong interval.");
        }
    }

    return 0;
}