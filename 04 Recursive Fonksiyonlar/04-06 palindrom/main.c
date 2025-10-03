/*************************************************************************
* Proje : Recursive (Özyinelemeli) Fonksiyonlar
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell DevC++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrommu(char *str, int len)
{
	if(len<2) return 1;
	return (str[0]==str[len-1]) && palindrommu(&str[1],len-2);
}

int main(int argc, char *argv[])
{
	char cumle[80];
	printf("bir cumle giriniz:");
	
	fgets(cumle,80,stdin);
	
	if(palindrommu(cumle,strlen(cumle)-1)) // -1 ile cumle sonuna eklenen enter karakteri devre disi birakiliyor
		printf("\nBu cumle palindromdur.\n");
	else 
 		printf("\nBu cumle palindrom degildir.\n");
 		
  return 0;
}
