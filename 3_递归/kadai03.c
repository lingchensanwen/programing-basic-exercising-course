#include <stdio.h>
#include <math.h>

double f(double);
double dffx(double);
double newton(double);

int main(){
  double x0 = 1.0;
  double solution = newton(x0);
  printf("solution is %f\n", solution);
  printf("0check : %f\n",exp(newton(x0))+newton(x0));
  return 0;
}

double f(double x){
  return exp(x) + x;
}

double dffx(double x){
  return exp(x) + 1;
}

double newton(double x){ 
  if(fabs(f(x)/dffx(x)) < 0.00000001)
    return x;
  else
    return newton(x- f(x)/dffx(x));
}
