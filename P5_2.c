// Q2. Newton's Forward Interpolation Formula


// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    
    printf("Enter order of matrix\n");
    scanf("%d", &n);
    
    float x[n], y[n][n];

    printf("Enter the values of x: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    
    printf("Enter the values of y: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[0][i]);
    }

    printf("Enter value of X to find\n");
    float findX;
    scanf("%f", &findX);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%f ", y[i][j]);
        }
        printf("\n");
    }

    float a = x[0];
    for (int i = 0; i < n; i++) {
        if (x[i] < findX) {
            a = x[i];
        }
    }

    float u = (findX - a) / (x[1] - x[0]);
    float ans = y[0][0];
    float fact = 1;
    float uu = u;

    for (int i = 1; i < n; i++) {
        fact *= i;
        ans += (uu * y[i][0] / fact);
        uu *= (u - i);
    }
    printf("Solution of x = %f is : %f\n", findX, ans);
}