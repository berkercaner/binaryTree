
#include "bts.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


struct node {
	int data;
	struct node* left;
	struct node* right;
	};

struct node* addNode(struct node* tree, int value)
{
	if(tree == NULL)
	{	
		struct node* root = (struct node*)malloc(sizeof(struct node));
		//printf("root\n");
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	
	
	if(tree->data > value)
	{
		tree->left = addNode(tree->left,value);
		return tree;
	}
	tree->right = addNode(tree->right,value);
	return tree;
	
}

void traverse(struct node* tree)
{
	if(tree == NULL)
	{
		return;
	}
	
	traverse(tree->left);
	printf("\t");
	printf("\n%d ", tree->data);
	traverse(tree->right);
	printf("\t");
}

void drawTree(struct node* tree, int spaces)
{	
	int counter;
	if(tree == NULL)
		return;
	
	spaces += 8;
	
	drawTree(tree->right, spaces);
	
	printf("\n");
	
	for(counter = 0; counter < spaces; counter++)
		printf(" ");
	
	printf("%d\n", tree->data);
	
	drawTree(tree->left, spaces);
}

struct node* createTree(struct node* tree, int *array, int number)
{	
	int counter;	
	for(counter = 0; counter < number; counter++)
		tree = addNode(tree, array[counter]);
	
	return tree;			
}


struct node* searchTree(struct node* tree, int value)
{
	if(tree == NULL)
		return tree;
	
	if(tree->data < value)
		return searchTree(tree->right, value);
	else if (tree->data > value)
		return searchTree(tree->left, value);
	else if(tree->data == value)	
		return tree;
	
	return tree;
}

struct node* findMinimum(struct node* tree)
{
	if(tree == NULL)
		return NULL;
	else if(tree->left != NULL)
		return findMinimum(tree->left);
	return tree;
}

struct node* deleteNode(struct node* tree, int value)
{	
	if(tree == NULL)
	{
		printf("Node doesn't exists");
		return NULL;
	}
	
	if(tree->data > value)
		tree->left = deleteNode(tree->left,value);
	else if(tree->data < value)
		tree->right = deleteNode(tree->right,value);
	else
	{
		if(tree->left == NULL && tree->right == NULL)
		{
			free(tree);
			return NULL;
		}
		else if(tree->left == NULL || tree->right == NULL)
		{
			struct node* temp;
			if(tree->left == NULL)
				temp = tree->right;
			else
				temp = tree->left;
			free(tree);
			return temp;
		}
		else
		{
			struct node* temp = findMinimum(tree->right);
			tree->data = temp->data;
			tree->right = deleteNode(tree->right,temp->data); 
		}
	}
	return tree;		
}

//yorum yap
void findNode(struct node* tree, int value)
{	
	struct node* tempT = searchTree(tree,value);
	if(tempT == NULL)	
		printf("\n%d doesn't exist\n",value);
	else	
		printf("\n%d exists \n", tempT->data);	
}

void deleteTheTree(struct node* tree)
{
	if(tree == NULL) 
		return;
		
	deleteTheTree(tree->left);
	deleteTheTree(tree->right);
	
	free(tree);
}








