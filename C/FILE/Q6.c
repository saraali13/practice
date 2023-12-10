#include <stdio.h>
#include <stdlib.h>

int cnt(char c)
{  
	FILE *f1= fopen("file1.txt","r");
    int count;

	if (f1==NULL)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	char ch;
	While (ch=fgetc(f1)!=EOF) 
	{ 
	 if (ch==c)
	   count++ ; 
	}
	fclose(f1);
	  return count;  
}
int main() {
	int ch;
	printf("enter the character you want to check occurence of\n");
	scanf(" %c",ch);
cnt(ch);
}
