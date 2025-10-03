/*************************************************************************
* Proje : dinamik stack
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "dynamicstack.h"

int main(int argc, char *argv[])
{
	int i;
    printf("Sonlandirmak icin negatif sayi giriniz.\n");
	for(;;)
	{
		printf("%d. sayi: ",getsize());
		scanf("%d",&i);
		if(i<0) break; 
		push(i);
	}
	
	printf("\nGirilen sayilar: ");
	while(!empty()) printf("%d ",pop());
	
	printf("\n");
	
  return 0;
}
