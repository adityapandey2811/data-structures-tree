//Optimized approach to check BST but its wrong since it only checks current node(This will give wrong output : 6 2 8 1 9 -1 -1 -1 -1 -1 -1)!
#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int checkBST(bt *root){
    int i = 0;
    if(root == NULL)
        return 1;
    checkBST(root->left);
    checkBST(root->right);
    if(root->left == NULL || root->left->data < root->data)
        i++;
    if(root->right == NULL || root->right->data > root->data)
        i++;
    if(i == 2)
        return 1;
    return 0;
}
int main(){
    bt *root = constructbt();
    int i = checkBST(root);
    if(i == 1)
        printf("BST\n");
    else
        printf("Not BST\n");
    return 0;
}
// 25 20 36 10 22 30 40 5 12 -1 -1 28 -1 38 48 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
