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

###APIs
**omp_get_thread_num()**
Get the thread rank in a parallel region (0- omp_get_num_threads() -1)

**omp_set_num_threads(nthreads)**
Set the number of threads used in a parallel region

**omp_get_num_threads()**
Get the number of threads used in a parallel region
