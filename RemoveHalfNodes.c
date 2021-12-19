#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
bt *trimHalfNode(bt *root){
    bt *temp = NULL;
    if(root == NULL)
        return NULL;
    root->left = trimHalfNode(root->left);
    root->right = trimHalfNode(root->right);
    if(!root->left && !root->right)
        return root;
    if(!root->left){
        temp = root->right;
        free(root);
        return temp;
    }
    if(!root->right){
        temp =  root->left;
        free(root);
        return temp;
    }
    if(root->left && root->right)
        return root;
}
int main(){
    bt *root = constructbt();
    root = trimHalfNode(root);
    inorder(root);
    return 0;
}
//1 2 3 4 -1 -1 5 7 8 9 -1 -1 -1 -1 -1 -1 -1 
//1 2 3 4 5 7 -1 -1 -1 -1 -1 -1 -1
