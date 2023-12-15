#include <stdio.h>
#include <stdlib.h>

int main ()
{   
    int n;
    printf("enter size");
    scanf("%d",&n);
    int **ptr=(int**)malloc(n*sizeof(int*));
    for (int i=0; i<n ; i++)
    {    ptr[i]=(int*)malloc(n*sizeof(int));
    //	for (int j=0 ;j<n; j++)
    	
      //  {  
    
    	//}   
    }
    for (int i=0; i<n ; i++)
         {
         //	printf("wrr");
    for(int j=0; j<n ; j++)
         {
         //	printf("ew");
        scanf("%d ",&ptr[i][j]);
        
          }
      }
       for (int i=0; i<n ; i++)
         {
       	for(int j=0; j<n ; j++)
         {
         //	printf("ewewwrr");
        printf("%d ",ptr[i][j]);
        
          }
          printf("\n");
      }
}
