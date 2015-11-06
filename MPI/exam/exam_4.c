#include "mpi.h"
#include <stdio.h>

#define SIZE 410

int main(int argc, char *argv[])  
{
	int numtasks, rank, rc, tag=1;  
	MPI_Status status;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int vec[SIZE];
	MPI_Datatype vec1, vec2;
	int k = sizeof(int);

	//int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
	rc = MPI_Type_vector(3, 5, 7, MPI_INT, &vec1);
	rc = MPI_Type_hvector(4, 1, k * 100, vec1, &vec2);
	//int MPI_Type_commit(MPI_Datatype *datatype)
	rc = MPI_Type_commit(&vec2);
	
	if (rank == 0) {
		int dest = 1;

		int i = 0;
		for (; i < SIZE; ++i) {
			vec[i] = i;
		}

		rc = MPI_Send(vec, 1, vec2, dest, tag, MPI_COMM_WORLD);
	} else if (rank == 1) {
		int source = 0;

		int i = 0;
		for (; i < SIZE; ++i) {
			vec[i] = -i;
		}

		rc = MPI_Recv(vec, 1, vec2, source, tag, MPI_COMM_WORLD, &status);
	}

	if (rank == 1) {
		int i = 0;
		for (; i < SIZE; ++i) {
			printf("loc %d : %d\n", i, vec[i]);
		}
	}
	
	//int MPI_Type_free(MPI_Datatype *datatype)
	MPI_Type_free(&vec2);
	MPI_Finalize();
	return 0;
}

