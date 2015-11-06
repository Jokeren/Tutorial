#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])  {
	int numtasks, rank, dest, source, rc, count, tag=1;  
	int inmsg, outmsg;
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int from = (rank + numtasks - 1) % numtasks;
	int to = (rank + numtasks + 1) % numtasks;

	outmsg = rank;
	//int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
	//                 int dest, int sendtag,
	//                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
	//                 int source, int recvtag, MPI_Comm comm, MPI_Status *status)
	// non-circular
	//source = MPI_PROC_NULL, tag = MPI_ANY_TAG and count = 0.
	if (rank == 0) {
		rc = MPI_Sendrecv(&outmsg, 1, MPI_INT, to, tag,
					&inmsg, 1, MPI_INT, MPI_PROC_NULL, tag,
					MPI_COMM_WORLD, &Stat);
	} else if (rank == numtasks - 1) {
		rc = MPI_Sendrecv(&outmsg, 1, MPI_INT, MPI_PROC_NULL, tag,
					&inmsg, 1, MPI_INT, from, tag,
					MPI_COMM_WORLD, &Stat);
	} else {
		rc = MPI_Sendrecv(&outmsg, 1, MPI_INT, to, tag,
					&inmsg, 1, MPI_INT, from, tag,
					MPI_COMM_WORLD, &Stat);
	}

	rc = MPI_Get_count(&Stat, MPI_INT, &count);
	if (rank != 0)
		printf("Task %d: Received %d int from task %d with tag %d, value %d\n",
				rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG, inmsg);

	MPI_Finalize();
	return 0;
}

