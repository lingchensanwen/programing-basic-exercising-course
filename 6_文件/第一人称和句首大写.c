#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
  int flag = 1;
  FILE *fp1,*fp2;
  int first = 300, second;
  fp1 = fopen(argv[1],"r");
  fp2 = fopen(argv[2],"w");
  if(fp1 == NULL){
    printf("File open failed\n");
    return 1;
  }
  second = getc(fp1);
  while(1){
    if(first == 300)
      second = second - 'a' + 'A';
    if(flag == 1){
      first = second;
      second = getc(fp1);
    }
    else{
      first = getc(fp1);
      second = getc(fp1);
    }
    flag = 1;
    if(first == EOF || second == EOF)break;
    first = (char)first;
    second = (char)second;
    if(first =='i' && (second < 'a'||second > 'z')){
      first = 'I';
      putc((int)first,fp2);
      putc((int)second,fp2);
      flag = 0;
    }
    if(first == '.' || first == '?' || first == '!'){
      putc((int)first,fp2);
      if(second <= 'z' && 'a' <= second){
	second = second - 'a' + 'A';
      }
      if(second == ' '){
	putc((int)second,fp2);
	second = getc(fp1);
	if(second <= 'z' && second >= 'a')
	  second = second - 'a' + 'A';
      }
       if(second == '\"'){
	  putc((int)second,fp2);
	  second = getc(fp1);
	  if(second <= 'z' && second >= 'a')
	    second = second - 'a' + 'A';
	  if(second == ' '){
	    	putc((int)second,fp2);
		second = getc(fp1);
		if(second <= 'z' && second >= 'a')
		  second = second - 'a' + 'A';
	  }
	}
	putc((int)second,fp2);
       flag = 0;
  }
    if(first == '\"'){
      putc((int)first,fp2);
      if(second <= 'z' && second >= 'a')
	second = second - 'a' + 'A';
      putc((int)second,fp2);
      flag = 0;
    }
    if(flag == 1){
      putc((int)first,fp2);
    }
}
  fclose(fp1);
  fclose(fp2);
  return 0;
}
