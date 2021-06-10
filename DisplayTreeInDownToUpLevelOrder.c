#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
#include"ss.h"
void displayR(bt *root){
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
        if(parent->right != NULL)
            head = enqueueTreeNode(head, parent->right);
        if(parent->left != NULL)
            head = enqueueTreeNode(head, parent->left);
        pushI(&top,parent->data);
    }
    while(!isEmptys(top)){
        n = popI(&top);
        printf("%d ",n);
    }
}
int main(){
    bt *root = constructbt();
    displayR(root);
}