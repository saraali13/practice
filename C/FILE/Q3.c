#include <stdio.h>
#include <stdlib.h>

int main() {
 	FILE *fptr= fopen("file1.txt","a");
	if (fptr==NULL)
	{
	printf("error");
	exit(1);
	}
	char arr[20][20];
    while ( fgets(arr,sizeof(arr),fptr) != NULL)
    {
    	printf("%s",arr);
	}
	fseek(fptr,20,SEEK_SET);
	  fprintf(fptr,"%s","hello 123");
	printf("written");
	fclose(fptr);
}
