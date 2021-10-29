#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void getInorderTraversalRoute(bt *root, int *arr, int *index){
    if(root == NULL)
        return;
    getInorderTraversalRoute(root->left, arr, index);
    if(root != NULL){
        *(arr+*index) = root->data;
        *index = *index + 1;
    }
    getInorderTraversalRoute(root->right, arr, index);
}
void checkBST(bt *root){
    int a[100], index = 0, i;
    int *arr = a;
    getInorderTraversalRoute(root, arr, &index);
    for(i = 1; i < index; i++){
        if(a[i]>a[i-1])
            continue;
        else
            break;
    }
    if(i == index)
        printf("BST\n");
    else
        printf("Not BST\n");
}
int main(){
    bt *root = constructbt();
    checkBST(root);
    return 0;
}
// 25 20 36 10 22 30 40 5 12 -1 -1 28 -1 38 48 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
