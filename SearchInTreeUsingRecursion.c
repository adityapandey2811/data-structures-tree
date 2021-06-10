#include<stdio.h>
#include<stdlib.h>
typedef struct binaryTree{
    int data;
    struct bt *left,*right;
}bt;
bt *constructbt(){
    bt* temp = NULL;
    int n;
    scanf("%d",&n);
    if(n==-1)
        return NULL;
    else{
        temp = (bt*)malloc(sizeof(bt));
        temp->data = n;
        printf("Enter left of %d: ",n);
        temp->left = constructbt();
        printf("Enter right of %d: ",n);
        temp->right = constructbt();
    }
    return temp;
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
int main(){
    bt *root;
    int i;
    printf("Enter root node: ");
    root = constructbt();

    i = searchInTree(root,20);
    if(i==1){
        printf("Found\n");
    }
    else if(i==0){
        printf("Nope\n");
    }
    return 0;
}