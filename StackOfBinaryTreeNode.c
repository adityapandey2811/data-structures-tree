#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
typedef struct s{
    bt *data;
    struct s *next;
}stack;
void push(stack **top, bt *root){
    stack *spare = *top, *node = NULL;
    if(root == NULL)
        return;
    node = (stack*)malloc(sizeof(stack));
    node->data = root;
    node->next = NULL;
    if((*top) == NULL){
        spare = node;
    }
    else{
        node->next = spare;
        spare = node;
    }
    (*top) = spare;
}
bt *pop(stack **top){
    stack *node = NULL;
    bt *treeNode = NULL;
    if((*top) == NULL)
        return NULL;
    node = (*top);
    (*top) = (*top)->next;
    treeNode = node->data;
    free(node);
    return treeNode;
}
void pushNpop(bt *root){
    queueTreeNode *head = NULL;
    stack *top = NULL;
    bt *temp = NULL;
    if(root == NULL)
        return;
    head = enqueueTreeNode(head,root);
    while(head != NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->left != NULL)
            head = enqueueTreeNode(head,parent->left);
        if(parent->right != NULL)
            head = enqueueTreeNode(head,parent->right);
        push(&top,parent);
    }
    while(top!=NULL){
        temp = pop(&top);
        printf("%d ",temp->data);
    }
}
int main(){
    bt *root = constructbt();
    pushNpop(root);
}