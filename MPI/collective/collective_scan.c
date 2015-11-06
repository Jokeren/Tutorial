
#include "mpi.h"
#include <stdio.h>

#define SIZE 10
int vec[SIZE];
int recv[SIZE];

int main(int argc, char *argv[])  {
	int numtasks, rank, dest, source, rc, count, tag=1;  
	int inmsg, outmsg;
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int i;
	for (i = 0; i < SIZE; ++i) {
		vec[i] = rank;
	}

	source = 0;
	//int MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
	rc = MPI_Scan(vec, recv, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

	for (i = 0; i < numtasks; ++i) {
		if (rank == i) {
			printf("proc %d\n", rank);
			int j;
			for (j = 0; j < SIZE; ++j) {
				printf("%d ", recv[j]);
			}
			printf("\n");
		}
	}

	MPI_Finalize();
	return 0;
}

