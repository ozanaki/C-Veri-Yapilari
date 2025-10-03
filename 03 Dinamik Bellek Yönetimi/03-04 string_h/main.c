/*************************************************************************
* Proje : Dinamik bellek yonetimi
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cumle[80];
char kelime[80];
char *temp;
int len,i;

int main(int argc, char *argv[])
{
	 printf("Bir cumle giriniz: ");
	 fgets(cumle,80,stdin);

	 printf("Bir kelime giriniz: ");
	 scanf("%s",kelime);
	 
	 len=strlen(cumle);
	 printf("Cumle uzunlugu %d karakter.\n",len);
	 
	 temp=strstr(cumle,kelime);
	 if(temp==NULL)
	 {
			printf("%s kelimesi cumle icinde bulunamadi.\n",kelime);
			return 0;
	 }
	 printf("%s kelimesi cumle icinde bulundu.\n",kelime);
	
	 memset(temp,'*',strlen(kelime));
	 printf("Sansurlu cumle: %s\n", cumle);
	 
	 strcpy(temp,kelime);
	 //memcpy(temp,kelime,strlen(kelime));
	 //memmove(temp,kelime,strlen(kelime));
	 
	 for(i=0;i<len; i++) printf("%c (%d)\n", cumle[i],cumle[i]);
	 //printf("Kelime yerine kopyalandi: %s\n",cumle);

  return 0;
}
