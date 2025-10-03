/*************************************************************************
* Proje : Arama algoritmalari - dosyada kelime arama
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE* dosya;
	size_t size;
  char dosyaadi[255];
  char kelime[80];
  char *metin,*p,*q,*t;
  int bulundu,indis;
  
  printf("aranacak dosya adini giriniz:");
  scanf("%s",dosyaadi);
  
  dosya=fopen(dosyaadi,"r");
  if(dosya==NULL)
  {
		printf("Dosya bulunamadi/acilamadi.\n");
		system("pause");
		return 0;	
	}
  
  fseek(dosya, 0L, SEEK_END);
	size = ftell(dosya);
  metin=(char*)malloc(size);
  if(metin==NULL)
  {
		printf("Yeterli bellek yok!\n");
		fclose(dosya);
		system("pause");
		return 0;	
	}
  
  rewind(dosya);
  fread(metin,size,1,dosya);
  
	printf("Aranan kelime:");
  scanf("%s",kelime);
  
  p=metin;
  q=kelime;
  t=p;
  indis=0;
  bulundu=0;
  while(*p!='\0')
  {
			if(*p==*q)
			{
				q++;
				if(*q=='\0')
				{
					printf("%d. indiste: ",indis);
					while(*t==' ') t++;
					while(*t!='\0' && *t!=' ')
					{
						putch(*t);
						t++;
					}
					printf("\n");
					bulundu++;
				}	
			}
			else
			{
				q=kelime;
				t=p;
				indis++;
			}
			p++;
	}
  
	printf("Aranan %s kelimesinden %d adet bulundu.\n",kelime,bulundu);

	free(metin);
  fclose(dosya);
    
  return 0;
}

