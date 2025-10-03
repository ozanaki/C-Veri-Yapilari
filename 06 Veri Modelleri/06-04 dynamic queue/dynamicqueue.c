/*************************************************************************
* Proje : dinamik queue
* Dosya : dynamicqueue.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <memory.h>
#include "dynamicqueue.h"

int *pqueue=NULL;
int size=0;

void add(int i)
{
	int *p=(int*)malloc(sizeof(int)*(size+1));
	if(p==NULL) return;
	*p=i;
	memmove(p+1,pqueue,sizeof(int)*size++);
	free(pqueue);
	pqueue=p;
}

int get()
{
	if(size==0) return 0;
	int i=pqueue[--size];
	int *p=(int*)realloc(pqueue,sizeof(int)*size);
	if(p==NULL) return i;
	pqueue=p;
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
