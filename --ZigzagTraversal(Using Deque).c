#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void zigzag(bt *root){
    dq *head = NULL;
    int ultimate = 0;
    if(root == NULL)
        return;
    head = enque_rear(head,root);
    printf("%d ",root->data);
    while(1){
        int nodeCounter = dequeSize(head);
        ultimate++;
        if(nodeCounter == 0)
            break;
        while(nodeCounter--){
            bt *parent = NULL;
            if(ultimate%2!=0){
                parent = deque_rear(&head);
                if(parent->right){
                    head = enque_front(head,parent->right);
                    printf("%d ",parent->right->data);
                }
                if(parent->left){
                    head = enque_front(head,parent->left);
                    printf("%d ",parent->left->data);
                }
            }
            else{
                parent = deque_front(&head);
                if(parent->left){
                    head = enque_rear(head,parent->left);
                    printf("%d ",parent->left->data);
                }
                if(parent->right){
                    head = enque_rear(head,parent->right);
                    printf("%d ",parent->right->data);
                }
            }
        }
    }
}
int main(){
    bt *root = constructbt();
    zigzag(root);
    return 0;
}