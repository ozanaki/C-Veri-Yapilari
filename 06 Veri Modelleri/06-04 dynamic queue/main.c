/*************************************************************************
* Proje : dynamic queue
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "dynamicqueue.h"

int main(int argc, char *argv[])
{
  int i;
  printf("Sonlandirmak icin negatif sayi giriniz.\n");
	for(;;)
	{
		printf("%d. sayi: ",getsize());
		scanf("%d",&i);
		if(i<0) break; 
		add(i);
	}
	
	printf("\nGirilen sayilar: ");
	while(!empty()) printf("%d ",get());
	
	printf("\n");
  
  return 0;
}

