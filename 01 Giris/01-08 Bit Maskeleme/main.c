/*************************************************************************
* Proje : Bit Maskeleme - Reverse Bits
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici :  Orwell Dev C++ IDE & TDM-GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  unsigned char i, sayi, yeni=0;
  
  printf("Bir sayi giriniz (0..255):");
  scanf("%u", &sayi);
    
  int bitsay = 8*sizeof(sayi);
  
    // bu kod ne yapiyor ??
	for(i=0; i<bitsay; i++)
	{
		if(sayi & (1<<i)) yeni |= 1 << (bitsay-i-1);	
	}
	
	printf("yeni= %u\n", yeni);
	
  return 0;
}
