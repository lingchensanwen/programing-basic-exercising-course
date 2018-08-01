#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void eig(double[2][2], double*, double*, double*, double*);
int main(){
  double val1;
  double val2;
  double vec1[2];
  double vec2[2];

  double mat[2][2] = {{1, 5},{6, 2}};
  eig(mat, &val1, &val2, vec1, vec2);
  printf("[%f,%f]\n", mat[0][0], mat[0][1]);
  printf("[%f,%f]\n", mat[1][0], mat[1][1]);
  printf("eigenvalue = %f, eigenvector = (%f, %f)\n", val1, vec1[0], vec1[1]);
  printf("eigenvalue = %f, eigenvector = (%f, %f)\n", val2, vec2[0], vec2[1]);
  return 0;
}

void eig(double mat[2][2], double *val1, double *val2, double *vec1, double *vec2) {
  //ここを埋める
  double as_sqrt = sqrt(mat[0][0]*mat[0][0]-2*mat[0][0]*mat[1][1]+4*mat[0][1]*mat[1][0]+mat[1][1]*mat[1][1]);
  *val1 = (-as_sqrt + mat[0][0] + mat[1][1])/2.0;
  *val2 = (as_sqrt + mat[0][0] + mat[1][1])/2.0;
  *vec1 = (as_sqrt - mat[0][0] + mat[1][1])/(-2.0*mat[1][0]);
  *(vec1+1) = 1;
  *vec2 = (-as_sqrt - mat[0][0] + mat[1][1])/(-2.0*mat[1][0]);
  *(vec2+1) = 1;
}


