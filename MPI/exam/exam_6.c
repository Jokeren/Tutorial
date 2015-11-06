#include "mpi.h"
#include <stdio.h>
#include <string.h>

#define SIZE 20
int vec[SIZE];
int recv[SIZE];

int main(int argc, char *argv[])  {
	int numtasks, rank, dest, source, rc, count, tag=1;  
	int inmsg, outmsg;
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	source = (rank + numtasks + 1) % numtasks;
	dest = (rank + numtasks - 1) % numtasks;

	int i;
	int sendcount = 2;
	int recvcount = 2;

	for (i = rank * recvcount; i < (rank + 1) * recvcount; ++i) {
		vec[i] = rank;
	}

	int send_idx = rank;
	for (i = 0; i < numtasks - 1; ++i) {
		if (rank % 2) {
			rc = MPI_Send(&vec[send_idx * sendcount], sendcount, MPI_INT, dest, tag, MPI_COMM_WORLD);
			rc = MPI_Recv(recv, recvcount, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
		} else {
			rc = MPI_Recv(recv, recvcount, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
			rc = MPI_Send(&vec[send_idx * sendcount], sendcount, MPI_INT, dest, tag, MPI_COMM_WORLD);
		}

		send_idx = (send_idx + 1) % numtasks;
		memcpy(vec + send_idx * recvcount, recv, recvcount * sizeof(int));
	}

	for (i = 0; i < numtasks; ++i) {
		if (rank == i) {
			int j;
			for (j = 0; j < SIZE; ++j) {
				printf("%d ", vec[j]);
			}
			printf("\n");
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}

