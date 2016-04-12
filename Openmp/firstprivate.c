#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main (int argc, char *argv[]) {
  int i;
  int jstart = 1;
  int j = jstart;
  float a[N];

  for (i = 0; i < N; ++i) {
    a[i] = 0;
  }

  for (i = 0; i < N; ++i) {
    printf("a[%d]= %f\n", i, a[i]);
  }

#pragma omp parallel firstprivate(j)
  {
    int tid = omp_get_thread_num();
#pragma omp for
    for (i = 0; i < N; ++i) {
      if (i == 0 || i == N - 1)
        j = j + 1;
      a[i] = a[i] + j;
      printf("Thread %d: i %d, j %d\n", tid, i, j);
    }
  }

  for (i = 0; i < N; ++i) {
    printf("a[%d]= %f\n", i, a[i]);
  }

  return 0;
}
