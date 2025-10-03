/*************************************************************************
* Proje : binary tree
* Dosya : binarytree.h
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

typedef struct node {
	int data;
	struct node* parent;
	struct node* left;
  struct node* right;
} node_t;

node_t* add(node_t *node, int data);
void del(node_t *node);
int count(node_t *root);
void list(node_t *root, int level, int dir);
node_t* empty(node_t *node);

