
/*************************************************************************
* Proje : Veri Tiplerinin Bellekte Kapladigi Alan
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ IDE & TDM-GCC 4.8.1 Compiler
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
	char sayi, bit;
	
	printf("Bir tam sayi giriniz: ");
	scanf("%d",&sayi);
  
  bit = 8*sizeof(sayi);
  
  printf("\n%d sayisinin bitleri : ",sayi);

  print_bit(bit, sayi);
  
  return 0;
}
