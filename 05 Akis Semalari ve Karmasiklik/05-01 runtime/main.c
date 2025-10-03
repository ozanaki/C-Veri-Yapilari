/*************************************************************************
* Proje : Calisma zamaninin olculmesi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A_SATIR 1000
#define A_SUTUN 1000

#define B_SATIR 1000
#define B_SUTUN 1000

#if A_SUTUN == B_SATIR
#define C_SATIR A_SATIR
#define C_SUTUN B_SUTUN
#else
#error "Carpim icin A Matrisi sutun sayisi ile B Matrisi satir sayisi esit olmali!"
#endif

int i,j,k;
float A[A_SATIR][A_SUTUN];
float B[B_SATIR][B_SUTUN];
float C[C_SATIR][C_SUTUN];

time_t begin,end;
clock_t sure;

int main(int argc, char* argv[])
{
	printf("A matrisi rasgele sayilarla olusturuluyor...\n");
	for(i=0; i<A_SATIR; i++)
	{
		for(j=0; j<A_SUTUN; j++)
		{
			A[i][j] = rand() / 100.0;
			//printf("A[%d,%d] = %0.2f\n",i,j,A[i][j]);
		}
	}

	printf("B matrisi rasgele sayilarla olusturuluyor...\n");
	for(i=0; i<B_SATIR; i++)
	{
		for(j=0; j<B_SUTUN; j++)
		{
			B[i][j] = rand() / 100.0;
			//printf("B[%d,%d] = %0.2f\n",i,j,B[i][j]);
		}

	}

	printf("Matrisler carpiliyor...");
	sure=clock();
	time(&begin);
	// carpim matrisini sifirla
	for(i=0; i<C_SATIR; i++)
	{
		for(j=0; j<C_SUTUN; j++)
		{
			C[i][j] = 0;
		}
	}

	// Matrisleri Carp
	for(i=0; i<A_SATIR; i++)
	{
		for(j=0; j<B_SUTUN; j++)
		{
			for(k=0; k<A_SUTUN; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	sure=clock()-sure;
	time(&end);
	printf(" Bitti.\n");

	// Ekrana Yaz
	if(C_SATIR<5 && C_SUTUN<5)
	{
		printf("C Carpim Matrisi:\n");
		printf("-------------------------\n");
		for(i=0; i<C_SATIR; i++)
		{
			printf("\n| ");
			for(j=0; j<C_SUTUN; j++)
			{
				printf("%0.2f\t",C[i][j]);
			}
			printf(" |");
		}
		printf("\n");
	}
	else
	{
		printf("Bu matris ekrana basilamayacak kadar buyuk.\n");
	}
	printf("difftime() --> Carpma islemi toplam %.3f saniye surdu.\n",difftime(end,begin));
	printf("clock() --> Carpma islemi toplam %.3f saniye surdu.\n",(double)sure/CLOCKS_PER_SEC);
	return 0;
}

