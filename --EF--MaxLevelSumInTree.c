#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int maxSumLevel(bt *root){
    queueTreeNode *head = NULL;
    int currentSum = 0, maxSum = 0, level = 0, maxLevelSum = 0;
    if(root == NULL)
        return -1;
    head = enqueueTreeNode(head,root);
    head = enqueueTreeNode(head,NULL);
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent == NULL){
            if(maxSum < currentSum){
                maxSum = currentSum;
                maxLevelSum = level;
            }
            currentSum = 0;
            if(head!=NULL)
                head = enqueueTreeNode(head,NULL);
            level++;
        }
        else{
            currentSum += parent->data;
            if(parent->left)
                head = enqueueTreeNode(head,parent->left);
            if(parent->right)
                head = enqueueTreeNode(head,parent->right);
        }
    }
    return maxLevelSum;
}
int main(){
    bt *root = constructbt();
    int res = maxSumLevel(root);
    printf("%d\n",res);
    return 0;
}