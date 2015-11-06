#include "mpi.h"
#include <stdio.h>

main(int argc, char *argv[])  {
	int numtasks, rank, tag1=1, tag2=2;
	int inmsg[2], outmsg;
	int rc;
	MPI_Request reqs[4];
	MPI_Status stats[4];

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int from = (rank + numtasks - 1) % numtasks;
	int to = (rank + numtasks + 1) % numtasks;

	//int MPI_Irecv( void *buf, int count, MPI_Datatype datatype, int source,
	//                      int tag, MPI_Comm comm, MPI_Request *request )
	rc = MPI_Irecv(&inmsg[0], 1, MPI_INT, to, tag1, MPI_COMM_WORLD, &reqs[0]);
	rc = MPI_Irecv(&inmsg[1], 1, MPI_INT, from, tag2, MPI_COMM_WORLD, &reqs[1]);

	//int MPI_Isend( void *buf, int count, MPI_Datatype datatype, int dest, int tag,
	//                           MPI_Comm comm, MPI_Request *request )
	rc = MPI_Isend(&rank, 1, MPI_INT, to, tag2, MPI_COMM_WORLD, &reqs[2]);
	rc = MPI_Isend(&rank, 1, MPI_INT, from, tag1, MPI_COMM_WORLD, &reqs[3]);

	rc = MPI_Waitall(4, reqs, stats);

	int count0, count1;
	rc = MPI_Get_count(&stats[0], MPI_INT, &count0);
	rc = MPI_Get_count(&stats[1], MPI_INT, &count1);
	printf("Task %d: Received %d int from task %d with tag %d, value %d\n",
				rank, count0, stats[0].MPI_SOURCE, stats[0].MPI_TAG, inmsg[0]);
	printf("Task %d: Received %d int from task %d with tag %d, value %d\n",
				rank, count1, stats[1].MPI_SOURCE, stats[1].MPI_TAG, inmsg[1]);

	MPI_Finalize();
}
