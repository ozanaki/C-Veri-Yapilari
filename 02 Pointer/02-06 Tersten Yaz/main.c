/*************************************************************************
* Proje : Pointer - Girilen diziyi tersten yaz
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int strlen(char *str)
{
	char *p=str;
	int len=0;
	while(*p++) len++;
	return len;
}

char str[255];
char *p;

int main(int argc, char* argv[])
{
	printf("Bir cumle yaziniz: ");
	fgets(str,sizeof(str),stdin);
	//scanf("%s", str);
	printf("\n");
	
	p=str;
	while(*p++);
	p-=3;
	//p=str+strlen(str);
	printf("uzunluk: %d\n", strlen(str));
	while(p>=str) printf("%c",*p--);
	printf("\n");

	return 0;
}

