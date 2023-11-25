#include <stdio.h>
int main(){
	int arr[5]={1,2,3,4,5} ;
	int n,i=5;
	printf("enter the value of an array you want" );
	scanf("%d",&n);
	if (n>i)
	{ printf("invalid input");
	}
	else {
	
    printf("the value is %d\n",arr[n]);
}
	return 1;
}//end main
