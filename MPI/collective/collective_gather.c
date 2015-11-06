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

	//int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
	//recvcount is for any single sender
	dest = 0;
	rc = MPI_Gather(&rank, 1, MPI_INT, vec, 1, MPI_INT, dest, MPI_COMM_WORLD);

	if (rank == dest) {
		int j;
		for (j = 0; j < numtasks; ++j) {
			printf("%d ", vec[j]);
		}
		printf("\n");
	}

	MPI_Finalize();
	return 0;
}

