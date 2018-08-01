#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n = 0;
struct person{
  char name[20];
  int age;
  double weight;
  double height;
  struct person *next;
  struct person *last;
};
void delete(struct person* h, char *s);
void show_linklist(struct person *h);
int main(int argc,char* agrv[]){
  FILE *fp1,*fp2;
  char str[100];
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
    info[i].last = NULL;
    info[i].next = NULL;
    if(fscanf(fp1,"%[^,],%d,%lf,%lf\n",info[i].name,&info[i].age,&info[i].weight,&info[i].height) == EOF)break;
    info[i].next = &info[i+1];
    if(i >= 1)
      info[i].last = &info[i-1]; 
    i = i + 1;
  }
    while(1){
    info[i].last = NULL;
    info[i].next = NULL;
    if(fscanf(fp2,"%[^,],%d,%lf,%lf\n",info[i].name,&info[i].age,&info[i].weight,&info[i].height) == EOF)break;
    info[i].next = &info[i+1];
    if(i>=1)
      info[i].last = &info[i-1];
    i = i + 1;
  }
  show_linklist(info);
  printf("if you want to delete the information of a person\n");
  printf("input the info of person you want to delete:\n");
  char *somebody = (char*)malloc(sizeof(char));
  scanf("%s",somebody);
  printf("somebody as %s\n",somebody);
  delete(info,somebody);
  show_linklist(info);
  fclose(fp1);
  fclose(fp2);
  return 0;
}
void delete(struct person* h, char *s){
  int i = 0;
  h->last = NULL;
  while(1){
    if(strcmp(h->name,s) == 0){
      h->last->next = h->next;
      h->next->last = h->last;
    }
    h = h->next;
    i = i + 1;
    if(h->next == NULL)break;
    }
}
void show_linklist(struct person *h){
  int i = 0;
  while(1){
  printf("linklist[%d] is %s,%d,%lf,%lf\n",i,h->name,h->age,h->weight,h->height);
  h = h->next;
  if(h->next == NULL)break;
  i++;
  }
}

