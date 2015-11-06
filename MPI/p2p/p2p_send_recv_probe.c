#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])  {
	int numtasks, rank, dest, source, rc, count, tag=1;  
	int inmsg, outmsg;
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		dest = 1;
		source = 1;
		outmsg = 0;	

		rc = MPI_Send(&outmsg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);

		//int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) 
		rc = MPI_Probe(source, tag, MPI_COMM_WORLD, &Stat);
		//int MPI_Get_count(MPI_Status *status, MPI_Datatype datatype, int *count)
		rc = MPI_Get_count(&Stat, MPI_INT, &count);

		rc = MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
		printf("Task %d: Received %d int from task %d with tag %d, value %d\n",
				rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG, inmsg);
	} else if (rank == 1) {
		dest = 0;
		source = 0;
		outmsg = 1;

		//int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) 
		rc = MPI_Probe(source, tag, MPI_COMM_WORLD, &Stat);
		//int MPI_Get_count(MPI_Status *status, MPI_Datatype datatype, int *count)
		rc = MPI_Get_count(&Stat, MPI_INT, &count);

		rc = MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
		rc = MPI_Send(&outmsg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
		printf("Task %d: Received %d int from task %d with tag %d, value %d\n",
				rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG, inmsg);
	}

	MPI_Finalize();
	return 0;
}

