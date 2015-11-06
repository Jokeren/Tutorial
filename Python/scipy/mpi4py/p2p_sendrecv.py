from mpi4py import MPI
import numpy

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
print "data rank ", rank

sendbuf = numpy.arange(10, dtype='i')
recvbuf = numpy.arange(10, dtype='i')
if rank == 0:
    comm.Sendrecv(sendbuf, 1, 0, recvbuf, 1, 0)
elif rank == 1:
    comm.Sendrecv(sendbuf, 0, 0, recvbuf, 0, 0)

print "data received ", rank
