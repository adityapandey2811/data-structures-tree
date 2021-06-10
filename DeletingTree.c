#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void deleteTree(bt **root){
    queueTreeNode *head = NULL;
    if((*root) == NULL){
        printf("Already Empty!!!\n");
        return;
    }
    head = enqueueTreeNode(head,(*root));
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->left != NULL)
            head = enqueueTreeNode(head,parent->left);
        if(parent->right != NULL)
            head = enqueueTreeNode(head,parent->right);
        free(parent);
    }
    (*root) = NULL;
}
int main(){
    bt *root = constructbt();
    displayL(root);
    deleteTree(&root);
    displayL(root);
    return 0;
}