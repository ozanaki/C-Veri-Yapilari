/*************************************************************************
* Proje : Pointer - Alfabe Histogram
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define CUMLE_LEN 255
#define HIST_LEN ('Z'-'A'+1)

unsigned char hist[HIST_LEN]; 

void buyuk_harf(char *str)
{
	while(*str)
	{
		if((*str>='a') && (*str<='z')) *str-='a'-'A';
		str++;
	}
}

void harf_say(const char* str)
{
	while(*str) 
	{
		if((*str>='A') && (*str<='Z')) hist[*str-'A']++;
		str++;
	}
}

void hist_goster(void)
{
	int i,j;
	printf("\n-------------------\n");
	for(i=0; i<HIST_LEN; i++)
	{
		if(hist[i]>0)
		{
			printf("%c: %d\t", i+'A', hist[i]);
			for(j=0; j<hist[i]; j++) printf("#");
			printf("\n");
		}
	}
	printf("---------------------\n");
}

int main(int argc, char* argv[])
{
	char cumle[CUMLE_LEN];
	printf("Bir cumle giriniz: ");
	fgets(cumle,255,stdin);

	buyuk_harf(cumle);
	harf_say(cumle);
	hist_goster();

	return 0;
}

