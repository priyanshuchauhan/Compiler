#include<stdio.h>
#define MAX 20

char table[4][MAX][MAX];
int  y1=0;
int  y2=0;
int  y3=0;

void insert(char[],char[]);
void display_table();

int main()
{
	int i,j,len,bs,state,pos;
	char str[MAX];
	char id[MAX];
	bs = 0;
	printf("\nEnter the string : \n");
	gets(str);
	printf("\n");
	state =0;

	for(i=0; i<strlen(str); i++)
	{
		if(isalpha(str[i]))
		{
		   switch(state)
		   {	
				//int,if,for,case,while
				case 0:
					if(str[i]=='i' || str[i]=='f' || str[i]=='c' || str[i]=='w')
						state = 1;
					else
					{
						state = 0;
						id[0] = str[i];
						printf("Identifier - %c\n",str[i]);
						insert("identifier",id);						
					}
					break;
				
				case 1 :
					if(str[i]=='n' || str[i]=='o' || str[i]=='a' || str[i]=='h')
						state = 2;
					else if(str[i] =='f')
					{
						state = 0;
						printf("Keyword - if \n");
						insert("keyword","if");	
					}
					else
					{
						state = 0;
						id[0] = 'i';
						printf("Identifier - i%c\n",str[i]);
						insert("identifier",id);						
					}
					break;
					
				case 2:
					if(str[i]=='t')
					{
						state = 0;
						printf("Keyword - int \n");
						insert("keyword","int");
					}
					else if(str[i]=='r')
					{
						state = 0;
						printf("Keyword - for \n");
						insert("keyword","for");
					}
					else if(str[i]=='s' || str[i]=='i')
						state = 3;
					break;
				
				case 3:
					if(str[i]=='e')
					{
						state = 0;
						printf("Keyword - case \n");
						insert("keyword","case");
					}
					else if(str[i]=='l')
						state = 4;
					break;
				
				case 4:
					if(str[i]=='e')
					{
						state = 0;
						printf("Keyword - while \n");
						insert("keyword","while");
					}
			}
			
			if(state == 1 && !isalpha(str[i+1]))
			{
				state = 0;
				id[0] = 'i';
				printf("Identifier - i \n");
				insert("identifier",id);
			}
		}
		
		else
		{
			switch(str[i])
			{
				case ' ':
					printf("Blank Space \n");
					bs++;
					break;
					
				case '<':
					printf("Relational Operator < \n");
					insert("operator","<");
					break;
					
				case '>':
					printf("Relational Operator > \n");
					insert("operator",">");
					break;
					
				case '=':
					printf("Assignment Operator = \n");
					insert("operator","=");
					break;
					
				case '!':
					if(str[i+1] == '=')
					{
						printf("Relational Operator != \n");
						//insert("operator","!=");
						i++;
					}
					else
					{
						printf("Unary Operator ! \n");
						insert("operator","!");
					}
					break;
				
				case '+':
					printf("Arithmetic Operator + \n");
					insert("operator","+");
					break;	
					
				case '-':
					printf("Arithmetic Operator - \n");
					insert("operator","-");
					break;	
					
				default:
					if(str[i]=='0' || str[i]=='1' || str[i]=='2' || str[i]=='3' || str[i]=='4' || str[i]=='5' || str[i]=='6' || 
					   str[i]=='7' || str[i]=='8' || str[i]=='9')
					{
						printf("Constant %c \n",str[i]);
						id[0] = str[i];
						insert("constant",id);
					}
					else
						printf("Undefined Default Character \n");
			}
		}
	}
	printf("Number of blank spaces = %d  \n",bs);
	display_table();
	return 0;
}

void insert(char token[],char attribute[])
{	
	int i;
	//keywords
	if(!strcmp(token,"keyword"))
	{
		if(!strcmp(attribute,"if"))
		{
			i=0;
			table[0][0][i++]='i';
			table[0][0][i]  ='f';
		}
		else if(!strcmp(attribute,"int"))
		{
			i=0;
			table[0][1][i++]='i';
			table[0][1][i++]='n';
			table[0][1][i]  ='t';
		}	
		else if(!strcmp(attribute,"for"))
		{
			i=0;
			table[0][2][i++]='f';
			table[0][2][i++]='o';
			table[0][2][i]  ='r';
		}	
		else if(!strcmp(attribute,"case"))
		{
			i=0;
			table[0][3][i++]='c';
			table[0][3][i++]='a';
			table[0][3][i++]='s';
			table[0][3][i]  ='e';
		}	
		else if(!strcmp(attribute,"while"))
		{
			i=0;
			table[0][4][i++]='w';
			table[0][4][i++]='h';
			table[0][4][i++]='i';
			table[0][4][i++]  ='l';
			table[0][4][i]  ='e';
		}	
	}

	//Identifier
	else if(!strcmp(token,"identifier"))
		table[1][y1++][0]=attribute[0];
	
	//Operator
	else if(!strcmp(token,"operator"))
		table[2][y2++][0]=attribute[0];
	
	//Constant
	else if(!strcmp(token,"constant"))
		table[3][y3++][0]=attribute[0];
}

void display_table()
{
		int i,j,k;
		printf("\n\nSymbol  Table");
		printf(" \n________________________________________________________________________________");
		printf("\nTokens \t\t Attributes");
		printf(" \n________________________________________________________________________________\n");
		for(i=0;i<4;i++)
		{
			if(i==0)
				printf("\nKeyword \t");
			else if(i==1)
				printf("\n\nIdentifier \t");
			else if(i==2)
				printf("\n\nOperator \t");
			else if(i==3)
				printf("\n\nConstant \t");
				
			for(j=0;j<6;j++)
				for(k=0;k<6;k++)
					printf("%c",table[i][j][k]);
				printf("  ");
		}
		printf("\n________________________________________________________________________________\n");
}


