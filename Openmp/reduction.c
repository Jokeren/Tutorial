#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

/* C++  Reduction Operands
Operator  Initial value
+ 0
* 1
* - 0
*   & ~0
*   | 0
*   ^ 0
*   &&  1
*   ||  0
*/


int main (int argc, char *argv[]) {
  int sum = 0;
  int i;

  #pragma omp parallel for reduction(+:sum)
  for(i = 1; i <= N; i++){
    sum = sum + i;
  }

  printf("sum %d\n", sum);

  return 0;
}
