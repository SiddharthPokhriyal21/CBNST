// Q2. Simpson's 3/8 Rule.


// Code:


// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include<stdio.h> 
#include<math.h> 

float f(float x) {
    return (1/(1 + x*x));
}

float result(int n, float h, float lower, float upper) {
    float sumNot3 = 0.0;
    float sum3 = 0.0;
    float itr = lower + h;
    
    int i = 1;

    while(i < n-1) {
        (i%3 == 0)? (sum3 += f(itr)): (sumNot3 += f(itr));
        itr += h;
        i++;
    }
    
    float answer = (3*h/8)*((f(lower) + f(upper)) + 3*sumNot3 + 2*sum3);

    return answer;
}

int main() { 
    int n;
    float  upper_limit, lower_limit;
    
    printf("Enter the lower and upper limit of the integral, respectively: ");
    scanf("%f %f", &lower_limit, &upper_limit);
    printf("Enter the number of points: ");
    scanf("%d", &n);

    float h = (upper_limit - lower_limit)/(n-1);
    
    printf("The value of the integral is %f\n", result(n, h, lower_limit, upper_limit));
    
    return 0; 
}