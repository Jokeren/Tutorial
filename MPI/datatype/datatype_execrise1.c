/*
 * This program transfer the following data
 * every process owns a line
 * *-*-
 * *-*-
 * *-*-
 * '*' data should be transferred to process 0
 * '*' and '-' are both matrices
 * in the example, it stands for 4 * 4 matrices
 */
#include "mpi.h"
#include <stdio.h>
#include <string.h>

#define SIZE 32

int main(int argc, char *argv[])  
{
	int numtasks, rank, rc, tag=1;  
	MPI_Status status;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Datatype MPI_FOUR_FOUR, MPI_M_STRUCT;

	int vec[SIZE][SIZE];
	memset(vec, 0, sizeof(vec));
	//define vector 1
	//
	int stride = SIZE;	
	int blen = 4;
	int dcount = 4;

	//int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype)
	rc = MPI_Type_vector(dcount, blen, stride, MPI_INT, &MPI_FOUR_FOUR);
	//int MPI_Type_commit(MPI_Datatype *datatype)
	rc = MPI_Type_commit(&MPI_FOUR_FOUR);

	MPI_Aint offset[2];
	MPI_Datatype types[2];
	int block_count[2];

	block_count[0] = 1;
	block_count[1] = 1;
	types[0] = MPI_FOUR_FOUR;
	types[1] = MPI_UB;
	offset[0] = 0;
	offset[1] = (4 + 4) * sizeof(int);

	//int MPI_Type_struct(int count, const int *array_of_blocklengths, const MPI_Aint *array_of_displacements, const MPI_Datatype *array_of_types, MPI_Datatype *newtype)
	MPI_Type_struct(2, block_count, offset, types, &MPI_M_STRUCT);
	rc = MPI_Type_commit(&MPI_M_STRUCT);

	if (rank != 0) {
		int i, j;
		for (i = 0; i < SIZE; ++i) {
			for (j = 0; j < SIZE; ++j) {
				vec[i][j] = i * SIZE + j + rank;
			}
		}
		rc = MPI_Send(&vec[4 * rank], 2, MPI_M_STRUCT, 0, tag, MPI_COMM_WORLD);
	} else {
		int i = 1;
	
		for (; i < numtasks; ++i) {
			printf("get from proc %d\n", i);
			MPI_Recv(&vec[4 * i], 2, MPI_M_STRUCT, i, tag, MPI_COMM_WORLD, &status);

			int num_element;
			int num_raw_element; 

			MPI_Get_count(&status, MPI_M_STRUCT, &num_element);
			//int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count)
			MPI_Get_elements(&status, MPI_INT, &num_raw_element);
			printf("get %d MPI_M_STRUCT\n", num_element);
			printf("get %d MPI_INT\n", num_raw_element);

			MPI_Aint extent;
			//int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
			MPI_Type_extent(MPI_M_STRUCT, &extent);
			printf("extent %zu\n", extent);
		}

		int j;
		printf("result\n");
		for (i = 0; i < SIZE; ++i) {
			for (j = 0; j < SIZE; ++j) {
				printf("%d ", vec[i][j]);
			}
			printf("\n");
		}
	}


	
	//int MPI_Type_free(MPI_Datatype *datatype)
	MPI_Type_free(&MPI_M_STRUCT);
	MPI_Type_free(&MPI_FOUR_FOUR);
	MPI_Finalize();
	return 0;
}

