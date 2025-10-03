/*************************************************************************
* Proje : binary tree
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

node_t *root=NULL;
void listele();

int main(int argc, char *argv[])
{
	int i=0,sayi;
	node_t *tmp=NULL;
		
	printf("Sonlandirmak icin negatif sayi giriniz.\n");  
	for(;;)
	{
		printf("%d. elemani giriniz: ",i++);
		scanf("%d", &sayi);
		if(sayi<0) break;
		root = add(root, sayi);
	}

	list(root,0,0);
		
  return 0;
}

