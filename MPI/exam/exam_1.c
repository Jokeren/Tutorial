#include <stdio.h>
#include <string.h>
#define LDA_A 50
#define LDA_B 60
#define LDA_C 100

void sub_matrix_add(int ax, int ay, int lda_a, int A[][lda_a],
		int bx, int by, int lda_b, int B[][lda_b], int row, int col, int **c)
{
	int i, j;
	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			c[i][j] = A[ax + i][ay + j] + B[bx + i][by + j];
		}
	}


	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int A[100][LDA_A];
	int B[100][LDA_B];

	int i, j;
	for (i = 0; i < 100; ++i) {
		for (j = 0; j < LDA_A; ++j) {
			A[i][j] = i + j;
		}
	}

	for (i = 0; i < 100; ++i) {
		for (j = 0; j < LDA_B; ++j) {
			B[i][j] = i + j + 1;
		}
	}

	int sm_x_a, sm_y_a, sm_x_b, sm_y_b, sm_col, sm_row;
	sm_x_a = 5;
	sm_y_a = 6;
	sm_x_b = 7;
	sm_y_b = 8;
	sm_col = 2;
	sm_row = 2;

	int **C;
	C = malloc(sm_row * sizeof(int *));
	for (i = 0; i < sm_col; ++i) {
		C[i] = (int *)malloc(sm_col * sizeof(int));
	}

	sub_matrix_add(sm_x_a, sm_y_a, LDA_A, A, sm_x_b, sm_y_b, LDA_B, B, sm_row, sm_col, C);

	return 0;
}
