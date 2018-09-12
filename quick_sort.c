#include<stdio.h>
#include<malloc.h>

int get_p(int *nos,int x,int y)
{
 int piv,tmp,l,u;
 l=x;
 u=y;
 piv=nos[x];
 while(1)
 {
  while(piv>=nos[l] && l<y)
   l++;
  while(piv<nos[u] && u>x)
   u--;
  if(l<u)
  {
   tmp=nos[l];
   nos[l]=nos[u];
   nos[u]=tmp;
  }  
 else
  break; 
 }
 nos[x]=nos[u];
 nos[u]=piv;
 return u;
}

int quick_sort(int *nos,int x,int y)
{
 int z;
 if(x<y)
 {
  z=get_p(nos,x,y);
  quick_sort(nos,x,z-1);
  quick_sort(nos,z+1,y);
 }
}

int main(void)
{ 
 int i,n,*nos;
 fprintf(stdout,"\nEnter the no of elemets:");
 fscanf(stdin,"%d",&n);
 nos=(int *)malloc(sizeof(int)*n);
 fprintf(stdout,"\nEnter the elements:");
 for(i=0;i<n;i++)
  fscanf(stdin,"%d",&nos[i]);
 quick_sort(nos,0,n-1);
 fprintf(stdout,"\nSorted elements:\n");
 for(i=0;i<n;i++)
  fprintf(stdout,"\t%d",nos[i]);
 
 return 0;
}
