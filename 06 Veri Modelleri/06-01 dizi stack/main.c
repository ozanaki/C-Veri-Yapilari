/*************************************************************************
* Proje : dizi stack
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE] = {0};
int pos=-1;

void push(int data)
{
	if(pos>=STACK_SIZE) return;
	stack[++pos]=data;
}

int pop()
{
	if(pos<0) return '\0';
	return stack[pos--];
}

int empty()
{
	return pos<0;
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
		push(i);	
	}
	
	printf("\nGirilen sayilar: \n");
	
	while(!empty()) printf("%d\n", pop());
	
	printf("\n"); 
	
  return 0;
}
