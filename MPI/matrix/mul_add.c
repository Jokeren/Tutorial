#include <stdio.h>
#define LDA 50
#define LDB 40 
#define LDC 30

void matrix_add(int row, int col, int (*A)[LDA], int sar, int sac, int (*B)[LDB], int sbr, int sbc, int (*C)[LDC])
{
	int i, j;

	for (i = 0; i < row; ++i) {
		for (j = 0; j < col; ++j) {
			C[i][j] = A[sar + i][sac + j] + B[sbr + i][sbc + j];
		}
	}	
}

int main()
{
	int A[100][LDA];
	int B[130][LDB];
	int C[50][LDC];

	A[10][15] = 1;
	A[11][15] = 2;
	B[10][15] = 2;
	B[11][15] = 2;

	matrix_add(10, 15, A, 10, 15, B, 10, 15, C);

	printf("%d\n", C[0][0]);
	printf("%d\n", C[1][0]);

	return 0;
}
