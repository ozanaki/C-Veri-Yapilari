/*************************************************************************
* Proje : Recursive (Özyinelemeli) Fonksiyonlar
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell DevC++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

int obeb(int a, int b)
{
	if(a==b)
		return a;
	else if(a>b)
		return obeb(a-b,b);
	else if(b>a)
		return obeb(a,b-a);
}

int main(int argc, char *argv[])
{
	int a,b,cevap;
	printf("A : ");	scanf("%d", &a);
	printf("B : ");	scanf("%d", &b);

	cevap = obeb(a,b);

	printf("OBEB(%d,%d) = %d\n", a,b,cevap);

	return 0;
}
