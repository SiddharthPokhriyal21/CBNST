// Aim:
// 1. To implement Euler's Method.
// 2. To implement Runge-Kutta Method.

// Algorithm:

// Q1. Given that dy/dx = x + y with y = 1 at x = 0, find y approximately for x = 1 using Euler’s Method.

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include<stdio.h>
#include<math.h>
float func(float x,float y){
    return x+y;
}
int main(){
    float x0,y0,xn,slope,yn;
    int n;
    printf("Enter the value of x0\n");
    scanf("%f",&x0);
    printf("Enter the value of y0\n");
    scanf("%f",&y0);
    printf("Enter the calculating point\n");
    scanf("%f",&xn);
    printf("Enter Number of steps\n");
    scanf("%d",&n);
    float h=(xn-x0)/n;
    for(int i=0;i<n;i++){
        slope=func(x0,y0);
        yn=y0+h*slope;
        printf("value of y0=%f for x0=%f at iteration %d is %f at slope=%f\n",y0,x0,i+1,yn,slope);
        y0=yn;
        x0=x0+h;
    }
    printf("The final value yn at xn %f is %f\n",xn,yn);
    return 0;
}
