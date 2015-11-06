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
		vec[i] = rank * 3 + i;
	}

	for (i = 0; i < numtasks; ++i) {
		if (rank == i) {
			printf("Task %d\n", rank);
			int j;
			for (j = 0; j < SIZE; ++j) {
				printf("%d ", vec[j]);
			}
			printf("\n");
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}
	MPI_Barrier(MPI_COMM_WORLD);

	//int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
	//sendcount and recvcount indicates amount of data to transfer
	rc = MPI_Alltoall(vec, 1, MPI_INT, recv, 1, MPI_INT, MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);
	for (i = 0; i < numtasks; ++i) {
		if (rank == i) {
			printf("Task %d\n", rank);
			int j;
			for (j = 0; j < SIZE; ++j) {
				printf("%d ", recv[j]);
			}
			printf("\n");
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}

