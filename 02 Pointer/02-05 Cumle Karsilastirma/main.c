/*************************************************************************
* Proje : Pointer
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int karsilastir(const char *str1, const char *str2)
{
	int fark=0;
	while(*str1 && *str2 && fark==0)
	{
		fark=*str2-*str1;
		str1++; str2++;
	}
	return fark;
}

int main(int argc, char* argv[])
{
	char cumle1[255],cumle2[255];

	printf("1. Cumleyi girin: ");
	fgets(cumle1,255,stdin);

	printf("2. Cumleyi girin: ");
	fgets(cumle2,255,stdin);

	int sonuc = karsilastir(cumle1, cumle2);

	if(sonuc>0) 
	{
		printf("1. cumle, 2. cumleden ONCE gelir.\n");
	}
	else if(sonuc<0)
	{
		printf("1. cumle, 2. cumleden SONRA gelir.\n");
	}
	else
	{
		printf("Her iki cumle esittir.\n");
	}

	return 0;
}

