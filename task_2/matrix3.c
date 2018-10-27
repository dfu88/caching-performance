/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}


int min(int a, int b)
{
  return a < b ? a : b;
}
 

int main ()
{
  double t1, t2; 
  
  /* variables for task 2 */
  int N = 1000;
  int count = 0;
  int SM = 64 / sizeof(int); // cache line size(64 Bytes) divided by size of int(4 Bytes)
  double **a, **b, **c;

    
  printf("allocate array\n");  
  /* allocate memory for 2d array*/
  a = malloc(N * sizeof(double *));
  b = malloc(N * sizeof(double *));
  c = malloc(N * sizeof(double *));

  for (int i = 0; i<N; ++i) {
    a[i] = malloc(N * sizeof(double));
    b[i] = malloc(N * sizeof(double));
    c[i] = malloc(N * sizeof(double));
  }
  

  printf("initialise array\n");
  /* initialise 2d arrray elements */
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      a[i][j] = 1;
      b[i][j] = 1;
      printf("i:%d j:%d\n", i,j);
    }
  }


  printf("matrix multiplication\n");
  t1 = getTime();
  /* code to be measured goes here */
  /***************************************/
  for (int k = 0; k < N; k+=SM) {
    for (int j = 0; j < N; j+=SM) {
      for (int i = 0; i < N; i+=SM) {
        for (int i2 = i; i2 < min(i+SM,N); ++i2) {
          for (int j2 = j; j2 < min(j+SM,N); ++j2) {
            for (int k2 = k; k2 < min(k+SM,N); ++k2) {
              c[i2][j2] += a[i2][k2] * b[k2][j2];
            }
          }
        }
      }
    }
  }
  /***************************************/
  t2 = getTime(); 
  
  /* output; examples, adjust for task */
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%f ", c[i][j]);
    }
  }
  printf("time: %6.2f secs\n",(t2 - t1));

  /* IMPORTANT: also print the result of the code, e.g. the sum, 
   * otherwise compiler might optimise away the code */
  
  /* free memory; examples, adjust for task */
  for (int i = 0; i < N; ++i)
  {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);
   

  return 0;  
}
