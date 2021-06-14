#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void deleteTreeNode(bt **root, int n){
    bt *deepestNode = deepestTreeNode((*root)), *temp = NULL,*spare = NULL;
    int k = searchInTree((*root),n);
    if(k==0){
        printf("Node Not Found!!!\n");
        return;
    }
    else{
        printf("\nDeepest: %d\n",deepestNode->data);
        temp = getTreeNodeParent((*root),n);
        spare = getTreeNodeParent((*root),deepestNode->data);
        if(temp->left->data == n)
            temp->left->data = deepestNode->data;
        else if(temp->right->data == n)
           temp->right->data = deepestNode->data;
        if(spare->left->data == deepestNode->data)
            spare->left = NULL;
        else if(spare->right->data == deepestNode->data)
           spare->right = NULL;
        free(deepestNode);
        deepestNode = NULL;
    }
    
}
int main(){
    bt *root = constructbt();
    printf("\nInorder: ");
    inorder(root);
    deleteTreeNode(&root,3);
    printf("\nInorder: ");
    inorder(root);
    return 0;
}