/*
 * cal matrix_ij = i + j by different processors
 */
#include "mpi.h"
#include <stdio.h>
#define M 10
#define N 10

void mesh(MPI_Comm comm, MPI_Comm *row_comm, MPI_Comm *col_comm, 
		int p, int q, int iam, int np, int *riam, int *ciam)
{
	//processers not enough
	if (np < p * q)
		return ;

	int color;
	if (iam < p * q) {
		color = iam / q;
		//int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
		//1. Use MPI_Allgather to get the color and key from each process
		//2. Count the number of processes with the same color; create a 
		//communicator with that many processes.  If this process has
		//MPI_UNDEFINED as the color, create a process with a single member.
		//3. Use key to order the ranks
		//4. Set the VCRs using the ordered key values
		MPI_Comm_split(comm, color, iam, row_comm);

		color = iam % q; 
		MPI_Comm_split(comm, color, iam, col_comm);

		//comm in the same row, different col
		MPI_Comm_rank(*row_comm, ciam);

		//comm in the same col, different row
		MPI_Comm_rank(*col_comm, riam);
	} else {
		color = MPI_UNDEFINED;
		MPI_Comm_split(comm, color, iam, row_comm);
		MPI_Comm_split(comm, color, iam, col_comm);
	}
}

void cal_matrix(int m, int n, int p, int q, int riam, int ciam, int lda, 
		float matrix[][lda], 
		int *rnum, int *cnum)
{
	int i, j, k, l;

	k = m / p;
	l = m % p;

	for (i = 0; i < l; ++i) 
		rnum[i] = k + 1;
	for (i = l; i < p; ++i)
		rnum[i] = k;

	k = n / q;
	l = n % q;

	for (i = 0; i < l; ++i)
		cnum[i] = k + 1;
	for (i = l; i < q; ++i)
		cnum[i] = k;

	k = 0;
	for (i = 0; i < riam; ++i)
		k += rnum[i];

	l = 0;
	for (i = 0; i < ciam; ++i)
		l += cnum[i];

	for (i = 0; i < rnum[riam]; ++i) {
		for (j = 0; j < cnum[ciam]; ++j) {
			matrix[i][j] = k + l + i + j;
		}
	}

	return;
}

float matrix[M][N];

int main(int argc, char *argv[])  {
	int numtasks, rank;
	char host_name[MPI_MAX_PROCESSOR_NAME];

	int rc = MPI_Init(&argc,&argv);
	if (rc != MPI_SUCCESS) {
		printf("Error starting MPI program. Terminating.\n");
		MPI_Abort(MPI_COMM_WORLD, rc);
	}

	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int res_len;
	MPI_Get_processor_name(host_name, &res_len);

	printf("Num Tasks:%d, Rank:%d, Host Name:%s\n", 
		numtasks, rank, host_name);
	
	int p = 3, q = 3;
	int riam, ciam;
	MPI_Comm ROW_COMM, COL_COMM;
	mesh(MPI_COMM_WORLD, &ROW_COMM, &COL_COMM, p, q, rank, numtasks, &riam, &ciam);
	
	int rnum[M], cnum[N];
	if (ROW_COMM != MPI_UNDEFINED && COL_COMM != MPI_UNDEFINED) 
		cal_matrix(M, N, p, q, riam, ciam, N, matrix, rnum, cnum);

	int ii;
	for (ii = 0; ii < numtasks; ++ii)  {
		if (rank == ii) {
			int i, j;
			printf("rank %d\n", ii);
			for (i = 0; i < M; ++i) {
				for (j = 0; j < N; ++j) {
					printf("%f ", matrix[i][j]);
				}
				printf("\n");
			}
		}
		//int MPI_Barrier( MPI_Comm comm )
		MPI_Barrier(MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}

