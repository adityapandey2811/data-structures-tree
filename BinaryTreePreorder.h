#ifndef bt_h
#define bt_h

#include<stdio.h>
#include<stdlib.h>
typedef struct binarytree{
    int data;
    struct binarytree *leftchild, *rightchild;
}bt;
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
void deleteTreeR(bt **root){
    if((*root) == NULL)
        return;
    deleteTreeR(&(*root)->leftchild);
    deleteTreeR(&(*root)->rightchild);
    free((*root));
    (*root) = NULL;
}
int findTreeSize(bt *root){
    if(root == NULL)
        return 0;
    else return(findTreeSize(root->leftchild)+findTreeSize(root->rightchild)+1);
}
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
