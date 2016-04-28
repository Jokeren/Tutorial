#include <stdio.h>
#include <stdlib.h>
#define N 10

int main (int argc, char *argv[]) {
  int sum = 0;
  int i = 0;

  #pragma omp parallel
  {
    #pragma omp atomic
    i += 1; 
    #pragma omp barrier
    #pragma omp master
    printf("sum %d\n", i);
  }


  return 0;
}
