#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* agrv[]){
  FILE *fp;
  int flag = 1;
  int counter_i = 0;
  int counter_j = 0;
  int first, second;
  fp = fopen(agrv[1],"r");
  if(fp == NULL){
    printf("read files with error!\n");
  }
  while(1){
    first = fgetc(fp);
    second = fgetc(fp);
    if(first == EOF || second == EOF)break;
    if((char)first != '\t' && (char)first != '\n'){
      if((char)second == '\t')
	counter_i++;
      if((char)second == '\n')
	counter_j++;
      if((char)second != '\t' && (char)second != '\n')
	counter_i++;
    }
    if((char)first == '\t'){
      first = second;
      second = fgetc(fp);
      if((char)second == '\t')
	counter_i++;
      if((char)second == '\n')
	counter_j++;
      if((char)second != '\t' && (char)second != '\n')
	counter_i++;
    }
    if((char)first == '\n')
       counter_j++;
  }
  printf("i is %d,j is %d\n",counter_i/counter_j,counter_j);
  fseek(fp,0L,SEEK_SET);
  int *table = (int*)malloc(sizeof(int)*counter_i*counter_j);
  first = (int)first;
  second =(int)second;
  first = getc(fp);
  second = getc(fp);
  int n = 0;
  while(1){
      flag = 1;
    if(((char)first == '\t' ||(char)first == '\n' )&& flag){
          first = second;
          second = getc(fp);
          flag = 0;
    }
      if((char)second == '\n'&& flag){
          first = getc(fp);
          second = getc(fp);
          flag = 0;
      }
    if(((char)first != '\t' && (char)first != '\n')&& flag){
      if((char)second == '\t' || (char)second == '\n'){
          table[n] =first - '0';//one number
          n++;
          flag = 0;
          first = getc(fp);
          second = getc(fp);
      }
      if(((char)second != '\t' && (char)second != '\n')&&flag){
          table[n] = (first - '0') * 10 + second - '0';
          n++;//two number}
          flag = 0;
          first = getc(fp);
          second = getc(fp);
      }
    }
      if(flag == 1){
          first = getc(fp);
          second = getc(fp);
      }
      if(first == EOF || second == EOF)break;
  }

  for(int i = 0; i < n; i++)
    printf("%d\t",table[i]);
  return 0;
}
