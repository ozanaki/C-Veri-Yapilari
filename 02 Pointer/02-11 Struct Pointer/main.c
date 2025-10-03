/*************************************************************************
* Proje : Pointer - Struct Pointer
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

typedef struct {
	char adsoyad[80];
	char tcno[11];
	float puan;
} kayit_t;

int i;
kayit_t *pkayit;
kayit_t	kayitlar[LEN];

int main(int argc, char* argv[])
{

	printf("%d Adet kayit giriniz:\n", LEN);

	for(i=0; i<LEN; i++)
	{
		printf("\n%d. Kayit\n",i+1);
		fflush(stdin);
		printf("Ad Soyad : ");
		fgets(kayitlar[i].adsoyad,sizeof(kayitlar[i].adsoyad),stdin);
		printf("TC No    : ");
		scanf("%s",kayitlar[i].tcno);
		printf("Puan     : ");
		scanf("%f", &kayitlar[i].puan);
	}
	printf("\n\n");

	pkayit = kayitlar;

	for(i=0; i<LEN; i++)
	{
		printf("%d --> %s %s %3.2f \n",i, pkayit->tcno, pkayit->adsoyad, pkayit->puan);
		pkayit++;
	}

	return 0;
}

