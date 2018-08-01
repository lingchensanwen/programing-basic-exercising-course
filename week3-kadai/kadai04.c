#include <stdio.h>
int mod_apm(int a,int p,int m);
int main(){
  int a = 541, p = 1234, m = 1299709;
  printf("the result is : %d\n",mod_apm(a,p,m));
  return 0;
}
int mod_apm(int a,int p,int m){
  if(p == 1)
    return a % m;
  else{
    return (a *  mod_apm(a,p-1,m)) % m;
  }
}
