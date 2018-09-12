#include<stdio.h>

void heapify(int c,int k,int i,int * arr )
{
        int j=0;
        if(i<k && i<=c)
        {
                j=i*2;
                if(arr[i]<arr[j+1] && j+1 < k)
                {
                        arr[i]^=arr[j+1];
                        arr[j+1]^=arr[i];
                        arr[i]^=arr[j+1];
                        heapify(c,k,j+1,arr);
                
                }
                if(arr[i]<arr[j+2] && j+2 < k)
                {
                        arr[i]^=arr[j+2];
                        arr[j+2]^=arr[i];
                        arr[i]^=arr[j+2];
                        heapify(c,k,j+2,arr);
                
                
                }
        }       

}

void maxheap(int c,int *arr)
{
    int i,j,max=0;
    for(i=(c/2-1);i>=0;i--)
    {   
        j=i*2;
        if(arr[j+1] >= arr[j+2])
        {
            j+=1;
        }   
        else 
        {
            j+=2;
        }   
        if (arr[i]<arr[j])
        {
            arr[i]^=arr[j];
            arr[j]^=arr[i];
            arr[i]^=arr[j];
            heapify((c/2-1),c,j,arr);
        }
            
    }
    printf("\nMAX HEAP\n");
    for(i=0;i<c;i++)
        printf("\t%d",arr[i]);
}



void hsort(int c,int* arr)
{
    int k=c-1,i;    
    maxheap(c,arr);
    for(;k>0;k--)
    {
        arr[0]^=arr[k];
        arr[k]^=arr[0];
        arr[0]^=arr[k];
        
        heapify((c/2-1),k,0,arr);
        printf("\nTEST\n");
        for(i=0;i<c;i++)
         printf("\t%d",arr[i]);

    }
    printf("\n HEAP SORTED\n");
    for(i=0;i<c;i++)
        printf("\t%d",arr[i]);

}


int main(void)
{
        int i,n,*num;
        printf("\nEnter n:");
        scanf("%d",&n);
        printf("\nEnter Elements:");
        for(i=0;i<n;i++)
        {
                scanf("%d",&num[i]);
        } 
        printf("\nBEFORE:\n");
        for(i=0;i<n;i++)
        {
                printf("\t%d",num[i]);
        }      
        hsort(n,num);
                       
        return 0;
}
