#include "mpi.h"
#include <stdio.h>

#define SIZE 25

int main(int argc, char *argv[])  
{
	int numtasks, rank, rc, tag=1;  
	MPI_Status status;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int vec[SIZE];
	MPI_Datatype MPI_ONE_FIFTH;
	int stride = 5;
	int blen = 1;
	int dcount = SIZE / stride;
	//int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
	rc = MPI_Type_vector(dcount, blen, stride, MPI_INT, &MPI_ONE_FIFTH);
	//int MPI_Type_commit(MPI_Datatype *datatype)
	rc = MPI_Type_commit(&MPI_ONE_FIFTH);
	
	if (rank == 0) {
		int dest = 1;

		int i = 0;
		for (; i < SIZE; ++i) {
			vec[i] = i;
		}

		rc = MPI_Send(vec, 1, MPI_ONE_FIFTH, dest, tag, MPI_COMM_WORLD);
	} else if (rank == 1) {
		int source = 0;

		int i = 0;
		for (; i < SIZE; ++i) {
			vec[i] = -i;
		}

		rc = MPI_Recv(vec, 1, MPI_ONE_FIFTH, source, tag, MPI_COMM_WORLD, &status);
	}

	if (rank == 1) {
		int num_element;
		int num_raw_element; 
		MPI_Get_count(&status, MPI_ONE_FIFTH, &num_element);
		//int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
		MPI_Get_elements(&status, MPI_INT, &num_raw_element);
		printf("get %d MPI_ONE_FIFTH\n", num_element);
		printf("get %d MPI_INT\n", num_raw_element);

		int i = 0;
		for (; i < SIZE; ++i) {
			printf("loc %d : %d\n", i, vec[i]);
		}

		MPI_Aint extent;
		//int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
		MPI_Type_extent(MPI_ONE_FIFTH, &extent);
		printf("extent %zu\n", extent);
	}
	
	//int MPI_Type_free(MPI_Datatype *datatype)
	MPI_Type_free(&MPI_ONE_FIFTH);
	MPI_Finalize();
	return 0;
}

