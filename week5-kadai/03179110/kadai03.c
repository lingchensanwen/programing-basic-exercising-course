#include <stdio.h>
void reverse(char *s);
int main() {
  char s[] = "hello";
  reverse(s);
  printf("%s\n",s); // 出力 "olleh"
  return 0;
}
void reverse(char *s){
  int length = 0;
  char temp;
  char *copy = s;
  while(*copy != '\0'){
    length++;
    copy++;
  }
  for(int i = 0; i < (length /2); i++){
    temp = *(s+i);
    *(s+i) = *(s+length-1-i);
    *(s+length-1-i) = temp;
  }
}
