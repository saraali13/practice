#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int n;
	printf("enter size of an array\n");
	scanf("%d",&n);
	int *a=(int*)calloc(n,sizeof(int));
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for (int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
return 1;
}// end main
