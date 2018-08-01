#include <stdio.h>
#include <math.h>
#define P_MAX 3000
int is_prime(int x);
int main(){
    double mult = 1;
    int PRIME[P_MAX] = {0};
    for(int i = 2; i < P_MAX ; i++){
        if(is_prime(i))
	  PRIME[i] = i;
    }
    for(int i = 2; i < P_MAX; i++){
      //printf("prime is %d\n",PRIME[i]);
      if(PRIME[i]!=0)
      mult = mult * (1-1.0/pow(PRIME[i],2));
    }
    printf("pi is %f\n",sqrt(6.0/mult));
    return 0;
}
int is_prime(int x){
    for(int i = 2; i < x ; i++){
        if((x % i) == 0)
            return 0;
    }
    return 1;
}
