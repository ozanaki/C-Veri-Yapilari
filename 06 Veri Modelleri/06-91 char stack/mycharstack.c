// My Char Stack Memory

#include <memory.h>
#include "mycharstack.h"

char *pstack=NULL;
int size=0;

void push(char c)
{
	char *p=(char*)realloc(pstack,size+1);
	if(p==NULL) return;
	pstack=p;
	pstack[size++]=c;
}

char pop()
{
	if(size==0) return '\0';
	char c=pstack[--size];
	char *p=(char*)realloc(pstack,size);
	if(p==NULL) return c;
	pstack=p;
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
