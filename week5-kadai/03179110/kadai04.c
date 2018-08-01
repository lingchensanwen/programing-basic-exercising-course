#include <stdio.h>
void uppercase(char* p);
int main(){
  char s[] = "hello world";
  uppercase(s);
  printf("%s\n",s);
  return 0;
}
void uppercase(char* p){
  while(*p != '\0'){
  if(*p == ' ')
    p++;
  *p = *p - ('a'-'A');
  p++;}
}
