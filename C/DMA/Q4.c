
#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int n;
	printf("enter size of an array\n");
	scanf("%d",&n);
	int *a=(int*)calloc(n,sizeof(int));
	printf("enter elements in an array\n");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for (int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
     a=(int*)realloc(a,n+2);
   
		for (int i=0;i<n+2;i++)
	{
		printf("%d ",a[i]);
	}
return 1;
}// end main
