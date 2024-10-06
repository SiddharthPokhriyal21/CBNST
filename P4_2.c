// Q2. Solve the following system of equations using Gauss Jordan Method:
//		6X - Y + Z = 13
//		X + Y + Z = 9
//		10X + Y - Z = 19


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

	float matrix[n][n + 1];
	printf("Enter the elements of the matrix: ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			scanf("%f", &matrix[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) {
				float c = matrix[i][j] / matrix[j][j];

				for (int k = 0; k <= n; k++) {
					matrix[i][k] = matrix[i][k] - c * matrix[j][k];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				float c = matrix[i][j] / matrix[j][j];

				for (int k = 0; k <= n; k++) {
					matrix[i][k] = matrix[i][k] - c * matrix[j][k];
				}
			}
		}
	}

	printf("The diagonal matrix so obtained is,\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			printf("%f ", matrix[i][j]);
		}
		printf("\n");
	}

	float sol[n];
	for (int i = n - 1; i >= 0; i--) {
		sol[i] = matrix[i][n] / matrix[i][i];
	}


	printf("The solutions to the given system of linear equations is, ");
	for (int i = 0; i < n; i++) {
		printf("%f ", sol[i]);
	}

	return 0;
}