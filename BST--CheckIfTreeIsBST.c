#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int checkBST(bt *root, int *index){
    if(root == NULL)
        return 1;
    checkBST(root->left, index);
    if(root->data > *index){
        *index = root->data;
    }
    else
        return 0;
    checkBST(root->right, index);
}
int main(){
    int index = INT_MIN;
    bt *root = constructbt();
    int i = checkBST(root,&index);
    if(i == 1)
        printf("BST\n");
    else
        printf("Not BST\n");
    return 0;
}
