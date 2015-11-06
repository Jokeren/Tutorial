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
	for (i = 0; i < numtasks; ++i) {
		vec[i] = 4 * rank + i;
	}
	recv[rank] = vec[rank];

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

	dest = (rank + 1) % numtasks;
	source = (rank - 1 + numtasks) % numtasks;
	int send_idx = (rank + 1) % numtasks;
	int recv_idx = (rank - 1 + numtasks) % numtasks;
	for (i = 0; i < numtasks - 1; ++i) {
		outmsg = vec[send_idx];
		rc = MPI_Send(&outmsg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
		rc = MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
		recv[recv_idx] = inmsg;
		dest = (dest + 1) % numtasks;
		source = (source - 1 + numtasks) % numtasks;
		send_idx = (send_idx + 1) % numtasks;
		recv_idx = (recv_idx - 1 + numtasks) % numtasks;
	}

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

