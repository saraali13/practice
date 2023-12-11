#include <stdio.h>
#include <stdlib.h>

 typedef struct student{
 	char name[20];
 	int rollno;
 	float marks ;
 }stud ;
 void displaydata(stud arr[],int size)
 { 
   for (int i=0;i<size;i++)
   printf("%s  %d  %.3f \n",arr[i].name,arr[i].rollno,arr[i].marks);
}
int main() {
  stud ST[50]={
  	{"sam",3,77.8},
  	{"jan",7,89} };
  	int n;
  printf("enter total number of students");
  scanf("%d",&n);
displaydata(ST,n);
}
