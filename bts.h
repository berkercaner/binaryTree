#ifndef __BTS_H_
#define __BTS_H_
enum switches{
	create =1,
	add,
	display,
	draw,
	find,
	del
};

struct node;

struct node* addNode(struct node* , int );

void traverse(struct node* );

void drawTree(struct node* , int );

struct node* createTree(struct node* , int *, int );

struct node* searchTree(struct node* , int );

void findNode(struct node* , int );

struct node* deleteNode(struct node*, int);
#endif


