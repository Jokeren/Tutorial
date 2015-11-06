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
	int ss[2];
	ss[0] = rank;
	ss[1] = 2 * rank;

	//int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
	rc = MPI_Allgather(ss, 1, MPI_INT, vec, 1, MPI_INT, MPI_COMM_WORLD);

	int i = 0;
	for (; i < numtasks; ++i) {
		if (rank == i) {
			int j;
			for (j = 0; j < numtasks; ++j) {
				printf("%d ", vec[j]);
			}
			printf("\n");
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}

