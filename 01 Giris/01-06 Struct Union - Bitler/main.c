/*************************************************************************
* Proje : Structure & Union
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici :  Orwell Dev C++ IDE & TDM-GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

union {
	unsigned char butun;
	struct {
		unsigned b0:1;
		unsigned b1:1;
		unsigned b2:1;
		unsigned b3:1;
		unsigned b4:1;
		unsigned b5:1;
		unsigned b6:1;
		unsigned b7:1;
	} bit;
} sayi;

int main(int argc, char *argv[])
{
  unsigned char kac,deger;
  unsigned char s;
  
  printf("0...255 arasinda bir sayi giriniz:");
  scanf("%d", &s);
    
  sayi.butun = s;
  
  printf("sayi %d : %d %d %d %d %d %d %d %d \n", 
		sayi.butun,
		sayi.bit.b7,sayi.bit.b6,sayi.bit.b5,sayi.bit.b4,
		sayi.bit.b3,sayi.bit.b2,sayi.bit.b1,sayi.bit.b0);
	
  return 0;
}
