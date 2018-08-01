#include <stdio.h>
#include <stdlib.h>
int roman2num(char*);
int change_number(char*);
int main() {
     // Examples
     printf("XIV = %d\n", roman2num("XIV")); //14
     printf("CDXCV = %d\n", roman2num("CDXCV")); //495
     printf("MCMXLV = %d\n", roman2num("MCMXLV")); //1945
     printf("MMMCMXCIX = %d\n", roman2num("MMMCMXCIX")); //3999
     return 0;
}
int roman2num(char *s) {
  int copy;
  int next;
  int sum = 0;
  while(*s != '\0'){
    copy = change_number(s);
    s++;
    next = change_number(s);
    if(next <= copy){
      sum = sum + copy;
    }
    else{
      sum = sum - copy;
    }
  }
  return sum;
}
int change_number(char* s){
    if(*s == 'I'){
      return  1;
    }
     if(*s == 'V'){
      return 5;
    } 
     if(*s == 'X'){
      return 10;
    }
     if(*s == 'L'){
      return 50;
    }
     if(*s == 'C'){
      return  100;
    }
     if(*s == 'D'){
      return 500;
    }
     if(*s == 'M'){
      return 1000;
    }
}
