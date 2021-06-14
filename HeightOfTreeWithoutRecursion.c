#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int depth(bt *root){
    int height = 0;
    queueTreeNode *head = NULL;
    if(root == NULL)
        return 0;
    head = enqueueTreeNode(head,root);
    while(1){
        int nodeCount = queueSize(head);
        if(nodeCount == 0)
            return height;
        else
            height++;
        while(nodeCount>0){
            bt *parent = dequeTreeNode(&head);
            if(parent->left)
                head = enqueueTreeNode(head,parent->left);
            if(parent->right)
                head = enqueueTreeNode(head,parent->right);
            nodeCount--;
        }
    }
}
int main(){
    bt *root = constructbt();
    int n = depth(root);
    printf("Depth: %d\n",n);
    return 0;
}