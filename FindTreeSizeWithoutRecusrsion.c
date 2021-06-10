#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int findTreeSize(bt *root){
    queueTreeNode *head = NULL;
    int n=0;
    if(root == NULL)
        return 0;
    head = enqueueTreeNode(head,root);
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head);
        n++;
        if(parent->left != NULL)
            head = enqueueTreeNode(head,parent->left);
        if(parent->right != NULL)
            head = enqueueTreeNode(head,parent->right);
    }
    return n;
}
int main(){
    bt *root = constructbt();
    int n = findTreeSize(root);
    printf("%d\n",n);
    return 0;
}