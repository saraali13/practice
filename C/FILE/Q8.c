#include <stdio.h>
#include <stdlib.h>
//function to add catagory infile 
void AddCatagory()
{
	char C_Name[20];//catahory name
	int C_ID;//catagory ID
	FILE *ptr1=fopen("catagory.txt","a");
	//taking input 
	printf("enter catagory name and ID\n");
	scanf("%s %d",C_Name[20],C_ID);
	if (ptr1==NULL)
	{
		printf("error");
		exit(EXIT_FAILURE); //file doesnot exsit
	}// end if
	fprintf(ptr1,"%s %d \n",C_Name,C_ID);
	printf("written in file catagory.txt\n");
	fclose(ptr1);
}// end AddCatagory
void AddProducts()
{
	char P_Name[20];//product name
	float P_Price;//product price
	int P_ID;//product ID
	FILE *ptr2=fopen("product.txt","a");
	//taking input 
	printf("enter product name ,price and ID\n");
	scanf("%s %f %d",P_Name[20],P_Price,P_ID);
	if (ptr2==NULL)
	{
		printf("error");
		exit(EXIT_FAILURE); //file doesnot exsit
	}// end if
	fprintf(ptr1,"%s %f %d \n",P_Name,P_Price,P_ID);
	printf("written in file product.txt\n");
	fclose(ptr2);
}//end AddProduct
void GenerateFinalResult()
{
	FILE *ptr1= fopen("catagory.txt","r");
	FILE *ptr2= fopen("product.txt","r");
	FILE *ptr3= fopen("final.txt","w");
	if (ptr1==NULL || ptr2==NULL || ptr3==NULL)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	char C_Name[20];//catahory name
	int C_ID;//catagory ID
	char P_Name[20];//product name
	float P_Price;//product price
	int P_ID;//product ID
 
	
	
	While (!feof(ptr1))//till end of catagory file
	{ 
	  fscanf(ptr1,"%s %d",C_Name,C_ID);
	  fprintf(ptr3,"%s",C_Name);//prining catagoryname in final.txt file
	  While (!feof(ptr2))//till end of product file
	  {
	  	fscanf(ptr2,"%s %f %d",P_Name,P_Price,P_ID);
	  	if (C_ID==P_ID) // if product is having same ID as catagory only then it will be printed in final.txt file
	    {
		 fprintf(ptr3,"%s %f \n",P_Name,P_Price);
	    }
	  }
	}
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr3);  
}// End GenerateFinalResult
int main() 
{ 
  int n;
  printf("enter your choice(1-4)");
  scanf("%d",&n);
  switch (n)
  {
  	case 1:
  		AddCatagory();
  		break;
  	case 2:
  		AddProduct();
  		break;
  	case 3:
  		GenerateFinalResult();
  		break;
  	case 4:
  		exit(EXIT_FAILURE);
  		break;
  	default:
  		printf("error");
  		break;
  }// end switch
}// end main
