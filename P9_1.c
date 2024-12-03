// Aim:
// 1. To implement Linear Curve Fitting.
// 2. To implement Parabolic Curve Fitting.
// 3. To find out the regression lines.

// Algorithm:

// Q1. 

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include <stdio.h> 
#include <math.h> 
#define MAX_ITER 100 
#define TOLERANCE 1e-6 
void gauss_seidel(double A[2][2], double B[2], double X[2]) 
{ 
    int iter = 0; 
    double x_old[2], diff; 
 
    X[0] = 0; 
    X[1] = 0; 
 
    do 
    { 
        x_old[0] = X[0]; 
        x_old[1] = X[1]; 
 
        X[0] = (B[0] - A[0][1] * X[1]) / A[0][0]; 
        X[1] = (B[1] - A[1][0] * X[0]) / A[1][1]; 
 
        diff = fabs(X[0] - x_old[0]) + fabs(X[1] - x_old[1]); 
        iter++; 
    } while (diff > TOLERANCE && iter < MAX_ITER); 
 
    if (iter == MAX_ITER) 
    { 
        printf("Gauss-Seidel did not converge\n"); 
    } 
} 
 
int main() 
{ 
    int n, i; 
    double x[100], y[100]; 
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0; 
    double A[2][2], B[2], X[2]; 
 
    printf("Enter the number of data points: "); 
    scanf("%d", &n); 
 
    printf("Enter x and y values:\n"); 
    for (i = 0; i < n; i++) 
    { 
        scanf("%lf %lf", &x[i], &y[i]); 
        sum_x += x[i]; 
        sum_y += y[i]; 
        sum_xy += x[i] * y[i]; 
        sum_x2 += x[i] * x[i]; 
    } 
 
    A[0][0] = n; 
    A[0][1] = sum_x; 
    A[1][0] = sum_x; 
    A[1][1] = sum_x2; 
 
    B[0] = sum_y; 
    B[1] = sum_xy; 
 
    gauss_seidel(A, B, X); 
 
    printf("The best-fit line is: y = %.4f + %.4fx\n", X[0], X[1]); 
 
    return 0; 
}