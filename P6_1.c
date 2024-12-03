// Aim:
// 1. To find the value of f(x) using Newton's Backward Interpolation Formula.
// 2. To find the value of f(x) using Gauss' Forward Interpolation Formula.
// 3. To find the value of f(x) using Lagrange's Interpolation Formula.

// Algorithm:

// Q1. Solve the following system of equations using Newton's Backward Interpolation Formula:

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include<stdio.h> 
#include<math.h> 
float u_cal(float u, int n){ 
    float temp = u; 
    for (int i = 1; i < n; i++) 
        temp = temp * (u + i); 
    return temp; 
} 
int factorial(int x){ 
    int fact=1; 
    for(int i=1;i<=x;i++){ 
        fact*=i; 
    } 
    return fact; 
} 
int main(){ 
    int n; 
    printf("Enter No. of Observations: "); 
    scanf("%d",&n); 
    float x[n],y[n][n]; 
    float x1; 
    printf("Enter the value: "); 
    scanf("%f",&x1); 
    printf("Enter the Values of x and y\n"); 
    for(int i=0;i<n;i++){ 
        scanf("%f %f",&x[i],&y[i][0]); 
    } 
    float h=x[1]-x[0]; 
    float u=(x1-x[n-1])/h; 
    //calculate Backward difference table 
    for (int j = 1; j < n; j++)  
    { 
        for (int i = n - 1; i >= j; i--)  
        { 
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];  
        } 
    } 
    printf("\nBackward Difference Table:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%f", x[i]); 
        for (int j = 0; j <=i; j++) { 
            printf("  %f", y[i][j]); 
        } 
        printf("\n"); 
    } 
    float sum = y[n - 1][0];     
    for (int i = 1; i < n; i++)  
    { 
        sum = sum + (u_cal(u, i) * y[n - 1][i]) / factorial(i); 
    } 
    printf("For the value of x(%f) the value of y is %0.4f",x1,sum); 
    return 0; 
}
