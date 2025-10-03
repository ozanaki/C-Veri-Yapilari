/*************************************************************************
* Proje : Pointer - Fonksiyona parametre olarak gecilmesi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void takas(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int x, y;

int main(int argc, char* argv[])
{
	x = 25;
	y = 63;

	printf("x = %d, y = %d\n", x, y);

	takas(&x, &y);

	printf("x = %d, y = %d\n", x, y);

	return 0;
}

