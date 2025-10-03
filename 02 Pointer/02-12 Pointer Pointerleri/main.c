/*************************************************************************
* Proje : Pointer - Pointer Pointerlari
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int i;
int *p;
int **q;
int ***r;

int main(int argc, char* argv[])
{
	i=100;
	p=&i;
	q=&p;
	r=&q;

	printf("i = %u\n\n", i);
	printf("p = %u\n", p);
	printf("*p = %u\n\n", *p);
	printf("q = %u\n", q);
	printf("*q = %u\n", *q);
	printf("**q = %u\n\n", **q);
	printf("r = %u\n", r);	
	printf("*r = %u\n", *r);
	printf("**r = %u\n", **r);
	printf("***r = %u\n\n", ***r);

	return 0;
}

