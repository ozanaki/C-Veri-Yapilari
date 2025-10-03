/*************************************************************************
* Proje : Pointer - Fonksiyona parametre olarak gecilmesi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void buyuk_harf(char *str)
{
	while(*str)
	{
		if((*str>='a') && (*str<='z')) *str-='a'-'A';
		str++;
	}
}

int main(int argc, char* argv[])
{
	char adsoyad[80];
	printf("Ad Soyad giriniz: ");
	fgets(adsoyad,80,stdin);

	buyuk_harf(adsoyad);

	printf("buyuk harf: %s", adsoyad);

	return 0;
}

