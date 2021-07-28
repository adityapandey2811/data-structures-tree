#include<stdio.h>
#include<stdlib.h>
typedef struct binary{
    int data;
    char val;
    struct binary *left,*right,*preorderSuccessor;
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
bt* findInorderSuccessor(bt *root, bt **prev){
    if(root == NULL)
        return NULL;
    findInorderSuccessor(root->left,prev);
    root->preorderSuccessor = *prev;
    (*prev) = root;
    findInorderSuccessor(root->right,prev);
    return root;
}
void display(bt *root){
    if(root == NULL)
        return;
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
}
void displayInorderSuccessor(bt *root){
    if(root == NULL)
        return;
    displayInorderSuccessor(root->left);
    if(root->preorderSuccessor != NULL)
        printf("%d ",root->preorderSuccessor->data);
    else
        printf("NULL ");
    displayInorderSuccessor(root->right);
}
int main(){
    bt *root = constructbt(),*temp = NULL;
    root = findPreorderSuccessor(root,&temp);
    display(root);
    printf("\n");
    displayPreorderSuccessor(root);
    return 0;
}