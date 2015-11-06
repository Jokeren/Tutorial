#include "mpi.h"
#include <stdio.h>

#define SIZE 10
int vec[SIZE];

int main(int argc, char *argv[])  {
	int numtasks, rank, dest, source, rc, count, tag=1;  
	int inmsg, outmsg;
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		int i;
		for (i = 0; i < SIZE; ++i) {
			vec[i] = i;
		}
	} 

	source = 0;
	//MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
	rc = MPI_Bcast(vec, 10, MPI_INT, source, MPI_COMM_WORLD);

	int i;
	for (i = 1; i < numtasks; ++i) {
		if (rank == i) {
			printf("Task %d: Received %d int from task %d with tag %d\n",
					rank, 10, source, tag);
			int j;
			for (j = 0; j < SIZE; ++j) {
				printf("%d ", vec[j]);
			}
			printf("\n");
		}
	}

	MPI_Finalize();
	return 0;
}

