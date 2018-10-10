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
 

int main ()
{
  double t1, t2; 
  
  /* variables for task 2 */
  int N = 1000;
  int **a, **b, **c;

    
  printf("allocate array\n");  
  /* allocate memory for 2d array*/
  a = malloc(N * sizeof(int *));
  b = malloc(N * sizeof(int *));
  c = malloc(N * sizeof(int *));

  for (int i = 0; i<N; ++i) {
    a[i] = malloc(N * sizeof(int));
    b[i] = malloc(N * sizeof(int));
    c[i] = malloc(N * sizeof(int));
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
  int tmp[N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      tmp[i][j] = b[j][i];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        c[i][j] += a[i][k] * tmp[j][k];
      }
    }
  }
  /***************************************/
  t2 = getTime(); 
  

  /* output; examples, adjust for task */
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%d ", c[i][j]);
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
