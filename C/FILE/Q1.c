#include <stdio.h>
#include <stdlib.h>

int main() {
 	FILE *fptr= fopen("file1.txt","w");
	if (fptr==NULL)
	{
	printf("error");
	exit(1);
	}
	fprintf(fptr,"%s %d","hello",2024);
	printf("written");
	fclose(fptr);
}
