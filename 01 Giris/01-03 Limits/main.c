/*************************************************************************
* Proje : Veri Tiplerinin Limitleri
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ IDE & TDM-GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
  printf("CHAR_MIN: %d\n", CHAR_MIN);
  printf("CHAR_MAX: %d\n", CHAR_MAX);
  printf("UCHAR_MAX: %u\n", UCHAR_MAX);
  
  printf("\n");
  
  printf("SHRT_MIN: %d\n", SHRT_MIN);
  printf("SHRT_MAX: %d\n", SHRT_MAX);
  printf("USHRT_MAX: %u\n", USHRT_MAX);

  printf("\n");
  
  printf("INT_MIN: %d\n", INT_MIN);
  printf("INT_MAX: %d\n", INT_MAX);
  printf("UINT_MAX: %u\n", UINT_MAX);
  
  printf("\n");

  printf("LONG_MIN: %d\n", LONG_MIN);
  printf("LONG_MAX: %d\n", LONG_MAX);
  printf("ULONG_MAX: %u\n", ULONG_MAX);
  
  printf("\n");

  return 0;
}
