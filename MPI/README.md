# MPI-Tutorial
MPICH program samples with function declartions inside the files.

##Directories

###p2p

MPI point-to-point communication usage.

p2p_send_recv_probe.c : `MPI_Send`, `MPI_Probe`, `MPI_Recv`, `MPI_Get_count`

p2p_isend_irecv.c : `MPI_Isend`, `MPI_Irecv`, `MPI_Waitall`

p2p_sendrecv.c : `MPI_Sendrecv`

###matrix

MPI matrix multiplication samples. Without lose of generality, We use A, B to indicate matrix A*B.

mul_col_col.c : both matrix stored in the column-leading way.

mul_col_row.c : A stored in the column-leading way, B stored in the row-leading way.

mul_row_col.c : A stored in the row-leading way, B stored in the column-leading way.

mul_row_row.c : both matrix stored in the row-leading way.

partition.c : `MPI_Comm_split`, `MPI_Barrier`

###datatype

MPI derived datatypes.

datatype_contiguous.c: `MPI_Type_contiguous`, `MPI_Type_commit`, `MPI_Get_elements`, `MPI_Type_extent`, `MPI_Type_free`

datatype_vector.c: `MPI_Type_vector`

datatype_indexed.c: `MPI_Type_indexed`

datatype_struct.c: `MPI_Get_address`, `MPI_Type_struct`

datatype_ub.c : `MPI_UB`

datatype_execrise[1-3] : Combine above routines and keywords.

###collective

MPI collective communication.

collective_allgather.c: `MPI_Allgather`

collective_alltoall.c: `MPI_Alltoall`

collective_bcast.c: `MPI_Bcast`

collective_gather.c: `MPI_Gather`

collective_reduce.c: `MPI_Reduce`

collective_reduce_scatter: `MPI_Reduce_scatter`

collective_scan.c: `MPI_Scan`

collective_scatter.c: `MPI_Scatter`

p2p_alltoall: use `MPI_Send` and `MPI_Recv` to implement `MPI_Alltoall`


