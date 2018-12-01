#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#include <time.h>

void binario();
void inicializacion(unsigned char arrg[8][4]);
void cruzaPunto(unsigned char arrg[8][4]);
void cruzaDosPuntos(unsigned char arrg[8][4]);
void cruzaUniforme(unsigned char arrg[8][4]);
void cruzaAcentuada(unsigned char arrg[8][4]);

int i,j,n,op;
unsigned char cruza[8][4];

int main()
{
	binario();
}

void binario(int gen)
{
	unsigned char arrg[8][4];
		
	srand(time(0)); 
	for(i=0;i<16;i++)
	{
	//	arrg[i][0]=0;
		for(j=0;j<4;j++)
		{
			arrg[i][j]=rand()%2;
		}
	}	
	
	fflush(stdin);
	inicializacion(arrg);		
}


void inicializacion(unsigned char arrg[8][4])
{	
	int dec[8];
	
	for(i=0;i<8;i++)
	{
		n=0;		
		for(j=0;j<4;j++)
		{			
			if(arrg[i][j]==1)
			{
				n=n+pow(2,3-j);						
			}
		}
		dec[i]=n;
	}
	
	printf("Inicio \n"); //Tabla
	printf("  No || Pob. Ini || X \n\n");
	for(i=0;i<8;i++)
	{
		printf("  %d  ||  ",i);
		for(j=0;j<4;j++)
		{			
			printf("%d",arrg[i][j]);		
		}
		printf("  ||  %d  ",dec[i]);
		printf("\n");
	}		  
	
	fflush(stdin);
	
	printf("1)Cruza de un Punto \n");
	printf("2)Cruza de dos Puntos \n");
	printf("3)Cruza Uniforme \n");
	printf("4)Cruza Acentuada \n");
	
	scanf("%d",&op);
	
	switch(op)
	{
		case 1:
			cruzaPunto(arrg);
			break;
		case 2:
			cruzaDosPuntos(arrg);
			break;
		case 3:
			cruzaUniforme(arrg);
			break;
		case 4:
			cruzaAcentuada(arrg);
			break;
		default:
			main();
	}	
	
	printf("Realizar de Nuevo 1-Si 2-No");
	scanf("%d",&op);
	if(op==1)
	{
		main();
	}
}

void cruzaPunto(unsigned char arrg[8][4])
{	
	int dec[8],Pcruza,Ipcruza[8];		
	
	Pcruza=2;
	for(i=0;i<8;i++)
	{		
		n=0;
		for(j=0;j<4;j++)
		{	
			if(i%2==0)
			{		
				if(j>=Pcruza)
				{
					cruza[i][j]=arrg[i+1][j];
				}
				else
				{
					cruza[i][j]=arrg[i][j];
				}
			}
			else if(i%2==1)
			{
				if(j>=Pcruza)
				{
					cruza[i][j]=arrg[i-1][j];
				}
				else
				{
					cruza[i][j]=arrg[i][j];
				}
			}
		}
		
		if(i%2==1)
		{
			Ipcruza[i]=Pcruza;
			Pcruza=rand()%4;
		}
		else if(i%2==0)
		{
			Ipcruza[i]=Pcruza;
		}
		n=0;
		for(j=0;j<4;j++)
		{			
			if(cruza[i][j]==1)
			{
				n=n+pow(2,3-j);						
			}
		}
		dec[i]=n;	
	}	
	
	printf("Cruza \n"); //Tabla
	printf("  No || Cruza || P.Cruza || Desc || X \n\n");
	for(i=0;i<8;i++)
	{	
		printf("  %d  ||  ",i);
		for(j=0;j<4;j++)
		{			
			printf("%d",arrg[i][j]);		
		}		
		printf("  ||  %d  ||  ",Ipcruza[i]);
		for(j=0;j<4;j++)
		{			
			printf("%d",cruza[i][j]);		
		}
		printf("  ||  %d  ",dec[i]);
		printf("\n");
	}	
}


void cruzaDosPuntos(unsigned char arrg[8][4])
{
	int dec[8],PcruzaA,PcruzaB,IpcruzaA[8],IpcruzaB[8];
	
	PcruzaA=1;
	PcruzaB=3;
	for(i=0;i<8;i++)
	{		
		n=0;
		for(j=0;j<4;j++)
		{	
			if(i%2==0)
			{		
				if(j>=PcruzaA&j<=PcruzaB)
				{
					cruza[i][j]=arrg[i+1][j];
				}
				else
				{
					cruza[i][j]=arrg[i][j];
				}
			}
			else if(i%2==1)
			{
				if(j>=PcruzaA&j<=PcruzaB)
				{
					cruza[i][j]=arrg[i-1][j];
				}
				else
				{
					cruza[i][j]=arrg[i][j];
				}
			}
		}
		
		if(i%2==1)
		{
			IpcruzaA[i]=PcruzaA;
			IpcruzaB[i]=PcruzaB;
			PcruzaA=rand()%2;
			PcruzaB=rand()%2+2;
		}
		else if(i%2==0)
		{
			IpcruzaA[i]=PcruzaA;
			IpcruzaB[i]=PcruzaB;
		}
		
		for(j=0;j<4;j++)
		{			
			if(cruza[i][j]==1)
			{
				n=n+pow(2,3-j);						
			}
		}
		dec[i]=n;	
	}	
	
	printf("Cruza \n"); //Tabla
	printf("  No || Cruza || PCruza A || PCruza B || Desc || X \n\n");
	for(i=0;i<8;i++)
	{	
		printf("  %d  ||  ",i);
		for(j=0;j<4;j++)
		{			
			printf("%d",arrg[i][j]);		
		}		
		printf("  ||  %d  ||  ",IpcruzaA[i]);
		printf("  %d  ||  ",IpcruzaB[i]);
		for(j=0;j<4;j++)
		{			
			printf("%d",cruza[i][j]);		
		}
		printf("  ||  %d  ",dec[i]);
		printf("\n");
	}
}


void cruzaUniforme(unsigned char arrg[8][4])
{
	int dec[8],PcruzaA,PcruzaB,IpcruzaA[8],IpcruzaB[8];
	
	do
	{
		PcruzaA=rand()%4;
		PcruzaB=rand()%4;
	//	printf("A %d,B %d",PcruzaA,PcruzaB);
	}while(PcruzaA==PcruzaB);
	
	for(i=0;i<8;i++)
	{		
		n=0;
		for(j=0;j<4;j++)
		{	
			if(i%2==0)
			{		
				if(j==PcruzaA|j==PcruzaB)
				{		
					cruza[i][j]=arrg[i][j];
				}
				else 
				{
					cruza[i][j]=arrg[i+1][j];
				}
			}
			else if(i%2==1)
			{
				if(j==PcruzaA|j==PcruzaB)
				{		
					cruza[i][j]=arrg[i][j];
				}
				else 
				{
					cruza[i][j]=arrg[i-1][j];
				}
			}
		}
		
		IpcruzaA[i]=PcruzaA;
		IpcruzaB[i]=PcruzaB;
		do
		{
			PcruzaA=rand()%4;
			PcruzaB=rand()%4;
			printf("A %d,B %d",PcruzaA,PcruzaB);
		}while(PcruzaA==PcruzaB);	
		
		for(j=0;j<4;j++)
		{			
			if(cruza[i][j]==1)
			{
				n=n+pow(2,3-j);						
			}
		}
		dec[i]=n;	
	}	
	
	printf("Cruza \n"); //Tabla
	printf("  No || Cruza || PCruza A || PCruza B || Desc || X \n\n");
	for(i=0;i<8;i++)
	{	
		printf("  %d  ||  ",i);
		for(j=0;j<4;j++)
		{			
			printf("%d",arrg[i][j]);		
		}		
		printf("  ||  %d  ||  ",IpcruzaA[i]);
		printf("  %d  ||  ",IpcruzaB[i]);
		for(j=0;j<4;j++)
		{			
			printf("%d",cruza[i][j]);		
		}
		printf("  ||  %d  ",dec[i]);
		printf("\n");
	}
}


void cruzaAcentuada(unsigned char arrg[8][4])
{
		int dec[8],PcruzaA,PcruzaB,IpcruzaA[8],IpcruzaB[8];
	
	PcruzaA=1;
	PcruzaB=3;
	for(i=0;i<8;i++)
	{		
		n=0;
		for(j=0;j<4;j++)
		{	
			if(i%2==0)
			{		
				if(j>=PcruzaA&j<=PcruzaB)
				{
					cruza[i][j]=arrg[i+1][j];
				}
				else
				{
					cruza[i][j]=arrg[i][j];
				}
			}
			else if(i%2==1)
			{
				if(j>=PcruzaA&j<=PcruzaB)
				{
					cruza[i][j]=arrg[i-1][j];
				}
				else
				{
					cruza[i][j]=arrg[i][j];
				}
			}
		}
		
		if(i%2==1)
		{
			IpcruzaA[i]=PcruzaA;
			IpcruzaB[i]=PcruzaB;
			PcruzaA=rand()%2;
			PcruzaB=rand()%2+2;
		}
		else if(i%2==0)
		{
			IpcruzaA[i]=PcruzaA;
			IpcruzaB[i]=PcruzaB;
		}
		
		for(j=0;j<4;j++)
		{			
			if(cruza[i][j]==1)
			{
				n=n+pow(2,3-j);						
			}
		}
		dec[i]=n;	
	}	
	
	printf("Cruza \n"); //Tabla
	printf("  No || Cruza || Desc || X \n\n");
	for(i=0;i<8;i++)
	{	
		printf("  %d  ||  ",i);
		for(j=0;j<4;j++)
		{			
			printf("%d",arrg[i][j]);		
		}
		printf("  ||  ");		
		for(j=0;j<4;j++)
		{			
			printf("%d",cruza[i][j]);		
		}
		printf("  ||  %d  ",dec[i]);
		printf("\n");
	}
}











