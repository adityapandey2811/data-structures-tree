#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void floorAndCeil(bt *root, int key, int *floor, int *ceil){
	if(root == NULL)
		return;
	floorAndCeil(root->left,key,floor,ceil);
	if(root->data == key){
		*ceil = *floor = root->data;
		return;
	}
	if(root->data < key && root->data > *floor)
		*floor = root->data;
	if(root->data > key && root->data < *ceil)
		*ceil = root->data;
	floorAndCeil(root->right,key,floor,ceil);
}
int main(){
	int i = -1, j = INT_MAX,k = 15;
	bt *root = constructbt();
	floorAndCeil(root,k,&i,&j);
	if(j == INT_MAX)
		j = -1;
	printf("Floor->%d Ceil->%d\n",i,j);
	return 0;
}
