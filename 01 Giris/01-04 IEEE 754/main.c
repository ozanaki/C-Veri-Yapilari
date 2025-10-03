/*************************************************************************
* Proje : IEEE 754 Standarti (float, double)
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ IDE & TDM-GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

union {
	float f;
	unsigned long u;
} fu;

void print_bit(int bit, int sayi)
{
	int i;
	for(i=bit-1; i>=0; i--)
	{
		if(sayi & (1<<i)) printf("1");
		else printf("0");
		if(i%4==0) printf(" ");
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	float f;
	
	printf("\nfloat tipinde sayi giriniz:");
	scanf("%f", &fu.f);
    
  int negatif = !!(fu.u & 0x80000000);
	int us = (fu.u & 0x7f800000) >> 23;
	int carpan = (fu.u & 0x007FFFFF);

	printf("negatif: %d\n", negatif);
	printf("us: %d -> ", us);
	print_bit(8,us);
	printf("carpan: %d -> ", carpan);
	print_bit(23,carpan);
	
  return 0;
}
