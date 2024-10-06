// Aim: To find the solution of linear algebraic equations using
// 1. Gauss Elimination Method.
// 2. Gauss Jordan Method.

// Algorithm:


// Q1. Solve the following system of equations using Gauss Elimination Method:
//		10x1 - 7x2 + 3x3 = 5
//		-6x1 + 8x2 + 4x3 = 7
//		2x1 + 6x2 + 9x3 = -1

// Code:

// Name: Siddharth Pokhriyal
// Section: A1
// University Roll No.: 2219716

#include<stdio.h>
#include<math.h>

int main() {
	int n;
	printf("Enter the order of the required square matrix: ");
	scanf("%d", &n);

	float matrix[n][n+1];
	printf("Enter the elements of the matrix: ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			scanf("%f", &matrix[i][j]);
		}
	}

	for (int i = 0;  i< n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) {
				float c = matrix[i][j] / matrix[j][j];

				for (int k = 0; k <= n; k++) {
					matrix[i][k] = matrix[i][k] - c * matrix[j][k];
				}
			}
		}
	}

	printf("The upper triangular matrix so obtained is,\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			printf("%f ", matrix[i][j]);
		}
		printf("\n");
	}

	float sol[n];
	sol[n - 1] = matrix[n-1][n]/matrix[n-1][n-1];
	for (int i = n - 2; i >= 0; i--) {
		float sum = 0;
		int j;
		for (j = n - 1; j > i; j--) {
			sum += sol[j]*matrix[i][j];
		}
		sol[i] = (matrix[i][n] - sum)/matrix[i][j];
	}

	printf("The solutions to the given system of linear equations is, ");
	for (int i = 0; i < n; i++) {
		printf("%f ", sol[i]);
	}

	return 0;
}