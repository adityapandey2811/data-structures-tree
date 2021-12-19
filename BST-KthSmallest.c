#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void kthSmallest(bt *root, int *k){
	if(root == NULL)
		return;
	kthSmallest(root->left,k);
	*k = *k-1;
	if(*k == 0){
		printf("%d\n",root->data);
		return;
	}
	kthSmallest(root->right,k);
}
int main(){
	int k = 5;
	bt *root = constructbt();
	kthSmallest(root,&k);
	return 0;
}
