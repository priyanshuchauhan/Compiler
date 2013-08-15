#include<stdio.h>
#include<string.h>

void display();
void table_entry();
int read_table(int,char);
int table[12][9];

struct production
{
	char left;
	char right[10];
}prod[12];


int main()
{
	int i,row;
	char col;
	//printf("Enter the production : ");
	prod[0].left  = 'E';
	strcpy(prod[0].right,"E+T");
	prod[1].left  = 'E';
	strcpy(prod[1].right,"T");
	prod[2].left  = 'E';
	strcpy(prod[2].right,"T*F");
	prod[3].left  = 'T';
	strcpy(prod[3].right,"F");
	prod[4].left  = 'F';
	strcpy(prod[4].right,"(E)");
	prod[5].left  = 'F';
	strcpy(prod[5].right,"id");
	display();
	
	//table entries
	table_entry();
	
	printf("\nEnter row : ");
	scanf("%d",&row);
	fflush(stdin);
	printf("\nEnter column : ");
	col = getchar();
	col = getchar();
	
	int value = read_table(row,col);
	
	if(value<12)
		printf("\nS",value);
	else if(value>15 && value<20)
		printf("\nR", );

	return 0;
}


void display()
{
	int i;	
	printf("\nInput Productions \n");
	for(i=0;i<7;i++)
		printf("\n%c -> %s",prod[i].left,prod[i].right);
	
}

void table_entry()
{
	//1-12 for shift and 15-20 for reduce, 100 for accept
	//if column number > 6 then its terminal
	
	table[0][0] = 5;
	table[0][3] = 4;
	table[0][6] = 1;
	table[0][7] = 2;
	table[0][8] = 3;
	
	table[1][1] = 6;
	table[1][0] = 100;
	
	table[2][1] = 16;
	table[2][2] = 7;
	table[2][4] = 16;
	table[2][5] = 16;
	

	table[3][1] = 18;
	table[3][2] = 18;
	table[3][4] = 18;
	table[3][5] = 18;

	table[4][0] = 5;
	table[4][3] = 4;
	table[4][6] = 8;
	table[4][7] = 2;
	table[4][8] = 3;

	table[5][1] = 20;
	table[5][2] = 20;
	table[5][4] = 20;
	table[5][5] = 20;
	table[5][8] = 3;

	table[6][0] = 5;
	table[6][3] = 4;
	table[6][7] = 9;
	table[6][8] = 3;

	table[7][0] = 5;
	table[7][3] = 4;
	table[7][8] = 10;

	table[8][1] = 6;
	table[8][4] = 11;

	table[9][1] = 15;
	table[9][2] = 7;
	table[9][4] = 15;
	table[9][5] = 15;

	table[10][1] = 17;
	table[10][2] = 17;
	table[10][4] = 17;
	table[10][5] = 19;

	table[11][1] = 19;
	table[11][2] = 19;
	table[11][4] = 19;
	table[11][5] = 19;
}

int read_table(int row, char col)
{
	switch(col)
	{
		case 'i':
			return table[row][0];
		case '+':
			return table[row][1];
		case '*':
			return table[row][2];
		case '(':
			return table[row][3];
		case ')':
			return table[row][4];
		case '$':
			return table[row][5];
		case 'E':
			return table[row][6];
		case 'T':
			return table[row][7];
		case 'F':
			return table[row][8];
	}

}





