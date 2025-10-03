/*************************************************************************
* Proje : dinamik stack
* Dosya : dynamicstack.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <memory.h>
#include "dynamicstack.h"

int *pstack=NULL;
int size=0;

void push(int i)
{
	int *p=(int*)realloc(pstack,sizeof(int)*(size+1));
	if(p==NULL) return;
	pstack=p;
	pstack[size++]=i;
}

int pop()
{
	if(size==0) return 0;
	int i=pstack[--size];
	int *p=(int*)realloc(pstack,sizeof(int)*size);
	if(p==NULL) return i;
	pstack=p;
	return i;
}

int getsize()
{
	return size;
}

int empty()
{
	return size==0;
}
