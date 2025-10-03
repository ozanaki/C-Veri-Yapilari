/*************************************************************************
* Proje : Structure & Union
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ IDE & TDM-GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

union {
	float f;
	struct {
		unsigned carpan:23;
		unsigned us:8;
		unsigned isaret:1;
	} bit;
} ortak;

int main(int argc, char *argv[])
{
  
  float f;
  
  printf("float bir sayi giriniz:");
  scanf("%f", &f);
    
  ortak.f = f;
  
  printf("isaret: %d\n", ortak.bit.isaret);
  printf("us: %d\n", ortak.bit.us);
  printf("carpan: %d\n", ortak.bit.carpan);
  	
  return 0;
}
