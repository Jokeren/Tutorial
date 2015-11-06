
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

	int i;
	for (i = 0; i < SIZE; ++i) {
		vec[i] = rank;
	}	

	int ans[SIZE];
	source = 0;
	//int MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
	rc = MPI_Reduce(vec, ans, SIZE, MPI_INT, MPI_SUM, source, MPI_COMM_WORLD);

	if (rank == 0) {
		for (i = 0; i < SIZE; ++i) {
			printf("pos %d ans %d\n", i, ans[i]);
		}
	}

	MPI_Finalize();
	return 0;
}

