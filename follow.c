//wap to find first and follow of a given grammar

#include<stdio.h>
#include<string.h>

void first(int n);
void display(int n);

struct production
{
	char left[10][10];
	char right[10][10];
}prod;


int main()
{
	int i,j,n;
	printf("Enter Number of productions : ");
	scanf("%d",&n);	

	printf("\nEnter the left of production  1 : ");
	gets(prod.left[0]);

	for(i=0; i<n; i++)
	{	
		if(i!=0)
			printf("\nEnter the left of production  %d : ",(i+1));
		gets(prod.left[i]);
		printf("\nEnter the right of production  %d : ",(i+1));
		gets(prod.right[i]);
	}
	printf("\nEntered Productions : \n");
	display(n);
	first(n);
	return 0;
}

void display(int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%s",prod.left[i]);
		printf(" -> ");
		printf("%s",prod.right[i]);
		printf("\n");
	}
}



void first(int n)
{
	int i,j;
	
	//rule 1
	printf("%d",strlen(prod.right[0]));
	for(i=0; i<n; i++)
	{
		if((int)(prod.right[i][0])>64 && (int)(prod.right[i][0])<91)
		{
			//non-terminal
			//first();
		}
		else
		{
			//terminal
			printf("\n\nFirst(%s) = %c \n\n",prod.left[i],prod.right[i][0]);
		}
	}
}





