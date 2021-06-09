#ifndef bt_h
#define bt_h

#include<stdio.h>
#include<stdlib.h>
typedef struct binarytree{
    int data;
    struct binarytree *leftchild, *rightchild;
}bt;
void inorder(bt *root){
    if(root == NULL)
        return;
    inorder(root->leftchild);
    printf("%d ",root->data);
    inorder(root->rightchild);
}
void preorder(bt *root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->leftchild);
    preorder(root->rightchild);
}
void postorder(bt *root){
    if(root == NULL)
        return;
    postorder(root->leftchild);
    postorder(root->rightchild);
    printf("%d ",root->data);
}
bt* constructbt(){
    bt *temp = NULL;
    int n;
    scanf("%d",&n);
    if(n==-1){
        return NULL;
    }
    else{
        temp = (bt*)malloc(sizeof(bt));
        temp->data = n;
        printf("Enter leftchild of %d: ",n);
        temp->leftchild = constructbt();

        printf("Enter rightchild of %d: ",n);
        temp->rightchild = constructbt();
    }
    return temp;
}


#endif
