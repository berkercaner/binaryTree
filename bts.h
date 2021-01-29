#ifndef __BTS_H_
#define __BTS_H_
enum switches{
	create =1,
	fromFile,
	add,
	display,
	draw,
	find,
	deleteTree,
	delNode,
	saveTree,
	parent
};

struct node;

struct node* addNode(struct node* , int );

void traverse(struct node* );

void drawTree(struct node* , int );

struct node* createTree(struct node* , int *, int );

struct node* searchTree(struct node* , int );

void findNode(struct node* , int );

struct node* deleteNode(struct node*, int);

void deleteTheTree(struct node* );

void findParent(struct node*, int, int);
#endif


