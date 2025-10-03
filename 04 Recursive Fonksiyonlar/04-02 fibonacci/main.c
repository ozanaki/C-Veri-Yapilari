/*************************************************************************
* Proje : Recursive (Özyinelemeli) Fonksiyonlar
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell DevC++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
	return n<=1?n:fibonacci(n-1)+fibonacci(n-2);
}

int main(int argc, char *argv[])
{
 	int sayi,i;
	int fibo;
	printf("Kac adet Fibonacci elemani listelensin : ");
	scanf("%d", &sayi);
	
	for(i=0; i<sayi; i++)
	{
		fibo=fibonacci(i);
		printf("%d ", fibo);
	}
	
  return 0;
}
