// My Char Queue Memory

#include <memory.h>
#include "mycharqueue.h"

char *pqueue=NULL;
int size=0;

void add(char c)
{
	char *p=(char*)malloc(size+1);
	if(p==NULL) return;
	*p=c;
	memmove(p+1,pqueue,size++);
	free(pqueue);
	pqueue=p;
}

char get()
{
	if(size==0) return '\0';
	char c=pqueue[--size];
	char *p=(char*)realloc(pqueue,size);
	if(p==NULL) return c;
	pqueue=p;
	return c;
}

int getsize()
{
	return size;
}

int empty()
{
	return size==0;
}
