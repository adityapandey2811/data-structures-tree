#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int checkIfAVL(bt *root){
	int l,r;
	if(root == NULL)
		return 0;
	l = checkIfAVL(root->left);
	r = checkIfAVL(root->right);
	if(l<0 || r<0)
		return -1;
	if(abs(l-r)<=1){
		if(l>=r)
			return l+1;
		else
			return r+1;
	}
	else
		return -1;
}
int main(){
	bt *root = constructbt();
	int isAVL = checkIfAVL(root);
	if(isAVL > 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
} 
