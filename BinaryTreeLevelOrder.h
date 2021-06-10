#ifndef bt_h
#define bt_h

#include<stdio.h>
#include<stdlib.h>
typedef struct binary{
    int data;
    struct binary *left,*right;
}bt;
typedef struct qm{
    bt *treenode;
    struct qm *next;
}queueMaker;
typedef struct qtn{
    queueMaker *front,*rear;
}queueTreeNode;
int findTreeSize(bt *root){
    if(root == NULL)
        return 0;
    else return(findTreeSize(root->left)+findTreeSize(root->right)+1);
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
void inorder(bt *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(bt *root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(bt *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
bt* constructbt(){
    bt *temp = NULL;
    queueTreeNode *head = NULL;
    temp = (bt*)malloc(sizeof(bt));
    printf("Enter root node data: ");
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

#endif