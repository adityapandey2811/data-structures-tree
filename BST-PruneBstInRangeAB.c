#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
bt* pruneBST(bt *root, int i, int j){
    bt *temp = NULL;
    if(root == NULL)
        return NULL;
    root->left = pruneBST(root->left,i,j);
    root->right = pruneBST(root->right,i,j);
    if(root->data >= i && root->data <= j){
        return root;
    }
    else{
        if(root->left){
            temp = root->left;
            free(root);
            return temp;
        }
        if(root->right){
            temp = root->right;
            free(root);
            return temp;
        }
        free(root);
        return NULL;
    }
}
int main(){
    int i = 6, j = 12;
    bt *root = constructbt();
    root = pruneBST(root,i,j);
    inorder(root);
    return 0;
}