#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "bts.h"

int main()
{
	struct node* mainTree = NULL;
	int i; int nodeNumber;int* array; int choice;int value;
	
	while(1)
	{
		printf("\n---- What do you want to do? ----\n");
		printf("1- Create a tree\n");
		printf("2- Add a node\n");
		printf("3- Display all nodes in sequence\n");
		printf("4- Draw the tree\n"),
		printf("5- Find a node \n");
		printf("6- Delete a node \n");
		
		printf("\n Make the choice:  ");
		
		scanf("%d", &choice); printf("\n");
		
		switch(choice)
		{
			case create:
				printf("\n Enter node number of your tree: ");
				scanf("%d",&nodeNumber);
				array = (int*) malloc(sizeof(int)*nodeNumber);
				for(i=0; i<nodeNumber; i++)
				{
					printf("Enter Value of Node:  ");	
					scanf("%d",&array[i]);
				}
				mainTree = createTree(mainTree, array,nodeNumber);
				break;
			
			case add:
				printf("\nEnter the value:  ");
				scanf("%d",&value);
				mainTree = addNode(mainTree,value);
				break;
			
			case display:
				traverse(mainTree);
				break;
				
			case draw:
				drawTree(mainTree,0);
				break;
			
			case find:
				printf("\nEnter the value:  ");
				scanf("%d", &value);
				findNode(mainTree, value);
				break;
			
			case del:
				printf("Enter the value:  ");
				scanf("%d", &value);
				mainTree = deleteNode(mainTree,value);
				break;
		}
		
	}
	
	return 0;
}

