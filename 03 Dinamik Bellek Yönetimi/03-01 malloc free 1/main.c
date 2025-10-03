/*************************************************************************
* Proje : Dinamik bellek yonetimi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int *pa,*pb,*pc;

int main(int argc, char *argv[])
{
	pa = (int*)malloc(sizeof(int));
	pb = (int*)malloc(sizeof(int));
	pc = (int*)malloc(sizeof(int));
	
  if(pa==NULL | pb==NULL | pc==NULL)
  {
		printf("Bellek yetersiz!\n");
	  system("PAUSE");	
		return 0;
	}

  printf("Bir sayi giriniz: ");
  scanf("%d", pa);
  
  printf("Bir sayi giriniz: ");
  scanf("%d", pb);
  
  *pc = *pa + *pb;

	printf("Sayilarin toplami: %d\n", *pc);  
    
  free(pa);
  free(pb);
  free(pc);
      
  return 0;
}
