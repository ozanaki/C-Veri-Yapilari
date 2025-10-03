/*************************************************************************
* Proje : Pointer - Karakter say
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int uzunluk(const char *str)
{
	int len=0;
	while(*str++) len++;
	return len-1;
}

int main(int argc, char* argv[])
{
	char cumle[255];
	printf("Bir cumle giriniz: ");
	fgets(cumle, 255, stdin);

	int len = uzunluk(cumle);

	printf("Cumledeki karakter sayisi: %d\n", len);

	return 0;
}

