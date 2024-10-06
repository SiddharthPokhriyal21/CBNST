// Aim:
// 1. To find the solution of linear algebraic equations using Gauss Seidel Method.
// 2. To find the value of f(x) using Newton's Forward Interpolation Formula.

// Algorithm:


// Q1. Solve the following system of equations using Gauss Seidel Method:
//		10X + Y + 2Z = 44
//		2X + 10Y + Z = 51
//		X + 2Y + Z = 61

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include<stdio.h>
#include<math.h>

int main() {
	float aerr;
	int n;
	printf("Enter the order of the matrix: ");
	scanf("%d", &n);

	float matrix[n][n+1];
	int flag = 0;

	printf("Enter the elements of the matrix: ");
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n+1; j++) {
			scanf("%f", &matrix[i][j]);
			if (i != j && j != n) {
				sum += matrix[i][j];
			}
		}
		if (matrix[i][i] < sum) {
			printf("The system of equations doesn't converge.");
			flag = 1;
			break;
		}
	}
	if(!flag) {
		printf("Enter the allowed error: ");
		scanf("%f", &aerr);
		float result[n];
		float prev_result[n];

		for (int i = 0; i < n; i++) {
			result[i] = 0;
		}

		int itr = 1;
		while (1) {
			for (int i = 0; i < n; i++) {
				prev_result[i] = result[i];
				result[i] = matrix[i][n];
				for (int j = 0; j < n; j++) {
					if (i != j) {
						result[i] -= matrix[i][j] * result[j];
					}
				}
				result[i] /= matrix[i][i];
			}
			printf("Iteration %d: ", itr++);
			for (int i = 0; i < n; i++) {
				printf("%f\t", result[i]);
			}
			printf("\n");

			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (fabs(fabs(result[i]) - fabs(prev_result[i])) < aerr) {
					flag = 1;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		
		printf("The solution to the system of equations is: ");
		for (int i = 0; i < n; i++) {
			printf("%f\t", result[i]);
		}
	}

	return 0;
}