#include <stdio.h>
#include <stdlib.h>

int main() {
 	FILE *fptr= fopen("file1.txt","r");
	if (fptr==NULL)
	{
	printf("error");
	exit(1);
	}
	char arr[20];
    while ( fgets(arr,sizeof(arr),fptr) != EOF)
    {
    	printf("%s",arr);
	}
	printf("written");
	fclose(fptr);
}
