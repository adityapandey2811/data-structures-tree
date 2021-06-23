#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void mirror(bt *root){
    bt *head = NULL;
    if(root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    if(root->left || root->right){
        head = root->left;
        root->left = root->right;
        root->right = head;
    }
}
int checkMirror(bt *root1, bt *root2){
    if(root1 == NULL && root2 == NULL)
        return 1;
    if(root1 == NULL || root2 == NULL)
        return 0;
    if(root1->data != root2->data)
        return 0;
    return checkMirror(root1->left,root2->right) && checkMirror(root1->right,root2->left);
    
}
int main(){
    bt *root1 = constructbt(), *root2 = constructbt();
    mirror(root2);
    checkMirror(root1,root2);
    return 0;
}