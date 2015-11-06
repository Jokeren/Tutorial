#include "mpi.h"
#include <stdio.h>

#define SIZE 25

struct m_type_t {
	float x, y, z;
	char c;
};

int main(int argc, char *argv[])  
{
	int numtasks, rank, rc, tag=1;  
	MPI_Status status;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Datatype MPI_M_STRUCT;

	struct m_type_t m_type;

	int mcount = 1;
	int block_count[2];
	MPI_Aint offset[2];
	MPI_Datatype types[2];
	block_count[0] = 3;
	block_count[1] = 1;
	types[0] = MPI_FLOAT;
	types[1] = MPI_CHAR;
	
	MPI_Aint base, off;
	//int MPI_Get_address(const void *location, MPI_Aint *address)
	MPI_Get_address(&m_type, &base);

	MPI_Get_address(&m_type.x, &off);
	offset[0] = off - base;

	MPI_Get_address(&m_type.c, &off);
	offset[1] = off - base;

	//int MPI_Type_struct(int count, const int *array_of_blocklengths, const MPI_Aint *array_of_displacements, const MPI_Datatype *array_of_types, MPI_Datatype *newtype)
	MPI_Type_struct(2, block_count, offset, types, &MPI_M_STRUCT);
	rc = MPI_Type_commit(&MPI_M_STRUCT);
	
	if (rank == 0) {
		int dest = 1;

		m_type.x = 1;
		m_type.y = 2;
		m_type.z = 3;
		m_type.c = 'c';

		rc = MPI_Send(&m_type, 1, MPI_M_STRUCT, dest, tag, MPI_COMM_WORLD);
	} else if (rank == 1) {
		int source = 0;

		rc = MPI_Recv(&m_type, 1, MPI_M_STRUCT, source, tag, MPI_COMM_WORLD, &status);
	}

	if (rank == 1) {
		int num_element;
		//int num_raw_element; 
		MPI_Get_count(&status, MPI_M_STRUCT, &num_element);
		//MPI_Get_elements(&status, MPI_INT, &num_raw_element);
		printf("get %d MPI_M_STRUCT\n", num_element);
		//printf("get %d MPI_INT\n", num_raw_element);

		printf("m_type.x %f\n", m_type.x);
		printf("m_type.y %f\n", m_type.y);
		printf("m_type.z %f\n", m_type.z);
		printf("m_type.c %c\n", m_type.c);

		MPI_Aint extent;
		//int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent)
		MPI_Type_extent(MPI_M_STRUCT, &extent);
		printf("extent %zu\n", extent);
	}
	
	//int MPI_Type_free(MPI_Datatype *datatype)
	MPI_Type_free(&MPI_M_STRUCT);
	MPI_Finalize();
	return 0;
}

