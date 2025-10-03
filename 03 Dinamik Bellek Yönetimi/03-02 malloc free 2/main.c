/*************************************************************************
* Proje : Dinamik bellek yonetimi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int *p,*q;
int i,size;

int main(int argc, char *argv[])
{
  printf("Kac elemanli dizi istiyorsun: ");
  scanf("%d", &size);
  
  p = (int*)malloc(sizeof(int)*size);
  
  if(p==NULL)
  {
		printf("Bu kadar bellek yok!\n");	
		return 0;
	}
  
  q=p;
	for(i=0; i<size; i++)
	{
		*q++=rand()%1000;	
	}  
	
	q=p;  
	for(i=0; i<size; i++)
	{
		printf("%4u ",*q++);	
	}  

  free(p);
  
  return 0;
}
