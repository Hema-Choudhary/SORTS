#include<stdio.h>
#include<malloc.h>

void sort(int **arr,int i,int j,int n)
{
  int k,l,tmp;  
  for(k=0;k<j;k++)
   {
   if(i+k+j<n)
   {
    for(l=0;l<j;l++)
    {
     if((*arr)[i+l]>(*arr)[i+k+j])
      {
       tmp=(*arr)[i+l];
       (*arr)[i+l]=(*arr)[i+k+j];
       (*arr)[i+k+j]=tmp;
      } 
     }
    }
   else
    break;
   }
}

int * merge_sort(int *arr,int n)
{
 int j,i;
 j=1;
 while(j<=n)
 {
 for(i=0;i<n;i=i+(j*2))
 {
  sort(&arr,i,j,n);
 }
 j=j*2;
 }
 return arr; 
}

int main(void)
{
 int *arr,n,i,*sorted;
 fprintf(stdout,"\nEnter no of elements:");
 fscanf(stdin,"%d",&n);
 arr=(int *)malloc(sizeof(int)*n);
 sorted=(int *)malloc(sizeof(int)*n);
 fprintf(stdout,"\nEnter elements:");
 for(i=0;i<n;i++)
  fscanf(stdin,"%d",&arr[i]);
 arr=merge_sort(arr,n);
 fprintf(stdout,"\nSorted elements:\n");
 for(i=0;i<n;i++)
  fprintf(stdout,"\t %d",arr[i]); 
 return 0;
}
