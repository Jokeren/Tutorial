#include "mpi.h"
#include <stdio.h>
#include <string.h>
#define SIZE 3

/*
 * a is stored as rows
 */
int matrix_a[SIZE][SIZE] = {
	{1, 2, 5}, {3, 4, 6}, {8, 9, 11}
};
/* 
 * b is stored as rows
 */
int matrix_b[SIZE][SIZE] = {
	{5, 1, 8}, {2, 4, 1}, {1, 8, 9}
};
int matrix_c[SIZE][SIZE];

void matrix_mul(int rank, int numtasks)
{
	MPI_Status Stat;

	int local_a[SIZE];
	int local_b[SIZE];
	int local_c[SIZE];

	memcpy(local_a, matrix_a[rank], sizeof(local_a)); 
	memcpy(local_b, matrix_b[rank], sizeof(local_b)); 
	memset(local_c, 0, sizeof(local_c));

	int mp1 = (rank + 1) % numtasks;
	int mm1 = rank == 0 ? numtasks - 1 : rank - 1;
	int tag = 0;
	int i;
	for (i = 0; i < numtasks; ++i) {
		int l = (i + rank) % numtasks;

		int j;
		for (j = 0; j < SIZE; ++j) {
			local_c[j] += local_a[l] * local_b[j];
		}

		int rc;
		if (i != numtasks - 1) {
			rc = MPI_Send(local_b, SIZE, MPI_INT, mm1, tag, MPI_COMM_WORLD);
			rc = MPI_Recv(local_b, SIZE, MPI_INT, mp1, tag, MPI_COMM_WORLD, &Stat);
		} 
	}

	if (rank != 0) {
		int rc = MPI_Send(local_c, SIZE, MPI_INT, 0, tag, MPI_COMM_WORLD);
	} else {
		memcpy(matrix_c[0], local_c, sizeof(int) * SIZE);
		int i;
		for (i = 1; i < numtasks; ++i) {
			int rc = MPI_Recv(local_c, SIZE, MPI_INT, i, tag, MPI_COMM_WORLD, &Stat);
			memcpy(matrix_c[i], local_c, sizeof(int) * SIZE);
		}
	}	
}

int main(int argc, char *argv[])  {
	int numtasks, rank, dest, source, rc, count, tag=1;  

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	matrix_mul(rank, numtasks);

	MPI_Finalize();

	if (rank == 0) {
		int i, j;
		for (i = 0; i < SIZE; ++i) {
			for (j = 0; j < SIZE; ++j) {
				printf("%d ", matrix_c[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
