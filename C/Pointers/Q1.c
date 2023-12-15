#include <stdio.h>
#include <stdlib.h>
int strlen(char *str)
{
	int count=0;
	while (*str!='\0')
	{
		*str++;
		count++;
	}
	return count;
}

int main ()
{   
  char arr[20]="hello world";
  int count=strlen(arr);
  printf("%d",count);
  
}
