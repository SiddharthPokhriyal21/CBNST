// Q3. Parabolic Curve Fitting


// Code:


// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716


#include <stdio.h> 
void gaussianElimination(int n, double matrix[n][n + 1], double solution[n]) 
{ 
for (int i = 0; i < n - 1; i++) 
{ 
for (int j = i + 1; j < n; j++) 
{ 
            double ratio = matrix[j][i] / matrix[i][i]; 
            for (int k = i; k < n + 1; k++) 
            { 
                matrix[j][k] -= ratio * matrix[i][k]; 
            } 
        } 
    } 
 
    for (int i = n - 1; i >= 0; i--) 
    { 
        solution[i] = matrix[i][n]; 
        for (int j = i + 1; j < n; j++) 
        { 
            solution[i] -= matrix[i][j] * solution[j]; 
        } 
        solution[i] /= matrix[i][i]; 
    } 
} 
 
int main() 
{ 
    int numPoints; 
    printf("Enter the number of data points: "); 
    scanf("%d", &numPoints); 
 
    double x[numPoints], y[numPoints]; 
    printf("Enter the x and y values:\n"); 
    for (int i = 0; i < numPoints; i++) 
    { 
 
        scanf("%lf %lf", &x[i], &y[i]); 
    } 
 
    double sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0; 
    double sumY = 0, sumXY = 0, sumX2Y = 0; 
 
    for (int i = 0; i < numPoints; i++) 
    { 
        sumX += x[i]; 
        sumX2 += x[i] * x[i]; 
        sumX3 += x[i] * x[i] * x[i]; 
        sumX4 += x[i] * x[i] * x[i] * x[i]; 
        sumY += y[i]; 
        sumXY += x[i] * y[i]; 
        sumX2Y += x[i] * x[i] * y[i]; 
    } 
 
    double matrix[3][4] = { 
        {numPoints, sumX, sumX2, sumY}, 
        {sumX, sumX2, sumX3, sumXY}, 
        {sumX2, sumX3, sumX4, sumX2Y}}; 
 
    double coefficients[3]; 
    gaussianElimination(3, matrix, coefficients); 
 
    printf("\nThe fitted parabolic curve is: y = %.2lfx^2 + %.2lfx + %.2lf\n", 
           coefficients[2], coefficients[1], coefficients[0]); 
 
    return 0; 
} 
