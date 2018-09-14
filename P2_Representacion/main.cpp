#include <stdio.h> 
#include <stdlib.h> 
#include<time.h>

void binario();
void grey();
void real();
void entero();


int main()
{
	fflush(stdin);
	int a,b;

	printf("Que desea hacer: \n");
	printf("1)Binario \n");
	printf("2)Grey \n");
	printf("3)Real \n");
	printf("4)Entero \n");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
			binario();
		break;
			
		case 2:
			grey();
		break;
			
		case 3:
			real();
		break;
		
		case 4:
			entero();
		break;
		
		default:
		break;	
	}
	
	printf("Desea volver a calcular algo: 1=Si 2=No \n");
	scanf("%d",&b);
	if(b==1)
	{
		system("cls");
		main();
	}
	
return 0;	
}

void binario()
{
	system("cls");
	int i,j;
	int arrg[10][10];
		
	srand(time(0)); 
	for(i=0;i<10;i++)
	{
		printf("individuo %d \n\n",i+1);
		for(j=0;j<10;j++)
		{
			arrg[i][j]=rand()%2;
			printf("%d ",arrg[i][j]);		
		}
		printf("\n\n");	
	}		
}

void grey()
{
	system("cls");
	int i,j,h;
	int arrg[10][10];
	int arrgrey[10][10];
	
	
	srand(time(0)); 
	for(i=0;i<10;i++)
	{
		printf("individuo %d \n\n",i+1);
		
		printf("Binario: \n");
		for(h=0;h<10;h++)
		{
			arrg[i][h]=rand()%2;
			printf("%d ",arrg[i][h]);
		}
		printf("\n");
		
		printf("Grey: \n");
		for(j=0;j<10;j++)
		{
			
			
			if(j==0)
			{
				arrgrey[i][j]=arrg[i][j];
			}
			else if(j>=1 || j<=8)
			{
				if(arrg[i][j]==arrg[i][j+1])
				{
					arrgrey[i][j]=0;
				}
				else
				{
					arrgrey[i][j]=1;
				}
			}
			else if(j==9)
			{
				if(arrg[i][j]==arrg[i][0])
				{
					arrgrey[i][j]=0;
				}
				else
				{
					arrgrey[i][j]=1;
				}	
			}
			printf("%d ",arrgrey[i][j]);
		}
		printf("\n\n");
	
		
	}				
}

void real()
{
	system("cls");
	int i,j;
	float a=10.0;
	float arrg[10][10];	
	
	srand(time(0)); 
	for(i=0;i<10;i++)
	{
		printf("individuo %d \n\n",i+1);
		for(j=0;j<10;j++)
		{
			arrg[i][j]=((float)rand()/(float)(RAND_MAX))*a;
			printf("%0.2f ",arrg[i][j]);		
		}
		printf("\n\n");	
	}	
}


void entero()
{
	system("cls");
	int i,j;
	int arrg[10][10];
		
	srand(time(0)); 
	for(i=0;i<10;i++)
	{
		printf("individuo %d \n\n",i+1);
		for(j=0;j<10;j++)
		{
			arrg[i][j]=rand()%10;
			printf("%d ",arrg[i][j]);		
		}
		printf("\n\n");	
	}	
}




