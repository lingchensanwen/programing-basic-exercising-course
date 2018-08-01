#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double max(double *,int n);
double min(double *,int n);
double mean(double *,int n);
double stdev(double *,int n);
int main(){
  char str[100];
  int n = 0;
  FILE *fp;
  fp = fopen("namelist.txt","r");
  if(fp == NULL){
    printf("failed with reading file");
    return 0;
  }
  while(1){
    if(NULL == fgets(str,100,fp))break;
    n++;
  }
  char *Name = (char *)malloc(sizeof(char)*n);
  double *Age = (double *)malloc(sizeof(double)*n);
  double *Height = (double *)malloc(sizeof(double)*n);
  double *Weight = (double *)malloc(sizeof(double)*n);
  fseek(fp,0L,SEEK_SET);
  int i = 0;
  while(1){
    if(fscanf(fp,"%[^,],%lf,%lf,%lf\n",Name,&Age[i],&Height[i],&Weight[i]) == EOF) break;
    i++;
  }
  fseek(fp,0L,SEEK_SET);
  printf("max of Age is %lf\n",max(Age,n));
  printf("max of Height is %lf\n",max(Height,n));
  printf("mean of Weight is %lf\n",mean(Weight,n));
  printf("Age: (max,min,mean,stdev) = (%lf,%lf,%lf,%lf)\n",max(Age,n),min(Age,n),mean(Age,n),stdev(Age,n));
  printf("Height: (max,min,mean,stdev) = (%lf,%lf,%lf,%lf)\n",max(Height,n),min(Height,n),mean(Height,n),stdev(Height,n));
  printf("Weight: (max,min,mean,stdev) = (%lf,%lf,%lf,%lf)\n",max(Weight,n),min(Weight,n),mean(Weight,n),stdev(Weight,n));
  return 0;
}
double max(double *number,int n){
  int max = 0;
  for(int i = 0; i < n; i++)
    if(max < number[i]) max = number[i];
  return max;
}
double min(double *number,int n){
  int min = 1000;
  for(int i = 0; i < n; i++)
    if(min > number[i]) min = number[i];
  return min;
}
double mean(double *number,int n){
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum = sum + number[i];
  return sum/n;
}
double stdev(double *number,int n){
  int sum = 0;
  double mean(double *,int n);
  int aver = mean(number,n);
  for(int i = 0; i < n ;i++){
    sum = (number[i] - aver)*(number[i] - aver) + sum;
  }
  return sum/n;
}
