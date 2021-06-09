#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int main(){
    bt *temp = NULL,*root = constructbt();
    queueTreeNode *head = NULL;
    int n;
    n = root->data;
    head = enqueueTreeNode(head,root);
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head),*leftc = parent->left,*rightc = parent->right;
        if(parent->left!=NULL){
            if(n<parent->left->data)
                n = parent->left->data;
            head = enqueueTreeNode(head,leftc);
        }
        if(parent->right!=NULL){
            if(n>parent->right->data)
                n = parent->right->data;
            head = enqueueTreeNode(head,rightc);
        }
    }
    printf("%d",n);
}