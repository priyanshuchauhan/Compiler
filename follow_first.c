//wap to find first and follow of a given grammar

#include<stdio.h>
#include<string.h>

int first(int n);
int follow(int m,int n);
void display(int n);

struct production
{
	char left[10];
	char right[10][10];
}prod;


int main()
{
	int i,j,n;
	printf("Enter Number of productions : ");
	scanf("%d",&n);	
	
	for(i=0; i<n; i++)
	{	
		fflush(stdin);
		printf("\nEnter the left  of production  %d : ",(i+1));
		prod.left[i] = getchar();
		
		fflush(stdin);
		printf("Enter the right of production  %d : ",(i+1));
		gets(prod.right[i]);
	}
	
	printf("\n\nEntered Productions : \n");
	display(n);
	
	for(i=0; i<n; i++)
	{
		printf("\nFirst(%c) = {",prod.left[i]);
		first(i);
	}
	printf("\n");
	
	for(i=0; i<n; i++)
	{
		printf("\nFollow(%c) = {",prod.left[i]);
		follow(i,n);
	}
	printf("\n");
		
	return 0;
}


int first(int m)
{
	int i = 0;
	
	//rule 1,3
	if((int)(prod.right[m][0])>64 && (int)(prod.right[m][0])<91)
	{
		//non-terminal
		while( prod.right[m][0] != prod.left[i] )
			i++;
		first(i);
	}
	
	else
	{
		//terminal
		printf("%c}",prod.right[m][0]);
		return 0;
	}
}


int follow(int m,int n)
{
	int i,j,k = 0;
	//rule 1,2
	for(i=0; i<n; i++)
	{
		//outer loop for checking all productions
		for(j=0; j<strlen(prod.right[i]); j++)
		{
			//inner loop for checking string of the outer production			
			if( prod.left[m] == prod.right[i][j] )
			{
				if( (int)(prod.right[i][j+1])>64 && (int)(prod.right[i][j+1])<91)
				{
					//Follow is a production, apply rule 2
					for( k=0; (prod.right[i][j+1] != prod.left[k]); k++);
					first(k);
					break;
				}
				
				else
				{
					printf("%c}",prod.right[i][j+1]);
					break;
				}
			}
		}
	}
	return 0;
}


void display(int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%c",prod.left[i]);
		printf(" -> ");
		printf("%s",prod.right[i]);
		printf("\n");
	}
}
