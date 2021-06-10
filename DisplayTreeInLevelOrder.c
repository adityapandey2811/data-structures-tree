#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void displayL(bt *root){
    queueTreeNode *head = NULL;
    stack *top = NULL;
    int n;
    if(root == NULL){
        printf("Empty!!");
        return;
    }
    head = enqueueTreeNode(head,root);
    while(head != NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->left != NULL)
            head = enqueueTreeNode(head, parent->left);
        if(parent->right != NULL)
            head = enqueueTreeNode(head, parent->right);
        printf("%d ",parent->data);
    }
}
int main(){
    bt *root = constructbt();
    displayL(root);
}