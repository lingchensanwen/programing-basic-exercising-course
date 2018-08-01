#include <stdio.h>
int is_prime(int x);
int main(){
    int flag[1000];
    for(int i = 2; i < 1000 ; i++){
      flag[i] = 0;
      for(int j = 2; j <= 2*i-2;j++)
	if(is_prime(j) + is_prime(2*i-j) == 2)
	  flag[i] = 1;
    }
    for(int i = 2; i < 1000; i++)
      if(flag[i] == 0){
	printf("no\n");
	  break;
      }
    printf("yes\n");
    return 0;
}
int is_prime(int x){
    for(int i = 2; i < x ; i++){
        if((x % i) == 0)
            return 0;
    }
    return 1;
}
