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
int main(){
    bt *root = constructbt();
    printf("Preorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nInorder: ");
    inorder(root);
    mirror(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nInorder: ");
    inorder(root);
    return 0;
}