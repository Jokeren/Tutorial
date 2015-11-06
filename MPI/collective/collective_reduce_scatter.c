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

	int recv_count[SIZE];
	int i;
	for (i = 0; i < SIZE; ++i) {
		vec[i] = rank;
		recv_count[i] = 3;
	}	

	int ans[SIZE];
	memset(ans, 0, sizeof(ans));
	source = 0;
	//int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
	//the sum of recvcounts can not be greater than the length of sendbuf for each process
	rc = MPI_Reduce_scatter(vec, ans, recv_count, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

	for (i = 0; i < numtasks; ++i) {
		if (i == rank) {
			printf("proc %d\n", rank);
			int j;
			for (j = 0; j < SIZE; ++j) {
				printf("%d ", ans[j]);
			}
			printf("\n");
		}
	}

	MPI_Finalize();
	return 0;
}

