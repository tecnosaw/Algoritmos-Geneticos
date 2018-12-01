// Ultimo dia de entrega de practicas, 30 nov

#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#include <time.h>

void binario(int gen);
void inicializacion(int gen,unsigned char arrg[16][4]);
void seleccionRanking(int gen, unsigned char arrg[16][4],float *Prob,int *dec,int *apt);
void seleccionRuleta(int gen, unsigned char rank[16][4],float *Prob,int *dec,int *apt);
void cruza(int gen,unsigned char sel[16][4]);
void mutacion(int gen,unsigned char cruza[16][4]);
void grafica(float *Max, float *Min);

float Max[100], Min[100];
int i,j,n,x,y;

int main()
{
	int gen=0;
	
	printf("Generacion %d \n",gen+1);
	binario(gen);
}

void binario(int gen)
{
	unsigned char arrg[16][4];
		
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
	inicializacion(gen,arrg);		
}


void inicializacion(int gen,unsigned char arrg[16][4])
{	
	int dec[16],apt[16],sumApt=0;
	float Prob[16],sumProb;
	
	Prob[0]=0.0;
	for(i=0;i<16;i++)
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
		apt[i]=fabs(dec[i]-5)/(2+sin(n*3.14159/180));
		sumApt=sumApt+apt[i];		
	}
	sumProb=0.0;
	for(i=0;i<16;i++)
	{
		Prob[i]=((float)apt[i])/((float)sumApt);
		sumProb=sumProb+Prob[i];
	}
	
/*	printf("Inicio \n"); //Tabla
	printf("  No || Pob. Ini || X || Aptitud X || Prob \n\n");
	for(i=0;i<16;i++)
	{
		printf("  %d  ||  ",i);
		for(j=0;j<4;j++)
		{			
			printf("%d",arrg[i][j]);		
		}
		printf("  ||  %d  ||  %d  ||",dec[i],apt[i]);
		printf("  %0.3f  ",Prob[i]);
		printf("\n");
	}	
	printf("\n Sumatoria Aptitud: %d", sumApt);
	printf("\n Sumatoria Probabilidad: %.2f \n\n",sumProb);	  */
	
	fflush(stdin);
	seleccionRanking(gen,arrg,Prob,dec,apt);
}


void seleccionRanking(int gen,unsigned char arrg[16][4], float *Prob, int *dec, int *apt)
{
	int i,j,temp,k[16];
	unsigned char rank[16][4];
	
	
	for(i=15;i>0;i--)
	{
		n=0;
		for(j=0;j<i;j++)
		{
			if(apt[j]>=apt[j+1])
			{
				temp=apt[j];
				apt[j]=apt[j+1];
				apt[j+1]=temp;
				k[15-i]=j;
			}
			else if(apt[j]>apt[j+1])
			{
				n++;
			}
		}
		k[i]=0;
	}
/*	for(i=0;i<16;i++)
	{
		printf("%d = %d \n",i,apt[i]);
	}
	printf("\n");
	for(i=0;i<16;i++)
	{
		printf("%d\n",k[i]);
	}*/

	
/*	for(i=0;i<16;i++)
	{
		printf("%d = ",i);
		for(j=0;j<4;j++)
		{
			printf("%d",rank[i][j]);
		}
		printf("\n");
	}*/
	seleccionRuleta(gen,arrg,Prob,dec,apt);
}


void seleccionRuleta(int gen,unsigned char arrg[16][4], float *Prob, int *dec, int *apt)
{
	//RULETA
	unsigned char sel[16][4];
	int selDec[16],selApt[16];
	float r,sum;

	for(i=0;i<16;i++)
	{
		n=0;
		sum=0.0;

		r=((float)rand()/(float)(RAND_MAX))*1.0;
	//	printf("\n\n%d\n\n",i);
	//	printf("r= %.3f \n",r);

		do
		{
	//		printf("\n %d sum %.3f +",n,sum);
			sum=sum+Prob[n];
	//		printf("\n %.3f = %.3f  \n",Prob[n],sum);
			n++;
		}while(sum<=r);
		n--;
		//printf("\n\n%d\n\n",n);
		for(j=0;j<4;j++)
		{
			sel[i][j]=arrg[n][j];
		//	printf("%d",sel[i][j]);
		}
		selDec[i]=dec[n];
		selApt[i]=apt[n];
	}


	fflush(stdin);
	cruza(gen,sel);
}

void cruza(int gen,unsigned char sel[16][4])
{
	unsigned char cruza[16][4];
	int dec[16],apt[16],sumApt=0,Pcru[16],Pcruza;
	
	Pcruza=2;
	for(i=0;i<16;i++)
	{		
		n=0;
		for(j=0;j<4;j++)
		{	
			if(i%2==0)
			{		
				if(j>=Pcruza)
				{
					cruza[i][j]=sel[i+1][j];
				}
				else
				{
					cruza[i][j]=sel[i][j];
				}
			}
			if(i%2==1)
			{
				if(j>=Pcruza)
				{
					cruza[i][j]=sel[i-1][j];
				}
				else
				{
					cruza[i][j]=sel[i][j];
				}
			}
		}
		Pcru[i]=Pcruza;	
		if(i%2==1)
		{
			Pcruza=rand()%3+1;
		}
		for(j=0;j<4;j++)
		{			
			if(cruza[i][j]==1)
			{
				n=n+pow(2,3-j);						
			}
		}
		dec[i]=n;	
		apt[i]=fabs(dec[i]-5)/(2+sin(n*3.14159/180));
		sumApt=sumApt+apt[i];
	}	
	
/*	printf("Cruza \n"); //Tabla
	printf("  No || Cruza || P.Cruza || Descendencia || X || Aptitud X  \n\n");
	for(i=0;i<16;i++)
	{	
		printf("  %d  ||  ",i);
		for(j=0;j<4;j++)
		{			
			printf("%d",sel[i][j]);		
		}		
		printf("  ||  %d  ||  ",Pcru[i]);
		for(j=0;j<4;j++)
		{			
			printf("%d",cruza[i][j]);		
		}
		printf("  ||  %d  ",dec[i]);
		printf("||  %d  ",apt[i]);
		printf("\n");
	}	
	printf("Sumatoria Aptitud: %d",sumApt); */
	
	fflush(stdin);
	mutacion(gen,cruza);
}

void mutacion(int gen,unsigned char cruza[16][4])
{
	unsigned char mutacion[16][4];	
	float prob[16];
	int dec[16],apt[16],sumApt=0;
	
	for(i=0;i<16;i++)
	{
		for(j=0;j<4;j++)
		{
			mutacion[i][j]=cruza[i][j];
		}
	}
	
	for(i=0;i<3;i++)
	{
		x=rand()%16;
		y=rand()%4;
		if(mutacion[x][y]==1)
		{
		    i--;	
		}
		else
		{
			mutacion[x][y]=1;
		}
		//	printf("\n %d",j);//checa si esta bien el if	
	}	
	
	for(i=0;i<16;i++)
	{
		n=0;
		for(j=0;j<4;j++)
		{			
			if(mutacion[i][j]==1)
			{
				n=n+pow(2,3-j);						
			}
		}	
		dec[i]=n;
		apt[i]=fabs(dec[i]-5)/(2+sin(n*3.14159/180));
		sumApt=sumApt+apt[i];
	}
	for(i=0;i<16;i++)
	{
		prob[i]=((float)apt[i])/((float)sumApt);
	}
	
/*	printf("\n Mutacion \n"); //Tabla
	printf("\n\n  No || Desc || Mutacion || X || Aptitud X || Prob  \n\n");	
	for(i=0;i<16;i++){			
		printf("  %d || ",i);
		for(j=0;j<4;j++)
		{
			printf("%d",cruza[i][j]);
		}
		printf(" || ");
		for(j=0;j<4;j++)
		{
			printf("%d",mutacion[i][j]);
		}
		printf("||  %d  ",dec[i]);
		printf("||  %d  ",apt[i]);
		
		printf("||  %0.3f  ",prob[i]);
		printf("\n");
	}		
	printf("%d\n",sumApt);  */
	
	float tmax=0,tmin=0;
	tmax=prob[0];
	tmin=prob[0];
	
	for(i=0;i<16;i++)
	{
		if(prob[i]>tmax)
		{
			tmax=prob[i];
		}
		if(prob[i]<tmin)
		{
			tmin=prob[i];
		}
	}
	
	Max[gen]=tmax;
	Min[gen]=tmin;
	printf("maximo %0.3f\n",Max[gen]);
	printf("minimo %0.3f\n",Min[gen]);
	gen++;
	if(gen<5)
	{
		printf("\n Generacion %d \n",gen+1);
		inicializacion(gen,mutacion);
	}
	else if(gen==5)
	{
		fflush(stdin);
		grafica(Max,Min);
	}
}

void grafica(float *Max, float *Min)
{
	printf("\nMax\n");
	for(i=0; i<5;i++)
	{
		printf("%d=%0.3f \n",i+1,Max[i]);	
	}
	printf("Min\n");
	for(i=0; i<5;i++)
	{	
		printf("%d=%0.3f \n",i+1,Min[i]);	
	}
}



