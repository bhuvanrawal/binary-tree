/*This is a C program to Create a binary tree, to do traversal of the same and to find a specific node*/
#include <stdio.h>
#include <stdlib.h>
struct binary_tree{
	int data;
	struct binary_tree *lchild;
	struct binary_tree *rchild;
};
typedef struct binary_tree node;
void insert(node **q, int data);
int search(node *q, int data);
void inorder(node *head);
int main(){
	node *head = NULL;
	int choice,data,r;
	printf("Please insert your option: ");
	while(1){
		printf("Enter 1 to insert, 2 to search a node, 3 to do inorder 5 to quit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the data to be inserted\n");
				scanf("%d",&data);
				insert(&head,data);
				break;
			case 2: printf("Enter the data to be searched\n");
				scanf("%d",&data);
				r=search(head, data);
				if(r==1) printf("Found\n");
				else	printf("Not found\n");
				break;
			case 3: inorder(head); 
				printf("\n");
				break;
			default: return 0;
		}
	}
}
void insert(node **q, int data){
	node *temp,*p;
	temp = *q;
	int ran;
	if(temp==NULL){
		printf("here\n");
		temp = (node *)malloc(sizeof(node));
		temp->data = data;
		temp->lchild = NULL;
		temp->rchild = NULL;
		*q=temp;
		return;
	}

	else if(temp->lchild == NULL){
		temp->lchild = (node *) malloc(sizeof(node));
		temp->lchild->lchild = NULL;
		temp->lchild->rchild = NULL;
		temp->lchild->data = data;
		return;
	}
	else if(temp->rchild == NULL){
		temp->rchild = (node *) malloc(sizeof(node));
		temp->rchild->lchild = NULL;
		temp->rchild->rchild = NULL;
		temp->rchild->data = data;
		return;
	}
	else{
		ran = rand()%2;
		if(ran==1){
			insert(&(temp->lchild),data);
		}
		else
			insert(&(temp->rchild),data);
	}

}
int search(node *q, int data){
	if(q==NULL)
		return 0;
	else if(q->data== data){
		return 1;
	}
	else return (search(q->rchild,data)|search(q->lchild,data));

}
void inorder(node *p){
	if(p==NULL)
		return;
	else{	
		inorder(p->lchild);
		printf("%d",p->data);
		inorder(p->rchild);	
	}

}
