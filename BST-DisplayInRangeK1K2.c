#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void displayInRangeK1K2(bt *root, int i, int j){
	if(root == NULL)
		return;
	displayInRangeK1K2(root->left,i,j);
	if(root->data>=i && root->data<=j)
		printf("%d ",root->data);
	displayInRangeK1K2(root->right,i,j);
}
int main(){
	int i = 2, j = 6;
	bt *root = constructbt();
	displayInRangeK1K2(root,i,j);
	return 0;
}
