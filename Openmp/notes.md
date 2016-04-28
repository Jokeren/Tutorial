###Concepts
**Two main approaches:**

loop-level

parallel regions

**Loop-Level Parallelism:**
Sometimes call *fine-grained parallelism*

**Parallel Regions Parallelism:**
Sometimes called *coarse-grained parallelism*

###Requirements
1. No dependencies between loop indicies
2. An element of an array is assigned to by at most one iteration
3. No loop iteration reads array elements modified by any other dependency
4. Due to overhead of parallelization - *use only on loops where individual iterations take a long time*

###Keywords
**shared**
By default

**private**
Thread local

**firstprivate**

**schedule**

*STATIC*
Loop iterations are divided into pieces of size chunk and then statically assigned to threads. If chunk is not specified, the iterations are evenly (if possible) divided contiguously among the threads.

*DYNAMIC*
Loop iterations are divided into pieces of size chunk, and dynamically scheduled among the threads; when a thread finishes one chunk, it is dynamically assigned another. The default chunk size is 1.

*GUIDED*
Iterations are dynamically assigned to threads in blocks as threads request them until no blocks remain to be assigned. Similar to DYNAMIC except that the block size decreases each time a parcel of work is given to a thread. The size of the initial block is proportional to:
$$number_of_iterations / number_of_threads$$
Subsequent blocks are proportional to
$$number_of_iterations_remaining / number_of_threads$$
The chunk parameter defines the minimum block size. The default chunk size is 1.

*RUNTIME*
The scheduling decision is deferred until runtime by the environment variable OMP_SCHEDULE. It is illegal to specify a chunk size for this clause.

*AUTO*
The scheduling decision is delegated to the compiler and/or runtime system.

###APIs
**omp_get_thread_num()**
Get the thread rank in a parallel region (0- omp_get_num_threads() -1)

**omp_set_num_threads(nthreads)**
Set the number of threads used in a parallel region

**omp_get_num_threads()**
Get the number of threads used in a parallel region

