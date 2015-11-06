#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])  {
	int numtasks, rank;
	char host_name[MPI_MAX_PROCESSOR_NAME];

	int rc = MPI_Init(&argc,&argv);
	if (rc != MPI_SUCCESS) {
		printf("Error starting MPI program. Terminating.\n");
		MPI_Abort(MPI_COMM_WORLD, rc);
	}

//	MPI_Comm com;
//	MPI_Comm_dup(MPI_COMM_WORLD, &com);

	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int res_len;
	MPI_Get_processor_name(host_name, &res_len);

	printf("Num Tasks:%d, Rank:%d, Host Name:%s\n", 
		numtasks, rank, host_name);

	MPI_Finalize();
	return 0;
}

