/*************************************************************************
* Proje : dizi queue
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

int queue[QUEUE_SIZE] = {0};
int head=0,tail=0;

void add(int i)
{
	queue[tail++]=i;
	if(tail>=QUEUE_SIZE) tail=0;
}

int get()
{
	if(empty()) return '\0';
	if(head>=QUEUE_SIZE) head=0;
	return queue[head++];
}

int empty()
{
	return head==tail;
}

int main(int argc, char *argv[])
{
  	int i;
	printf("Sonlandirmak icin negatif sayi giriniz.\n");
	for(;;)
	{
		printf("Sayi giriniz: ");
		scanf("%d",&i);
		if(i<=0) break;
		add(i);	
	}
	
	printf("\nGirilen sayilar:\n");
	
	while(!empty()) printf("%d\n", get());
	
	printf("\n"); 

  return 0;
}
