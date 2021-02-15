#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "bts.h"

int main()
{
	struct node* mainTree = NULL;
	int i, nodeNumber, choice, value, count;
	int* array;
	
	while(1)
	{
		printf("\n---- What do you want to do? ----\n");
		printf("1- Create a tree\n");
		printf("2- Create a tree from the file 'tree.txt'\n");
		printf("3- Add a node\n");
		printf("4- Display all nodes in sequence\n");
		printf("5- Draw the tree\n"),
		printf("6- Find a node \n");
		printf("7- Delete the tree \n");
		printf("8- Delete a node \n");
		printf("9- Save the tree \n");
		printf("10- Find parent \n");
		
		printf("\n Make the choice:  ");
		
		scanf("%d", &choice); printf("\n");
		FILE* fp;
		
		switch(choice)
		{
			case create:
				printf("\n Enter node number of your tree: ");
				scanf("%d",&count);
				array = (int*) malloc(sizeof(int)*count);
				for(i=0; i<count; i++){
					printf("Enter Value of Node:  ");	
					scanf("%d",&array[i]);
				}
				nodeNumber = count;
				mainTree = createTree(mainTree, array,count);
				break;
				
			
			case fromFile:
				fp = fopen("tree.txt","r");
				i = 0;
				while(fscanf(fp,"%d",&value) == 1)
					i++;
				fclose(fp);
				array = (int*) malloc(sizeof(int)*i);
				fp = fopen("tree.txt","r");
				for(count = 0; count < i; count++){	
					fscanf(fp,"%d",&array[count]);
				}	
				nodeNumber = count++;
				fclose(fp);
				mainTree = createTree(mainTree,array,i);
				break;
			
			case add:
				if(mainTree == NULL){
				printf("\nYou should create a tree first.\n");
				break;
				}
				printf("\nEnter the value:  ");
				scanf("%d",&value);
				mainTree = addNode(mainTree,value);
				nodeNumber++;
				array = (int*) realloc(array,sizeof(int)*nodeNumber);
				array[nodeNumber-1] = value;
				break;
			
			case display:
				if(mainTree == NULL){
				printf("\nYou should create a tree first.\n");
				break;
				}
				traverse(mainTree);
				break;
				
			case draw:
				if(mainTree == NULL){
				printf("\nYou should create a tree first.\n");
				break;
				}
				drawTree(mainTree,0);
				break;
			
			case find:
				if(mainTree == NULL){
				printf("\nYou should create a tree first.\n");
				break;
				}
				printf("\nEnter the value:  ");
				scanf("%d", &value);
				findNode(mainTree, value);
				break;	
			
			case deleteTree:
				if(mainTree == NULL){
				printf("\nYou should create a tree first.\n");
				break;
				}
				deleteTheTree(mainTree);
				free(array);
				mainTree = NULL;
				nodeNumber = 0;
				break;	
			
			case delNode:
				if(mainTree == NULL){
				printf("\nYou should create a tree first.\n");
				break;
				}
				printf("Enter the value:  ");
				scanf("%d", &value);
				for(i = 0; i<nodeNumber; i++){	
					if(array[i]==value)
						break;
				}
				for(i=i;i<nodeNumber;i++)
					array[i] = array[i+1];
				
				nodeNumber--;
				mainTree = deleteNode(mainTree,value);
				break;		
			
			case saveTree:
				if(mainTree == NULL){
				printf("\nYou should create a tree first.\n");
				break;
				}
				i = 0;
				fp = fopen("savedTree.txt","w");
				while(i < nodeNumber){
					fprintf(fp,"%d ",array[i]);
					i++;
				}
				fclose(fp);
				break;
			
			case parent:
				if(mainTree == NULL){
				printf("\nYou should create a tree first.\n");
				break;
				}
				printf("\n------------------------------------\n");
				traverse(mainTree);
				printf("\n------------------------------------\n");
				printf("Enter a value to find its parent:  ");
				scanf("%d",&value); printf("\n");
				if(searchTree(mainTree,value) == NULL){
					printf("\n %d doesn't exist\n",value);
					break;
				}
				findParent(mainTree,value,-1);printf("\n");
				break;
				
				
		}
		
	}
	
	return 0;
}

