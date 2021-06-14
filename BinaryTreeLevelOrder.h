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
int depth(bt *root){
    int l,r;
    if(root == NULL)
        return 0;
    else{
        l = depth(root->left);
        r = depth(root->right);
    }
    if(l>r)
        return l+1;
    else
        return r+1;
}
int searchInTree(bt *root, int n){
    int i;
    if(root == NULL)
        return 0;
    else if(root->data == n)
        return 1;
    i = searchInTree(root->left,n);
    if(i!=1)
        i = searchInTree(root->right,n);
    if(i==1)
        return 1;
    return 0;
}
bt* getTreeNode(bt *root, int n){
    queueTreeNode *head = NULL;
    if(root == NULL)
        return 0;
    head = enqueueTreeNode(head,root);
    while(head != NULL){
        bt *parent = dequeTreeNode(&head);
        if(parent->data == n)
            return parent;
        else{
            if(parent->left != NULL)
                head = enqueueTreeNode(head,parent->left);
            if(parent->right != NULL)
                head = enqueueTreeNode(head,parent->right);
        }
    }
    return NULL;
}
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
int findTreeSize(bt *root){
    if(root == NULL)
        return 0;
    else return(findTreeSize(root->left)+findTreeSize(root->right)+1);
}
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
void deleteTreeR(bt **root){
    if((*root) == NULL)
        return;
    deleteTreeR(&(*root)->left);
    deleteTreeR(&(*root)->right);
    free((*root));
    (*root) = NULL;
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