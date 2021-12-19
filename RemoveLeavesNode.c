#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int trimLeaves(bt **root){
    bt *temp = *root;
    int r,l;
    if(temp == NULL)
        return 0;
    l = trimLeaves(&(temp->left));
    r = trimLeaves(&(temp->right));
    if(!temp->left && !temp->right)
        return INT_MAX;
    if(l == INT_MAX){
        free(temp->left);
        temp->left = NULL;
    }
    if(r == INT_MAX){
        free(temp->right);
        temp->right = NULL;
    }
    return 0;
}
int main(){
    bt *root = constructbt();
    trimLeaves(&root);
    inorder(root);
    return 0;
}
