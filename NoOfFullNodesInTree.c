#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int noOfLeaves(bt *root){
    queueTreeNode *head = NULL;
    int n = 0;
    if(root == NULL)
        return 0;
    head = enqueueTreeNode(head,root);
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->left)
            head = enqueueTreeNode(head,parent->left);
        if(parent->right)
            head = enqueueTreeNode(head,parent->right);
        if(parent->left && parent->right)
            n++;
    }
    return n;
}
int main(){
    bt *root = constructbt();
    int n = noOfLeaves(root);
    printf("%d\n",n);
    return 0;
}