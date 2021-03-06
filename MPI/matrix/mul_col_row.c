#include "mpi.h"
#include <stdio.h>
#include <string.h>
#define SIZE 3

/*
 * a is stored as columns
 */
int matrix_a[SIZE][SIZE] = {
	{1, 3, 8}, {2, 4, 9}, {5, 6, 11}
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
	int local_tmp[SIZE];

	memcpy(local_a, matrix_a[rank], sizeof(local_a)); 
	memcpy(local_b, matrix_b[rank], sizeof(local_b)); 
	memset(local_c, 0, sizeof(local_c));

	int j;
	for (j = 0; j < SIZE; ++j) {
		local_c[j] += local_a[j] * local_b[rank];
	}

	int tag = 0;
	int i;
	for (i = 1; i < numtasks; ++i) {
		int l = (i + rank) % numtasks;
		int p = (numtasks - i + rank) % numtasks;

		int j;
		for (j = 0; j < SIZE; ++j) {
			local_tmp[j] = local_a[j] * local_b[l];
		}

		int rc;
		rc = MPI_Send(local_tmp, SIZE, MPI_INT, l, tag, MPI_COMM_WORLD);
		rc = MPI_Recv(local_tmp, SIZE, MPI_INT, p, tag, MPI_COMM_WORLD, &Stat);

		for (j = 0; j < SIZE; ++j) {
			local_c[j] += local_tmp[j];
		}
	}

	if (rank != 0) {
		int rc = MPI_Send(local_c, SIZE, MPI_INT, 0, tag, MPI_COMM_WORLD);
	} else {
		int j;
		for (j = 0; j < SIZE; ++j) {
			matrix_c[j][0] = local_c[j];
		}
		int i;
		for (i = 1; i < numtasks; ++i) {
			int rc = MPI_Recv(local_c, SIZE, MPI_INT, i, tag, MPI_COMM_WORLD, &Stat);

			for (j = 0; j < SIZE; ++j) {
				matrix_c[j][i] = local_c[j];
			}
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
