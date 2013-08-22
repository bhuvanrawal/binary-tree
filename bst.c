#include <stdio.h>
#include <stdlib.h>
struct bst{
	int data;
	struct bst * left;
	struct bst * right;
};
typedef struct bst node;
void insert(node **t, int data);
int search(node *head, int data);
void inorder(node *head);
int main(){
	node *head = NULL;
	int choice,data,r;
	printf("Please insert your option: ");
	while(1){
		printf("Enter 1 to insert, 2 to search a node, 3 to do inorder 4 to quit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the data to be inserted\n");
				scanf("%d",&data);
				insert(&head,data);
				printf("Head after insertion is %p\n",(int *)head);
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
	return 0;
}
void insert(node **t, int data){
	node *head = *t;
	if(head==NULL){
		printf("Here1\n");
		(*t) = (node *)malloc(sizeof(node));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->data = data;
		printf("Data %d new head location = %p\n",data,(int *)*t);
	}
	else if(head->data == data)
		printf("This item is already present \n");
	else if(head->data > data){//Insert in the Left Subtree
		if(head->left == NULL){
			printf("Head->data>data\n");
			head->left = (node *)malloc(sizeof(node *));
			head->left->right = head->left->left = NULL;
			head->left->data = data;
			t = &head;
		}	
		else
			insert(&(head->left),data);
	
	}
	else {
		if(head->right == NULL){
			printf("Head->left<data\n");
			head->right = (node *)malloc(sizeof(node *));
			head->right->left = head->right->right = NULL;
			head->right->data = data;
			t = &head;
		}
		else
			insert(&(head->right),data);
	
	}
}
int search(node *head, int data){
	if(head==NULL){
		printf("Key not found \n");
		return 0;
	}
	else if(data == head->data)
		return 1;
	else if(data>head->data){
		return search(head->right,data);
	}
	else
		return search(head->left,data);
}
void inorder(node *head){
	if(head==NULL){
		return;
	}
	else{
		inorder(head->left);
		printf("%d",head->data);
		inorder(head->right);
	}
}
