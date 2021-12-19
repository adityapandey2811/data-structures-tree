#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void display(bt *root){
	bt *traverser = root;
	while(traverser->right!=NULL){
		printf("%d ",traverser->data);
		traverser = traverser->right;
	}
	printf("%d\n",traverser->data);
	while(traverser->left!=NULL){
		printf("%d ",traverser->data);
		traverser = traverser->left;
	}
	printf("%d\n",traverser->data);
}
void bt2dll(bt **head, bt *root){
	if(root == NULL)
		return;
	bt2dll(head,root->left);
	bt *spare = *head;
	spare->right = root;
	root->left = spare;
	(*head) = root;
	bt2dll(head,root->right);
}
int main(){
	bt *root = NULL, *head = NULL, *start = NULL;
	root = constructbt();
	head = (bt*)malloc(sizeof(bt));
	head->left = head->right = NULL;
	head->data = 0;
	start = head;
	bt2dll(&head,root);
	head = start;
	start = start->right;
	free(head);
	start->left = NULL;
	display(start);
  return 0;
}
