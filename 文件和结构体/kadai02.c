#include <stdio.h>
#include <stdlib.h>
struct person{
  char name[20];
  int age;
  double weight;
  double height;
  struct person *next;
};
int main(int argc,char* agrv[]){
  FILE *fp1,*fp2;
  char str[100];
  int n = 0;
  fp1 = fopen(agrv[1],"r");
  fp2 = fopen(agrv[2],"r");
  while(1){
    if(NULL == fgets(str,100,fp1))
      break;
    n++;
  }
  while(1){
    if(NULL == fgets(str,100,fp2))
      break;
    n++;
  }
  fseek(fp1,0L,SEEK_SET);
  fseek(fp2,0L,SEEK_SET); 
  struct person* info = (struct person*)malloc(sizeof(struct person)*n);
  int i = 0;
  while(1){
    info[i].next = NULL;
    if(fscanf(fp1,"%[^,],%d,%lf,%lf\n",info[i].name,&info[i].age,&info[i].weight,&info[i].height) == EOF)break;
    info[i].next = &info[i+1];
    i = i + 1;
  }
    while(1){
    info[i].next = NULL;
    if(fscanf(fp2,"%[^,],%d,%lf,%lf\n",info[i].name,&info[i].age,&info[i].weight,&info[i].height) == EOF)break;
    info[i].next = &info[i+1];
    i = i + 1;
  }
  for(i = 0; i < n; i++){
    printf("info[%d] is %s,%d,%lf,%lf\n",i,info[i].name,info[i].age,info[i].weight,info[i].height);
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
