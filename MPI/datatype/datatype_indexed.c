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

	MPI_Datatype MPI_INDEX;

	int vec[SIZE];
	int block_count[2];
	int offset[2];
	block_count[0] = 2;
	block_count[1] = 4;
	offset[0] = 5;
	//according to base
	offset[1] = 11;
	//MPI_Type_indexed (count,blocklens[],offsets[],old_type,&newtype)
	rc = MPI_Type_indexed(2, block_count, offset, MPI_INT, &MPI_INDEX);
	//int MPI_Type_commit(MPI_Datatype *datatype)
	rc = MPI_Type_commit(&MPI_INDEX);
	
	if (rank == 0) {
		int dest = 1;

		int i = 0;
		for (; i < SIZE; ++i) {
			vec[i] = i;
		}

		rc = MPI_Send(vec, 1, MPI_INDEX, dest, tag, MPI_COMM_WORLD);
	} else if (rank == 1) {
		int source = 0;

		int i = 0;
		for (; i < SIZE; ++i) {
			vec[i] = -i;
		}

		rc = MPI_Recv(vec, 1, MPI_INDEX, source, tag, MPI_COMM_WORLD, &status);
	}

	if (rank == 1) {
		int num_element;
		int num_raw_element; 
		MPI_Get_count(&status, MPI_INDEX, &num_element);
		//int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
		MPI_Get_elements(&status, MPI_INT, &num_raw_element);
		printf("get %d MPI_INDEX\n", num_element);
		printf("get %d MPI_INT\n", num_raw_element);

		int i = 0;
		for (; i < SIZE; ++i) {
			printf("loc %d : %d\n", i, vec[i]);
		}

		MPI_Aint extent;
		//int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
		MPI_Type_extent(MPI_INDEX, &extent);
		printf("extent %zu\n", extent);
	}
	
	//int MPI_Type_free(MPI_Datatype *datatype)
	MPI_Type_free(&MPI_INDEX);
	MPI_Finalize();
	return 0;
}

