#include "mpi.h"
#include <stdio.h>
#include <string.h>

#define SIZE 10

int main(int argc, char *argv[])  
{
	int numtasks, rank, rc, tag=1;  
	MPI_Status status;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int vec[SIZE];
	memset(vec, 0, sizeof(vec));

	MPI_Datatype MPI_TWO, MPI_UB_TWO;
	//MPI_Type_contiguous (count,oldtype,&newtype) 
	MPI_Type_contiguous(SIZE, MPI_INT, &MPI_TWO);
	//int MPI_Type_commit(MPI_Datatype *datatype)
	rc = MPI_Type_commit(&MPI_TWO);

	int block_count[2];
	MPI_Aint offset[2];
	MPI_Datatype types[2];
	block_count[0] = 1;
	block_count[1] = 1;
	types[0] = MPI_TWO;
	types[1] = MPI_UB;

	//int MPI_Get_address(const void *location, MPI_Aint *address)
	offset[0] = 0;
	offset[1] = 4;
	MPI_Type_struct(2, block_count, offset, types, &MPI_UB_TWO);
	rc = MPI_Type_commit(&MPI_UB_TWO);
	
	if (rank == 0) {
		int dest = 1;
		int i = 0;
		for (; i < SIZE; ++i)
			vec[i] = i;

		rc = MPI_Send(vec, 1, MPI_UB_TWO, dest, tag, MPI_COMM_WORLD);
	} else if (rank == 1) {
		int source = 0;

		rc = MPI_Recv(vec, 1, MPI_UB_TWO, source, tag, MPI_COMM_WORLD, &status);
	}

	if (rank == 1) {
		int num_element;
		int num_raw_element; 
		MPI_Get_count(&status, MPI_UB_TWO, &num_element);
		//int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
		//MPI_Get_elements(&status, MPI_UB_TWO, &num_raw_element);

		printf("get %d MPI_UB_TWO\n", num_element);
		//printf("get %d MPI_INT\n", num_raw_element);

		int i = 0;
		for (; i < SIZE; ++i) {
			printf("loc %d : %d\n", i, vec[i]);
		}

		MPI_Aint extent;
		//int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
		//the data not change, but extent change
		MPI_Type_extent(MPI_UB_TWO, &extent);
		printf("extent %zu\n", extent);
	}
	
	//int MPI_Type_free(MPI_Datatype *datatype)
	MPI_Type_free(&MPI_UB_TWO);
	MPI_Type_free(&MPI_TWO);
	
	MPI_Finalize();
	return 0;
}

