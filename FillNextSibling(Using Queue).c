#include<stdio.h>
#include<stdlib.h>
typedef struct binary{
    int data;
    struct binary *left,*right,*nextSibling;
}bt;
typedef struct qm{
    bt *treenode;
    struct qm *next;
}queueMaker;
typedef struct qtn{
    queueMaker *front,*rear;
}queueTreeNode;
int queueSize(queueTreeNode *q){
    queueMaker *temp;
    int i = 0;
    if(q == NULL)
        return 0;
    for(temp = q->front;temp != NULL; temp = temp->next, i++);
    return i;
}
queueTreeNode* enqueueTreeNode(queueTreeNode *head, bt *n){
    queueMaker *temp = NULL;
    temp = (queueMaker*)malloc(sizeof(queueMaker));
    temp->treenode = n;
    temp->next = NULL;
    if(head == NULL){
        head = (queueTreeNode*)malloc(sizeof(queueTreeNode));;
        head->front = head->rear = temp;
    }
    else{
        head->rear->next = temp;
        head->rear = temp;
    }
    return head;
}
bt* dequeTreeNode(queueTreeNode **head){
    bt *newnode = NULL;
    if((*head)!=NULL){
        newnode = (*head)->front->treenode;
        (*head)->front = (*head)->front->next;
    }
    if((*head)->front == NULL)
        (*head) = NULL;
    return newnode;
}
bt* constructbt(){
    bt *temp = NULL;
    queueTreeNode *head = NULL;
    temp = (bt*)malloc(sizeof(bt));
    printf("Enter root data: ");
    scanf("%d",&temp->data);
    temp->left = temp->right = NULL;
    head = enqueueTreeNode(head,temp);
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head),*leftc = NULL, *rightc = NULL;
        int n;
        parent->nextSibling = NULL;
        printf("Enter left of %d: ",parent->data);
        scanf("%d",&n);
        if(n!=-1){
            leftc = (bt*)malloc(sizeof(bt));
            leftc->data = n;
            leftc->left = leftc->right = NULL;
            parent->left = leftc;
            head = enqueueTreeNode(head,leftc);
        }
        printf("Enter right of %d: ",parent->data);
        scanf("%d",&n);
        if(n!=-1){
            rightc = (bt*)malloc(sizeof(bt));
            rightc->data = n;
            rightc->left = rightc->right = NULL;
            parent->right = rightc;
            head = enqueueTreeNode(head,rightc);
        }
    }
    return temp;
}
void displayL(bt *root){
    queueTreeNode *head = NULL;
    int n;
    if(root == NULL){
        printf("Empty!!!");
        return;
    }
    head = enqueueTreeNode(head,root);
    while(head != NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->left != NULL)
            head = enqueueTreeNode(head, parent->left);
        if(parent->right != NULL)
            head = enqueueTreeNode(head, parent->right);
        printf("%d ",parent->data);
    }
}
void displayLNS(bt *root){
    queueTreeNode *head = NULL;
    int n;
    if(root == NULL){
        printf("Empty!!!");
        return;
    }
    head = enqueueTreeNode(head,root);
    while(head != NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->left != NULL)
            head = enqueueTreeNode(head, parent->left);
        if(parent->right != NULL)
            head = enqueueTreeNode(head, parent->right);
        printf("%d ",parent->nextSibling->data);
    }
}
bt *createNextSibling(bt *root){
    queueTreeNode *head = NULL;
    bt *temp = root;
    if(root == NULL)
        return NULL;
    head = enqueueTreeNode(head,root);
    root->nextSibling = root;
    while(head!=NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->left != NULL){
            head = enqueueTreeNode(head, parent->left);
            parent->left->nextSibling = parent->right;
        }
        if(parent->right != NULL){
            head = enqueueTreeNode(head, parent->right);
            parent->right->nextSibling = parent->left;
        }
    }
    return temp;
}
int main(){
    bt *root = constructbt();
    root = createNextSibling(root);
    displayL(root);
    printf("\n");
    displayLNS(root);
    return 0;
}