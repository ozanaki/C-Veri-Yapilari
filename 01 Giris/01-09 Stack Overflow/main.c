/*************************************************************************
* Proje : Stack Overflow
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici :  Orwell Dev C++ IDE & TDM-GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// recursive fonksiyon kendi kendini cagiriyor
int topla(int a, int b)
{
	int c = topla(a,b);
	if(c<0) return c;
}

int main(int argc, char *argv[])
{
  printf("topla()...\n");
  int top=topla(3,5);
  printf("toplam = %d\n", top);
  return 0;
}
