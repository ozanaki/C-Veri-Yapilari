/*************************************************************************
* Proje : Sezar Kripto
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void kriptola(char *str, int otele)
{
	while(*str)
	{
		*str+=otele;
		str++;
	}
}

void kripto_coz(char *str, int otele)
{
	while(*str)
	{
		*str-=otele;
		str++;
	}
}

int main(int argc, char* argv[])
{
	char cumle[255];
	int anahtar;

	printf("Bir cumle giriniz: ");
	fgets(cumle,255,stdin);

	printf("anahtar sayiyi giriniz: ");
	scanf("%d", &anahtar);

	kriptola(cumle,anahtar);
	printf("Kriptolu cumle: %s\n", cumle);

	kripto_coz(cumle, anahtar);
	printf("Cozulmus cumle: %s\n", cumle);

	return 0;
}

