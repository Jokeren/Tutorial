#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main (int argc, char *argv[]) {
  int j = 0;
  int i;

  for (j = 0; j < 5; ++j) {
    #pragma omp parallel for ordered
    for (i = 0; i < N; ++i) {
      #pragma omp ordered
      printf("i %d\n", i);
    }
    printf("\n");
  }

  return 0;
}
