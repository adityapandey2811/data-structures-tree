#include<stdio.h>
#include<stdlib.h>
#include"bt.h"
int findMax(bt *root){
    static int n = -1;
    if(root == NULL)
        return n;
    if(root->data>n)
        n = root->data;
    n = findMax(root->leftchild);
    n = findMax(root->rightchild);
}
int findMin(bt *root){
    static int k,n = 0;
    if(n==0){
        n=1;
        k = root->data;
    }
    if(root == NULL)
        return k;
    if(root->data<k)
        k = root->data;
    k = findMin(root->leftchild);
    k = findMin(root->rightchild);
}
int main(){
    bt *root = constructbt();
    int n = findMax(root);
    int k = findMin(root);
    printf("Max: %d Min:%d\n",n,k);
    return 0;
}