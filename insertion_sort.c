#include<stdio.h>
#include<malloc.h>

int* insertion_sort(int *nos,int n)
{
 int i,j,k,m,temp;
 for(i=1;i<n;i++)
 { 
  m=i;
  k=nos[m];
  for(j=i-1;j>=0;j--)
  {
   if(k<nos[j])
   {
    temp=k;
    nos[m]=nos[j];
    nos[j]=temp; 
    k=nos[--m];
   } 
  } 
 }
return nos;
}

int main()
{
 int i,n,*nos;
 fprintf(stdout,"\nNo of elements: ");
 fscanf(stdin,"%d",&n);
 nos=(int*)malloc(sizeof(int)*n);
 fprintf(stdout,"\nEnter elements:\n");
 for(i=0;i<n;i++)
  fscanf(stdin,"%d",&nos[i]);
 nos=insertion_sort(nos,n); 
  fprintf(stdout,"\nSorted elements:\n");
 for(i=0;i<n;i++)
  fprintf(stdout,"\t%d",nos[i]);

 return 0;
}
