/*************************************************************************
* Proje : Dinamik bellek yonetimi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int sayi,n;
int adet=0;
int *sayilar=NULL;
int *temp;

int main(int argc, char *argv[])
{

  do {
     printf ("istedigin kadar sayi gir (0 ile bitir): ");
     scanf ("%d", &sayi);
     adet++;

     temp=(int*)realloc(sayilar, adet*sizeof(int));

     if (temp!=NULL) {
       sayilar=temp;
       sayilar[adet-1]=sayi;
     }
     else {
       free(sayilar);
       puts("Bellek yetersiz!\n");
       exit(1);
     }
  } while (sayi!=0);

  printf ("Girilen sayilar: ");
  for(n=0; n<adet; n++) printf("%d ",sayilar[n]);

  free(sayilar);
  
  return 0;
}
