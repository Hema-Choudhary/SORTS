#include<stdio.h>
#include<malloc.h>


void sort(int **arr,int n,int s)
{
 int i,l,k,tmp;
 
 for(i=0;i<s;i=i+n)
 {
   for(k=1;k<n;k++)
   {
   if(i+(n-k)<s)
   {
    for(l=i;l<i+(n-k);l++)
    {
     if((*arr)[l]>(*arr)[l+1])
      {
       tmp=(*arr)[l];
       (*arr)[l]=(*arr)[l+1];
       (*arr)[l+1]=tmp;
      } 
     }
    }
   else
    break;
  }
 }
}

void merge_sort(int **arr,int n,int s)
{
 if(n==1)
  return;
 else 
  merge_sort(arr,n/2,s);
 sort(arr,n,s); 
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
 merge_sort(&arr,n,n);
 fprintf(stdout,"\nSorted elements:\n");
 for(i=0;i<n;i++)
  fprintf(stdout,"\t %d",arr[i]); 
 return 0;
}
