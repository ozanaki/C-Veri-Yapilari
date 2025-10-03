/*************************************************************************
* Proje : char queue
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "mycharqueue.h"

int main(int argc, char *argv[])
{
  char c;
	printf("Bir cumle giriniz: ");
	for(;;)
	{
		if((c=getch())=='\r') break;
		printf("%c",c);
		add(c);	
	}
	
	printf("\nsize()=%d, Girilen cumle: ",getsize());
	
	while(!empty()) printf("%c", get());
	
	printf("\n");

  return 0;
}
