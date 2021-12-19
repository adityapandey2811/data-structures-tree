#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
bt *createTreeNode(int h){
	bt *temp = NULL;
	temp = (bt*)malloc(sizeof(bt));
	temp->data = h;
	temp->left = temp->right = NULL;
	return temp;
}
bt *generateMinimunNodeAVLTree(int h){
	if(h == 0)
		return NULL;
	bt *temp = createTreeNode(h);
	if(h-1>=0)
		temp->left = generateMinimunNodeAVLTree(h-1);
	if(h-2>=0)
		temp->right = generateMinimunNodeAVLTree(h-2);
	return temp;
}
int main(){
	bt *root = generateMinimunNodeAVLTree(6); //takes height as argument
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0;
}
