#include <stdio.h>
#include <stdlib.h>
void MergeAndWrite()
{
	FILE *f1= fopen("file1.txt","r");
	FILE *f2= fopen("file2.txt","r");
	FILE *f3= fopen("file3.txt","w");
	if (f1==NULL || f2==NULL || f3==NULL)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	char ch;
	While (ch=fgets(f1)!=EOF)
	   fputs(ch,f3);
	While (ch=fgets(f2)!=EOF)
	   fputs(ch,f3);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	   
}
int main() {
MergeAndWrite();
}
