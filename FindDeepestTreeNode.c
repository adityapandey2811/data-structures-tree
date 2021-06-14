#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
bt* deepestTreeNode(bt *root){
    queueTreeNode *head = NULL;
    bt *temp = NULL;
    if(root == NULL)
        return 0;
    head = enqueueTreeNode(head,root);
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head);
        temp = parent;
        if(parent->left)
            head = enqueueTreeNode(head,parent->left);
        if(parent->right)
            head = enqueueTreeNode(head,parent->right);
    }
    return temp;
}
int main(){
    bt *root = constructbt(), *deepest;
    deepest = deepestTreeNode(root);
    printf("Deepest Node: %d\n",deepest->data);
    return 0;
}