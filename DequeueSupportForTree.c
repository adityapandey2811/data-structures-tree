#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
typedef struct dequeue_support{
    bt *data;
    struct dequeue_support *next, *prev;
}dqe;
typedef struct dequeue_main{
    dqe *front, *rear;
}dq;
void displayde(dq *head){
    dqe *temp = NULL;
    if(head == NULL){
        printf("Dequeue Empty\n");
        return;
    }
    for(temp = head->front; temp!=NULL; temp = temp->next){
        printf("%d ",temp->data->data);
    }
    printf("\n");
}
dq* createFirst(dq *head, bt *root){
    head = (dq*)malloc(sizeof(dq));
    head->front = head->rear = (dqe*)malloc(sizeof(dqe));
    head->front->data = head->rear->data = root;
    head->front->next = head->front->prev = head->rear->prev = head->rear->next = NULL;
    return head;
}
dq* enque_front(dq *head,bt *root){
    dqe *temp = NULL;
    if(head == NULL){
        head = createFirst(head,root);
    }
    else{
        temp = (dqe*)malloc(sizeof(dqe));
        temp->data = root;
        temp->next = head->front;
        temp->prev = NULL;
        head->front->prev = temp;
        head->front = temp;
    }
    return head;
}
dq* enque_rear(dq *head,bt *root){
    dqe *temp = NULL;
    if(head == NULL){
        head = createFirst(head,root);
    }
    else{
        temp = (dqe*)malloc(sizeof(dqe));
        temp->data = root;
        temp->prev = head->rear;
        temp->next = NULL;
        head->rear->next = temp;
        head->rear = temp;
    }
}
bt *deque_front(dq **head){
    dqe *temp = NULL;
    if((*head) == NULL){
        printf("Dequeue Empty\n");
        return NULL;
    }
    else{
        temp = (*head)->front;
        (*head)->front = (*head)->front->next;
        if((*head)->front == NULL)
            (*head) = NULL;
        else
            (*head)->front->prev = NULL;
        return temp->data;
    }
}
bt *deque_rear(dq **head){
    dqe *temp = NULL;
    if((*head) == NULL){
        printf("Dequeue Empty\n");
        return NULL;
    }
    else{
        temp = (*head)->rear;
        (*head)->rear = (*head)->rear->prev;
        if((*head)->rear == NULL)
            (*head) = NULL;
        else
            (*head)->rear->next = NULL;
        return temp->data;
    }
}
int main(){
    int i;
    bt *root = NULL;
    dq *head = NULL;
    printf("1.ef 2.er 3.df 4.dr 5.pr\n");
    while(i!=-1){
        printf("Enter: ");
        scanf("%d",&i);
        if(i==1){
            root = (bt*)malloc(sizeof(bt));
            root->data = 1;
            root->left = root->right = NULL;
            head = enque_front(head,root);
        }
        else if(i==2){
            root = (bt*)malloc(sizeof(bt));
            root->data = 2;
            root->left = root->right = NULL;
            head = enque_rear(head,root);
        }
        else if(i==3){
            root = deque_front(&head);
            if(root!=NULL)
                printf("Front deque: %d\n",root->data);
            else
                printf("Nothing\n");
        }
        else if(i==4){
            root = deque_rear(&head);
            if(root!=NULL)
                printf("Rear deque: %d\n",root->data);
            else
                printf("Nothing\n");
        }
        else if(i==5){
            displayde(head);
        }
    }
    return 0;
}