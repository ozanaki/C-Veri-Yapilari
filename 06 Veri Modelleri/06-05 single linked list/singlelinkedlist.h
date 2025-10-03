/*************************************************************************
* Proje : single linked list
* Dosya : singlelinkedlist.h
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#define OK 0
#define ERROR -1

typedef struct node {
	int data;
	struct node* next; 
} node_t;

node_t* add(node_t *node, int data);
int count(node_t *node);
void insert(node_t *node, int data);
void removenext(node_t *node);
void list(node_t *node);
node_t* empty(node_t *node);

