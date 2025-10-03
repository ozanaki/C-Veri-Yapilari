/*************************************************************************
* Proje : Arama algoritmalari - kelime arama
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char cumle[255];
  char kelime[80];
  char *p,*q;
  int bulundu,indis;
  
  printf("Bir metin giriniz:");
  gets(cumle);
  
	printf("Aranan kelime:");
	fflush(stdin);
  scanf("%s",kelime);
  
  p=cumle;
  q=kelime;
  indis=0;
  bulundu=0;
  while(*p!='\0')
  {
			if(*p==*q)
			{
				q++;
				if(*q=='\0')
				{
					bulundu=1;
					break;
				}	
			}
			else
			{
				q=kelime;
				indis++;
			}
			p++;
	}
  
  if(bulundu)
		printf("Aranan %s kelimesi %d indisinde bulundu.\n",kelime,indis);
	else
		printf("Aranan %s kelimesi bulunamadi.\n",kelime);
  
   return 0;
}

