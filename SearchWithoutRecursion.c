#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int searchInTree(bt *root, int n){
    queueTreeNode *head = NULL;
    if(root == NULL)
        return 0;
    head = enqueueTreeNode(head,root);
    while(head != NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->data == n)
            return 1;
        else{
            if(parent->left != NULL)
                head = enqueueTreeNode(head,parent->left);
            if(parent->right != NULL)
                head = enqueueTreeNode(head,parent->right);
        }
    }
    return 0;
}
int main(){
    bt *root = constructbt();
    int n = searchInTree(root,7);
    (n==1)?(printf("Found\n")):(printf("Nope\n"));
    return 0;
}