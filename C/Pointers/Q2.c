#include <stdio.h>
#include <stdlib.h>
int output(int *arr,int size)
{
	int brr[size];
	for (int i=0; i<size; i++)
	{
		if(i%2 !=0)
		{
			brr[i]=arr[i-1]*arr[i+1];
		}
	else
		brr[i]=arr[i];
	}
	for (int i=0;i<size;i++)
	{
		printf("%d ,",brr[i]);
	}
}
int main ()
{   
    int n;
    printf("enter size");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
    	scanf("%d",&ptr[i]);
	}
	output(ptr,n);
}
