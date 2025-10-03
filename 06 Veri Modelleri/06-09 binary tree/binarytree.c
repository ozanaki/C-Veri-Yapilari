/*************************************************************************
* Proje : binary tree
* Dosya : binarytree.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include "binarytree.h"

node_t* add(node_t *node, int data)
{
	node_t *tmp;
	if(node==NULL)
	{
		 	node = (node_t*)malloc(sizeof(node_t)*1);
		 	if(node==NULL) return NULL;
		 	node->left=NULL;
		 	node->right=NULL;
		 	node->data=data;
		 	return node;
	}
	else
	{
		if(data < node->data)
		{
			if(node->left==NULL)
				node->left=add(node->left,data);
			else
				add(node->left,data);
		}
		else
		{
			if(node->right==NULL)
				node->right=add(node->right,data);
			else
				add(node->right,data);
		}	
	}	

	return node;
}

void list(node_t *root, int level, int dir)
{
	int i,sp;
	node_t *tmp;
	if(root==NULL) return;
	sp=10+dir*level;
	for(i=0; i<sp; i++) printf("    ");
	printf("%4d:%d\n",root->data,childcount(root));
	list(root->left,level+1,-1);
	list(root->right,level+1,1);
}

int childcount(node_t *node)
{
	int count=0;
	if(node==NULL) return 0;
	if(node->left!=NULL) count++;
	count+=childcount(node->left);
	if(node->right!=NULL) count++;
	count+=childcount(node->right);
	return count;
}
