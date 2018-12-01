#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define CHAR_BITS 4

void individuo();
void bin(unsigned char *num);
void generacion(unsigned char *ind);

int main()
{
	individuo();
}

void individuo()
{
	system("cls");
	int i,j,m,n;
	int a;
	unsigned char ind[32][5];

	srand(time(0));	
	for(i=0;i<32;i++)
	{
		printf("individuo %d \n\n",i+1);	
		ind[i]=rand()%17;
		printf("%d",ind[i]);				
		printf("\n\n");	
	}	
	bin(ind);
}

void bin(unsigned char num[32][5])
{
	int sup = CHAR_BITS;
    
	for(int i=0; i<32;i++){
	
		while(sup >= 0)
   		 {
        if(num[i] & 31 << sup)
            printf("1");
        else
            printf("0");
        sup--;
    }
    printf("\n");
}
    
}


void generacion(unsigned char *ind)
{

}







