#include <stdio.h>
#include <stdlib.h>

 struct GameCharacter{
 	char name[80];
 	float HP, AP ,DP ;
 };
 void AddCharacter(struct GameCharacter *NewCharacter)
 {
 //	struct GameCharacter NewCharacter;
 	//NewCharacter->name
 	printf("Enter character\'s detail\n");
 	printf("Enter character\'s name\n");
 	scanf(" %s",NewCharacter->name);
 	printf("Enter character\'s other detail\n");
 	scanf("%f %f %f",&NewCharacter->HP,&NewCharacter->AP,&NewCharacter->DP);
 	if ((NewCharacter->HP+NewCharacter->AP+NewCharacter->DP)==10)
 	{
 		if(NewCharacter->HP <5 && NewCharacter->AP <5 && NewCharacter->DP <5)
 		{ if(NewCharacter->HP != NewCharacter->AP && NewCharacter->DP != NewCharacter->HP && NewCharacter->AP != NewCharacter->DP)
 		{  
 		  printf("character created");
		 }
		 }
	 }
	 else 
	   {
	   	printf("enter valid input");
	    exit;
	   }
 }// end add character
 void DisplayCharacter(struct GameCharacter Character)
 {
 	printf("printing %s charcter\'s info\n\n",Character);
 	printf(" %s  %f  %f  %f \n",Character.name,Character.HP,Character.AP,Character.DP);
 	
 }
 
 
 
 
int main() {
  int n;
  struct GameCharacter Character1={"jane", 3.6 ,2.5 ,3.9};
  struct GameCharacter Character2={"tom", 4.3,2.1 ,3.6};
   struct GameCharacter Character3;
  printf("enter your choice(1-4)\n\n 1:add character\n 2:Display character\n 3:Battel simulation\n 0: To Exit\n\n");
  scanf("%d",&n);
  switch (n)
  {
  	case 1:
  		AddCharacter(&Character3);
  		break;
  	case 2:
  		DisplayCharacter(Character1);
  		DisplayCharacter(Character2);
  		DisplayCharacter(Character3);
  		break;
  //	case 3:
  //		BattelSimulation();
  //		break;
  	case 4: 
  		exit(EXIT_FAILURE);
  		break;
  	default:
  		printf("error");
  		break;
  }// end switch
}
