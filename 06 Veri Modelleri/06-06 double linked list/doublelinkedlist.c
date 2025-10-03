/*************************************************************************
* Proje : double linked list
* Dosya : doublelinkedlist.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include "doublelinkedlist.h"

node_t* add(node_t *node, int data)
{
	node_t *tmp;
 	tmp = (node_t*)malloc(sizeof(node_t)*1);
 	if(tmp==NULL) return NULL;

	tmp->data=data;
	tmp->next=NULL;

	if(node==NULL)
	{
	 	tmp->prev=NULL;
	 	return tmp;
	}
	
	node_t *last=node;
	while(last->next) last=last->next;
	
	tmp->prev=last;
	last->next = tmp;
	
	return node;
}

void insert(node_t *node, int data)
{
	node_t *tmp;
	tmp=node->next;
	node->next = (node_t*)malloc(sizeof(node_t)*1);
	if(node->next!=NULL)
	{
		node->next->prev=node;
		node=node->next;
		node->next=tmp;
		node->data=data;
	}
}

void del(node_t *node)
{
	node_t *tmp;
	if(node==NULL) return;
	tmp=node->prev;
	if(tmp==NULL) return;
	node->prev=tmp;
	tmp->next=node->next;
	free(node);
	node=NULL;
}

int count(node_t *root)
{
	int cnt=0;
	node_t *tmp;
	if(root==NULL) return 0;

	tmp=root;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
		cnt++;
	}
	return cnt;
}

void list(node_t *root)
{
	node_t *tmp;
	if(root==NULL)
	{
		printf("-- Empty List --");
		return;
	}
	tmp=root;
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
