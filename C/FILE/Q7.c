#include <stdio.h>
#include <stdlib.h>

void ReadLine(int line)
{  
	FILE *f1= fopen("file1.txt","r");
    int linecount=0;

	if (f1==NULL)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	char arr[50];
	While (fgets(arr,sizeof(arr),f1)!=EOF) 
	{ 
	  linecount++;
	 if (linecount==line)
	  { 
	   prinf("line is %d containing %s",linecount,arr)
	   } 
	}
	fclose(f1);
}
int main() {
	int n;
	printf("enter the number of line you want to read\n");
	scanf(" %d",&n);
ReadLine(n);
}
