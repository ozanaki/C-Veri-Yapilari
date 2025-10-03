/*************************************************************************
* Proje : little-endian, big-endian
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ IDE & TDM-GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	
  unsigned int test = 0x12345678; // 32 bit
 
	unsigned char *c = (unsigned char*)(&test);
	
	printf("Data: %X\n", test);
	
	for(i=0; i<sizeof(test); i++)
	{
		printf("%p -> %0X\n", c+i, c[i]);
	}
	
	printf("\nSistem: ");
	if (*c == 0x78)
	{
	  printf("little-endian\n");
	}
	else
	{
	  printf("big-endian\n");
	}
		
  return 0;
}
