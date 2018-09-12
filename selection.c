#include<stdio.h>
#include<malloc.h>

int get_min_pos(int *arr,int i,int n)
{
 int j,min=arr[i],pos=i;
 for(j=i+1;j<n;j++)
 {
  if(min>arr[j])
   {
   min=arr[j];
   pos=j;
   }
 }
 return pos;
}

int* selection_sort(int *nos,int n)
{
 int i,minp,tmp;
 for(i=0;i<n;i++)
 {
  minp=get_min_pos(nos,i,n);
  tmp=nos[i];
  nos[i]=nos[minp];
  nos[minp]=tmp;
 }
 return nos;
}

int main(void)
{
 int i,n,*nos;
 fprintf(stdout,"\nNo of elements: ");
 fscanf(stdin,"%d",&n);
 nos=(int*)malloc(sizeof(int)*n);
 fprintf(stdout,"\nEnter elements:\n");
 for(i=0;i<n;i++)
  fscanf(stdin,"%d",&nos[i]);
 nos=selection_sort(nos,n); 
  fprintf(stdout,"\nSorted elements:\n");
 for(i=0;i<n;i++)
  fprintf(stdout,"\t%d",nos[i]);
 return 0;
}
