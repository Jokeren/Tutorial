#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main (int argc, char *argv[]) {
  int i;
  float a[N];

  for (i = 0; i < N; ++i) {
    a[i] = 0;
  }

  for (i = 0; i < N; ++i) {
    printf("a[%d]= %f\n", i, a[i]);
  }

#pragma omp parallel 
  {
    int tid = omp_get_thread_num();
#pragma omp for lastprivate(i)
    for (i = 0; i < N; ++i) {
      a[i] = a[i] + i;
      printf("Thread %d: i %d\n", tid, i);
    }
  }

  printf("last i %d\n", i);

  return 0;
}
