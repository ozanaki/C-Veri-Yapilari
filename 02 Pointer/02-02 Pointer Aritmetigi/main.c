/*************************************************************************
* Proje : Pointer Aritmetigi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

char *cp = NULL;
short *sp = NULL;
int *ip = NULL;
long *lp = NULL;
float *fp = NULL;
double *dp = NULL;

int main(int argc, char* argv[])
{
	printf("cp = %u\n", cp);
	printf("sp = %u\n", sp);
	printf("ip = %u\n", ip);
	printf("lp = %u\n", lp);
	printf("fp = %u\n", fp);
	printf("dp = %u\n", dp);

	printf("-----------------\n");
	cp++; sp++; ip++; lp++; fp++; dp++;

	printf("cp = %u\n", cp);
	printf("sp = %u\n", sp);
	printf("ip = %u\n", ip);
	printf("lp = %u\n", lp);
	printf("fp = %u\n", fp);
	printf("dp = %u\n", dp);

	return 0;
}

