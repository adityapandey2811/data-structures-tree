#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
bt *insertInTree(bt *root, int n){
    queueTreeNode *head = NULL;
    bt *temp = NULL;
    temp = (bt*)malloc(sizeof(bt));
    temp->data = n;
    temp->left = temp->right = NULL;
    if(root == NULL){
        root = temp;
        return root;
    }
    head = enqueueTreeNode(head,root);
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->left == NULL){
            parent->left = temp;
            return root;
        }
        else{
            head = enqueueTreeNode(head,parent->left);
        }
        if(parent->right == NULL){
            parent->right = temp;
            return root;
        }
        else{
            head = enqueueTreeNode(head,parent->right);
        }
    }
}
int main(){
    bt *root = constructbt();
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    root = insertInTree(root,7);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
}