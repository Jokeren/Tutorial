#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main (int argc, char *argv[]) {
  int sum = 0;
  int i = 0;

  #pragma omp parallel
  {
    #pragma omp sections
    {
      #pragma omp section
      i += 1; 
    }
    #pragma omp barrier
    printf("sum %d\n", i);
  }


  return 0;
}
