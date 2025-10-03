/*************************************************************************
* Proje : Pointer Tanimlanmasi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int a,b;
int *iptr;

int main(int argc, char* argv[])
{
	a=3; b=5;

	iptr = &a;
	*iptr = *iptr*10;
	
	iptr = &b;
	*iptr = *iptr*10;

	printf("a=%d  b=%d\n",a,b);

	printf("&a=%d  &b=%d\n",&a,&b);

	printf("iptr= %d\n",iptr);

	return 0;
}

