#include "mpi.h"
#include <stdio.h>
#include <string.h>

#define SIZE 10
int vec[SIZE];

int main(int argc, char *argv[])  {
	int numtasks, rank, dest, source, rc, count, tag=1;  
	int inmsg, outmsg;
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	memset(vec, 0, sizeof(vec));

	//int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
	if (rank == 0) {
		int i = 0;
		for (; i < numtasks; ++i) {
			vec[i] = i;
		}
	}
	
	source = 0;
	rc = MPI_Scatter(vec, 1, MPI_INT, &tag, 1, MPI_INT, source, MPI_COMM_WORLD);

	int i = 0;
	for (; i < numtasks; ++i) {
		if (rank == i) {
			printf("rank %d\n", i);
			printf("tag %d\n", tag);
		}
	}

	MPI_Finalize();
	return 0;
}

