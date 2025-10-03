/*************************************************************************
* Proje : single linked list
* Dosya : singlelinkedlist.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include "singlelinkedlist.h"

node_t* add(node_t *node, int data)
{
	node_t *tmp;
	tmp = (node_t*)malloc(sizeof(node_t)*1);
	if(tmp==NULL) return ERROR;
	
	tmp->data=data;
	tmp->next=NULL;
	
	if(node==NULL)
	{
		return tmp;
	}
	
	node_t *last=node;
	while(last->next) last=last->next;
	
	last->next=tmp;
	
	return node;
}

void insert(node_t *node, int data)
{
	node_t *tmp;
	tmp = (node_t*)malloc(sizeof(node_t)*1);
	if(tmp==NULL) return ERROR;
	
	tmp->data=data;
	tmp->next=node->next;
	node->next=tmp;
	
	return OK;
}

void removenext(node_t *node)
{
	node_t *tmp;
	if(node==NULL) return;
	tmp=node->next;
	if(tmp==NULL) return;
	node->next=tmp->next;
	free(tmp);
	return;
}

int count(node_t *node)
{
	int cnt=0;
	node_t *tmp;
	if(node==NULL) return 0;

	tmp=node;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
		cnt++;
	}
	return cnt;
}

void list(node_t *node)
{
	node_t *tmp;
	if(node==NULL)
	{
		printf("-- List is Empty --");
		return;
	}
	tmp=node;
	while(tmp!=NULL)
	{
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}

node_t* empty(node_t *node)
{
	if(node->next!=NULL)
	{
		empty(node->next);
		node->next=NULL;
	}
	free(node);
	node=NULL;
	return node;
}

