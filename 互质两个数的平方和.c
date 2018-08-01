#include <stdio.h>
int gcd(int a, int b);
int main(){
  for(int x = 1; x < 1000; x++)
    for(int y = 1; y < 1000; y++)
      for(int z = 1; z < 1000; z++)
	if(x*x + y*y == z*z && gcd(x,y) == 1)
	  printf("%d^2 * %d^2 = %d^2\n",x,y,z);
  return 0;
}
int gcd(int a, int b){//两个数的最大公倍数
  int t;
  while(b){
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
